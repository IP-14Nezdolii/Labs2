#include <iostream>
#include <string>
#include <ctime>
#include "PolySort.h"
#include "PolySortMod.h"
#include "Testing.h"


int main()
{
    std::string filename = "file";

    // // __int64(1024 * 131072), 294967295

    //gen_file(filename, ( __int64(16* 1024) * 131072), 294967295);//10 * 131072 //294967295
    //out_file(filename);
    //std::cout << std::endl << numb_of_series_mod(filename) << " " << file_size(filename) << std::endl;
    //std::cout << std::endl << "start numb of series: " << numb_of_series_mod(filename) << " " << "file_size: " << file_size(filename) << std::endl;
    
    //демонстрація роботи алгоритмів на прикладі малих вхідних файлів
    // 
    gen_file(filename, 20, 40);
    out_file(filename);
    poly_sort(filename);
    out_file(filename);
    //out_file(filename);
    std::cout << std::endl;
    gen_file(filename, 20, 40);
    out_file(filename);
    //unsigned int start_time = clock();
    poly_sort_mod(filename);
    //unsigned int end_time = clock();
    out_file(filename);
    //out_file(filename);
   // std::cout << std::endl << "end numb of series: " << numb_of_series_mod(filename) << " " << "file_size: " << file_size(filename) << std::endl;
    //std::cout << std::endl << numb_of_series_mod(filename) << " " << file_size(filename) << std::endl;
    //std::cout << std::endl << "time: " << (end_time - start_time) / (60000);
    getchar();
}
