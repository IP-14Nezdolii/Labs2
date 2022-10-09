#pragma once
#include <fstream>
#include <string>
#include <vector>

std::vector<__int64> gen_fib_vec(int numb_of_fibs = 90)//повертає вектор перших 90 чисел Фібоначчі
{
    std::vector<__int64> vec_fib;

    vec_fib.push_back(0);
    vec_fib.push_back(1);
    vec_fib.push_back(1);

    for (size_t i = 3; i < numb_of_fibs; i++)
    {
        vec_fib.push_back(vec_fib[i - 2] + vec_fib[i - 1]);
    }

    return vec_fib;
}

__int64 numb_of_series(std::string filename)//повертає кількість серій у файлі
{
    __int64 numb = 0;
    __int64 current;
    __int64 previous;
    FILE* file;

    fopen_s(&file, filename.c_str(), "rb");

    if (file != 0)
    {
        if (fread(&current, sizeof(__int64), 1, file))
        {            
            numb += 1;
            previous = current;

            while (fread(&current, sizeof(__int64), 1, file))
            {
                if (current < previous)
                {
                    numb += 1;
                }
                previous = current;
            }
        }

        fclose(file);
    }

    return numb;
}

__int64 distribution(std::string filename, std::string filename1, std::string filename2)//розподіляє серії по файлам
{
    __int64 real_numb_series = numb_of_series(filename);
    __int64 numb_series;
    __int64 numb_fake_series = 0;
    __int64 numb_series1;
    __int64 numb_series2;

    std::vector<__int64> fib_vec = gen_fib_vec();

    if (real_numb_series != 1)
    {
        for (size_t i = 2; i < fib_vec.size(); i++)
        {
            if (fib_vec[i] >= real_numb_series)
            {
                numb_series = fib_vec[i];
                numb_fake_series = numb_series - real_numb_series;
                numb_series1 = real_numb_series - fib_vec[i - 2];
                numb_series2 = fib_vec[i - 2];
                break;
            }
        }
    }
    else 
    {
        numb_series1 = 1;
        numb_series2 = 0;
    }
   
    FILE* file;
    FILE* file1;
    FILE* file2;

    fopen_s(&file, filename.c_str(), "rb");
    fopen_s(&file1, filename1.c_str(), "wb");
    fopen_s(&file2, filename2.c_str(), "wb");

    __int64 current;
    __int64 previous;
    __int64 numb_s = 1;

    if (file != 0 && file1 != 0 && file2 != 0)
    {
        fread(&previous, sizeof(__int64), 1, file);
        fwrite(&previous, sizeof(__int64), 1, file1);

        while (fread(&current, sizeof(__int64), 1, file))
        {
            if (current < previous)
            {
                numb_s += 1;
            }

            if (numb_s <= numb_series1)
            {
                fwrite(&current, sizeof(__int64), 1, file1);
            }
            else
            {
                break;
            }

            previous = current;
        }

        if (real_numb_series != 1) 
        {
            fwrite(&current, sizeof(__int64), 1, file2);
            while (fread(&current, sizeof(__int64), 1, file))
            {
                fwrite(&current, sizeof(__int64), 1, file2);
            }
        }
      
        fclose(file);
        fclose(file1);
        fclose(file2);
    }

    return numb_fake_series;
}

bool last_elem_was_read(FILE* stream)//перевіряє чи є поточний елемент останнім у файлі
{
    __int64 buff;
    bool end = fread(&buff, sizeof(__int64), 1, stream);
    if (end == 0)
    {
        return true;
    }
    else
    {
        _fseeki64(stream, _ftelli64(stream) - sizeof(__int64), SEEK_SET);
        return false;
    }
}

bool last_elem_in_ser(FILE* stream)//перевіряє чи є поточний елемент останнім у серії
{
    if (last_elem_was_read(stream)) return true;

    __int64 current;
    __int64 next;

    _fseeki64(stream, _ftelli64(stream) - sizeof(__int64), SEEK_SET);
    fread(&current, sizeof(__int64), 1, stream);
    fread(&next, sizeof(__int64), 1, stream);
    _fseeki64(stream, _ftelli64(stream) - sizeof(__int64), SEEK_SET);

    if (current > next) return true;
    else  return false;  
}

void fwrite_ser(__int64 &current, FILE* stream1, FILE* stream2)//записує серію із першого файлу у другий починаючи з поточної позиції файлового показчика
{
    __int64 previous = current;

    fwrite(&current, sizeof(__int64), 1, stream2);

    while (true) 
    {
        if (fread(&current, sizeof(__int64), 1, stream1) && current >= previous)
        {
            previous = current;
            fwrite(&current, sizeof(__int64), 1, stream2);
        }
        else 
        {
            if (current < previous)
            {
                _fseeki64(stream1, _ftelli64(stream1) - sizeof(__int64), SEEK_SET);
                current = previous;
            }
            else previous = current;
            break;
        }    
    }    
}

