#include "Header.h"
#include <string>
#include <iostream>

int Word::digits()
{
    int n = 0,
        k = name.length();

    for (int i = 0; i < k; i++)
    {
        if (name[i] >= '0' && name[i] <= '9') n++;
    }
    return n;
}

Word* input_arr(int& length)
{
    std::cout << "������ ������� �������� ������: ";
    std::cin >> length;
    Word* arr = new Word[length];

    for (int i = 0; i < length; i++)
    {
        std::cout << "������ �����: ";
        std::cin >> arr[i].name;
    }

    return arr;
}

void print_arr(Word* arr, int length)
{
    std::cout << "������ ���: ";
    for (int i = 0; i < length; i++)
    {        
        std::cout << arr[i].name << ' ';
    }
}

void find_in_arr(Word* arr, int length) 
{
    int j = 0,
        max = 0,
        num = 0;
    for (int i = 0; i < length; i++)
    {
        num = arr[i].digits();
        if (max < num)
        {
            j = i;
            max = num;
        }
    }
    std::cout << "\n����� � ��������� ������� ����: "<< arr[j].name;
}
