#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Arr.h"
#include "PolySort.h"
#include <random>

void out_file(std::string filename)
{
    __int64 numb;
    FILE* file;

    fopen_s(&file, filename.c_str(), "rb");

    if (file != 0)
    {
        std::cout << std::endl;
        while (fread(&numb, sizeof(__int64), 1, file))
        {
            std::cout << numb << " ";
        }
        fclose(file);
    }
}

void gen_test_file(std::string filename)
{
    std::vector<__int64> vec = { 169, 248, 13, 190, 258, 24, 31, 72, 155, 126, 165, 176, 288, 202, 191, 212, 119, 680, 232, 168};// 169654101, 248050465, 13718010, 190671929, 258435847, 24063424, 31931653, 72237826, 155657666, 126200505, 165518586, 176579132, 288400809, 202949216, 191908928, 212622548, 119278197, 68063412, 232600831, 168667620
    FILE* file;

    fopen_s(&file, filename.c_str(), "wb");

    if (file != 0)
    {
        for (size_t i = 0; i < vec.size(); i++)
        {
            fwrite(&vec[i], sizeof(__int64), 1, file);
        }
        fclose(file);
    }
}

void gen_file(std::string filename, __int64 num = 10, __int64 range = 20)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<__int64> dist(0, range);

    FILE* file;

    Arr arr(8 * num);
    remove(filename.c_str());
    fopen_s(&file, filename.c_str(), "wb");
    if (file != 0)
    {
        for (__int64 i = 0; i < num; i++)
        {
            if (arr.size() == arr.max_size())
            {
                fwrite(arr, file);
                arr.clear();
            }  
            arr.append(dist(mt));
        }
        if (arr.size() != 0) fwrite(arr, file);
        fclose(file);
    }
}