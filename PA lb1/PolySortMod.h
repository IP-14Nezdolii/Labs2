#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "PolySort.h"
#include "Arr.h"

//Значна частина функцій працює аналогічно немодифікованим, але використовує в якості буфера "масиви",
//сумарний розмір яких, одночасно "існуючих", в більшості випадках є не більше ніж половина розміру вхідного файла  

__int64 file_size(std::string filename)//повертає розмір файла в байтах
{
    __int64 size;
    FILE* file;

    fopen_s(&file, filename.c_str(), "rb");

    if (file != 0) 
    {
        _fseeki64(file, 0, SEEK_END);
        size = _ftelli64(file);
        fclose(file);

        return size;
    }
    
    return -1;
}

__int64 numb_of_series_mod(std::string filename)
{
    __int64 numb = 1;
    __int64 previous;
    FILE* file;

    Arr arr(file_size(filename));
    fopen_s(&file, filename.c_str(), "rb");

    if (file != 0)
    {
        if(fread(arr, file) == 0) return 0;
        previous = arr[0];

        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[i] < previous)
            {
                numb += 1;
            }
            previous = arr[i];
        }

        while(fread(arr, file))
        {
            for (size_t i = 0; i < arr.size(); i++)
            {
                if (arr[i] < previous)
                {
                    numb += 1;
                }
                previous = arr[i];
            }
        }

        fclose(file);
    }
    return numb;
}

