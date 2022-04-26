
#include <iostream>
#include "Header.h"
#include "Windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int length;
    Word* arr = input_arr(length);
    print_arr(arr, length);
    find_in_arr(arr, length);
    delete[]arr;
}
