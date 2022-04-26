#pragma once
#ifndef HEADER_H_
#define HEADER_H_
#include <string>

class Word
{
public:
    std::string name;
    int digits();   
};

Word* input_arr(int& length);
void print_arr(Word* arr, int length);
void find_in_arr(Word* arr, int length);

#endif