__int64 distribution_mod(std::string filename, std::string filename1, std::string filename2)//перед розподілом ділить вхідний файл на серії
{
    FILE* file;
    FILE* file3;

    Arr arr(file_size(filename));

    fopen_s(&file, filename.c_str(), "rb");
    fopen_s(&file3, (filename + "3").c_str(), "wb");

    if (file != 0 && file3 != 0) 
    {
        while (fread(arr, file))
        {
            arr.sort();
            fwrite(arr, file3);
        }

        fclose(file);
        fclose(file3);       
    }

    remove((filename + "Old").c_str());
    rename(filename.c_str(), (filename + "Old").c_str());
    rename((filename + "3").c_str(), (filename).c_str());
   
    __int64 real_numb_series = numb_of_series_mod(filename);
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

void fwrite_buff(Arr& arr, FILE* stream3)//запсує з буфера інформацію у відкритий файл
{
    if (arr.size() != 0)
    {
        fwrite(arr, stream3);
        arr.clear();
    }
}

void fwrite_ser_mod(Arr& arr, size_t& ind, FILE* stream, FILE* stream3)//використовується в merge_series_mod
{
    bool ser_end = false;
    __int64 prev = arr[ind];

    for (ind; ind < arr.size(); ind++)
    {
        if (prev > arr[ind])
        {
            ind--;
            ser_end = true;
            break;
        }
        else
        {
            fwrite(&arr[ind], 8, 1, stream3);
            prev = arr[ind];
        }      
    }

    while (ser_end == false)
    {
        if (fread(arr, stream)) 
        {
            for (size_t i = 0; i < arr.size(); i++)
            {
                if (prev > arr[i])
                {
                    ind = i--;
                    ser_end = true;
                    break;
                }
                else
                {
                    fwrite(&arr[i], 8, 1, stream3);
                    prev = arr[i];
                }                
            }
        }
        else 
        {
            break;
        }
    }

    _fseeki64(stream, _ftelli64(stream) - __int64(arr.size() - ( ind)) * 8, SEEK_SET);
}

void fwrite_ser_mod(Arr& arr, FILE* stream, FILE* stream3)//використовується в merge_files_mod
{
    bool ser_end = false;
    __int64 prev;
    size_t ind = 0;

    fread(arr, stream);
    prev = arr[0];

    for (ind; ind < arr.size(); ind++)
    {
        if (prev > arr[ind])
        {
            ind--;
            ser_end = true;
            break;
        }
        else
        {
            fwrite(&arr[ind], 8, 1, stream3);
            prev = arr[ind];
        }
    }

    while (ser_end == false)
    {
        if (fread(arr, stream))
        {
            for (size_t i = 0; i < arr.size(); i++)
            {
                if (prev > arr[i])
                {
                    ind = i--;
                    ser_end = true;
                    break;
                }
                else
                {
                    fwrite(&arr[i], 8, 1, stream3);
                    prev = arr[i];
                }
            }
        }
        else
        {
            break;
        }
    }

    _fseeki64(stream, _ftelli64(stream) - __int64(arr.size() - (ind)) * 8, SEEK_SET);
}

void merge_series_mod(std::string filename, FILE* stream1, FILE* stream2, FILE* stream3)
{

    Arr arr1(file_size(filename));
    Arr arr2(file_size(filename));
    Arr arr3(file_size(filename));

    fread(arr1, stream1);
    fread(arr2, stream2);

    __int64 num = __int64(arr1.size() + arr2.size());

    size_t ind1 = 0;
    size_t ind2 = 0;

    __int64 prev1 = arr1[ind1];
    __int64 prev2 = arr2[ind2];

    for (__int64 i = 0; i < num; i++)
    {
        if (prev1 > arr1[ind1])
        {
            fwrite_buff(arr3, stream3);
            _fseeki64(stream1, _ftelli64(stream1) - __int64(arr1.size() - (ind1)) * 8, SEEK_SET);
            fwrite_ser_mod(arr2, ind2, stream2, stream3);
            break;
        }
        else if (prev2 > arr2[ind2])
        {
            fwrite_buff(arr3, stream3);
            _fseeki64(stream2, _ftelli64(stream2) - __int64(arr2.size() - (ind2)) * 8, SEEK_SET);
            fwrite_ser_mod(arr1, ind1, stream1, stream3);
            break;
        }

        if (arr1[ind1] < arr2[ind2])
        {
            arr3.append(arr1[ind1]);
            prev1 = arr1[ind1];

            if (ind1 + 1 == arr1.size()) 
            {
                if (last_elem_was_read(stream1) == false) 
                {
                    fread(arr1, stream1);
                    num += arr1.size();
                    ind1 = 0;
                }
                else 
                {
                    fwrite_buff(arr3, stream3);
                    fwrite_ser_mod(arr2, ind2, stream2, stream3);
                    break;
                }              
            }
            else ind1++;
        }
        else 
        {
            arr3.append(arr2[ind2]);
            prev2 = arr2[ind2];

            if (ind2 + 1 == arr2.size())
            {
                if (last_elem_was_read(stream2) == false) 
                {
                    fread(arr2, stream2);
                    num += arr2.size();
                    ind2 = 0;
                }
                else 
                {
                    fwrite_buff(arr3, stream3);
                    fwrite_ser_mod(arr1, ind1, stream1, stream3);
                    break;
                }
            }
            else ind2++;
        }

        if (arr3.size() == arr3.max_size()) fwrite_buff(arr3, stream3);
    }
}

void merge_files_mod(std::string filename, std::string filename1, std::string filename2, std::string filename3, __int64 numb_fake_series = 0)
{
    FILE* file1;
    FILE* file2;
    FILE* file3;

    __int64 numb_s1 = numb_of_series_mod(filename1) + numb_fake_series;
    __int64 numb_s2 = numb_of_series_mod(filename2);
    __int64 numb;

    Arr arr(file_size(filename));

    bool end_of_merge = false;

    std::string str;

    if (numb_s1 == 1 && numb_s2 == 0) return;

    while (end_of_merge == false)
    {
        fopen_s(&file1, filename1.c_str(), "rb");
        fopen_s(&file2, filename2.c_str(), "rb");
        fopen_s(&file3, filename3.c_str(), "wb");

        if (file1 == 0 || file2 == 0 || file3 == 0) return;

        for (size_t i = 0; i < numb_fake_series; i++)
        {
            fwrite_ser_mod(arr, file2, file3);
        }
        numb_fake_series = 0;
        

        while (last_elem_was_read(file2) == false)
        {
            merge_series_mod(filename, file1, file2, file3);
        }

        fclose(file3);
        fclose(file2);

        //merge other series
        fopen_s(&file2, filename2.c_str(), "wb");
        if (file2 != 0)
        {
            while (fread(arr, file1))
            {
                fwrite(arr, file2);
            }

            fclose(file1);
            fclose(file2);
        }

        if (numb_s1 == 1 && numb_s2 == 0)
        {
            end_of_merge = true;
        }
        else 
        {
            str = filename1;
            filename1 = filename3;
            filename3 = str;

            numb = numb_s1;
            numb_s1 = numb_s2;
            numb_s2 = numb - numb_s2;
        }
    }
}

void poly_sort_mod(std::string filename)
{
    __int64 numb_fake_series;

    std::string filename1 = filename + "1";
    std::string filename2 = filename + "2";
    std::string filename3 = filename + "3";
    std::string file_name;

    numb_fake_series = distribution_mod(filename, filename1, filename2);

    merge_files_mod(filename, filename1, filename2, filename3, numb_fake_series);

    if (numb_of_series_mod(filename1) == 1) file_name = filename1;
    else if (numb_of_series_mod(filename2) == 1) file_name = filename2;
    else file_name = filename3;

    remove((filename).c_str());
    rename(file_name.c_str(), filename.c_str());

    remove(filename1.c_str());
    remove(filename2.c_str());
    remove(filename3.c_str());
    remove((file_name).c_str());
}