void merge_fake_series(FILE* stream2, FILE* stream3, __int64 numb_fake_series = 0)//записує серії другого файлу у третій
{
    __int64 current;
    __int64 previous;

    fread(&current, sizeof(__int64), 1, stream2);
    for (__int64 i = 0; i < numb_fake_series; i++)
    {
        previous = current;
        do
        {
            if (current < previous)
            {
                break;
            }
            else
            {
                fwrite(&current, sizeof(__int64), 1, stream3);
                previous = current;
            }

        } while (fread(&current, sizeof(__int64), 1, stream2));
    }
    _fseeki64(stream2, _ftelli64(stream2) - sizeof(__int64), SEEK_SET);
}

void merge_series(FILE* stream1, FILE* stream2, FILE* stream3)//зливає серії у дваох файлах поки другий файл не закінчиться та записує всі елементи злитих серій у третій файл
{
    __int64 current1;
    __int64 current2;

    while (true) 
    {
        fread(&current1, sizeof(__int64), 1, stream1);
        fread(&current2, sizeof(__int64), 1, stream2);

        if (current1 < current2)
        {
            fwrite(&current1, sizeof(__int64), 1, stream3);
            if (last_elem_in_ser(stream1) == true)
            {
                fwrite_ser(current2, stream2, stream3);
                break;
            }
            else _fseeki64(stream2, _ftelli64(stream2) - sizeof(__int64), SEEK_SET);
        }
        else 
        {
            fwrite(&current2, sizeof(__int64), 1, stream3);
            if (last_elem_in_ser(stream2) == true)
            {
                fwrite_ser(current1, stream1, stream3);
                break;
            }
            else _fseeki64(stream1, _ftelli64(stream1) - sizeof(__int64), SEEK_SET);
        }
    }
   
}

void merge_files(std::string filename1, std::string filename2, std::string filename3, __int64 numb_fake_series = 0)//циклічно зливає файли поки не буде отримано відсортований
{
    FILE* file1;
    FILE* file2;
    FILE* file3;

    __int64 current;

    __int64 numb_s1 = numb_of_series(filename1) + numb_fake_series;
    __int64 numb_s2 = numb_of_series(filename2);
    __int64 numb;

    bool end_of_merge = false;

    std::string str;

    if (numb_s1 == 1 && numb_s2 == 0) return;

    while (end_of_merge == false)
    {
        fopen_s(&file1, filename1.c_str(), "rb");
        fopen_s(&file2, filename2.c_str(), "rb");
        fopen_s(&file3, filename3.c_str(), "wb");

        if (file1 == 0 || file2 == 0 || file3 == 0) return;

        if (numb_fake_series > 0) 
        {
            merge_fake_series(file2, file3, numb_fake_series);
            numb_fake_series = 0;
        }
       
        while (last_elem_was_read(file2) == false)
        {
            merge_series(file1, file2, file3);
        }          
      
        fclose(file3);
        fclose(file2);

        //merge other series
        fopen_s(&file2, filename2.c_str(), "wb");
        if (file2 != 0) 
        {
            while (fread(&current, sizeof(__int64), 1, file1))
            {
                fwrite(&current, sizeof(__int64), 1, file2);
            }

            fclose(file1);
            fclose(file2);
        }

        if (numb_s1 == 1 && numb_s2 == 0)
        {
            end_of_merge = true;
        }

        str = filename1;
        filename1 = filename3;
        filename3 = str;  

        numb = numb_s1;
        numb_s1 = numb_s2;
        numb_s2 = numb - numb_s2;
    }
}

void poly_sort(std::string filename)//викликає інші функції для багатофазного сортування, додає до старої назви файлу "Old"
{
    __int64 numb_fake_series;

    std::string filename1 = filename + "1";
    std::string filename2 = filename + "2";
    std::string filename3 = filename + "3";
    std::string file_name;

    numb_fake_series = distribution(filename, filename1, filename2);

    merge_files(filename1, filename2, filename3, numb_fake_series);

    if (numb_of_series(filename1) == 1) file_name = filename1;
    else if (numb_of_series(filename2) == 1) file_name = filename2;
    else file_name = filename3;

    remove((filename + "Old").c_str());
    rename(filename.c_str(), (filename + "Old").c_str());
    rename(file_name.c_str(), filename.c_str());

    remove(filename1.c_str());
    remove(filename2.c_str());
    remove(filename3.c_str());
    remove((file_name).c_str());
}