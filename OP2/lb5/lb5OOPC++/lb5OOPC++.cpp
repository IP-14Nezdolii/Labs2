#include "Header.h"
#include "TVector.h"
#include <iostream>
#include <Windows.h>



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    R2Vector *mas1 = new R2Vector[3];
    R3Vector *mas2 = new R3Vector[4];

    double sum = 0;

    std::cout << "Введення трьох двовимірних векторів\n";
    input_m(3, mas1);
    std::cout << "Введення чотирьох тривимірних векторів\n";
    input_m(4, mas2);

    std::cout << "Двовимірні вектори :";
    output_m(3, mas1);
    std::cout << "\nТривимірні вектори :";
    output_m(4, mas2);
   
    for (size_t i = 1; i<3; i++)
    {
        if (mas1[0].parall(mas1[i]) == true)
        {
            std::cout << "\nДвовимірний вектор номер "<<i+1<<" паралельний до вектоа номер 1";
            sum += mas1[i].length();
        }
    }
    std::cout <<"\nСума довжин векторів паралельних до вектора номер 1: " << sum << "\n";

    sum = 0;
    for (size_t i = 1; i < 4; i++)
    {
        if (mas2[0].perp(mas2[i]) == true)
        {
            std::cout << "\nТривимірний вектор номер " << i+1 << " перпендикулярний до вектоа номер 1";
            sum += mas2[i].length();
        }
    }
    std::cout << "\nСума довжин векторів перпендикулярних до вектора номер 1: " << sum << "\n";

    delete[] mas1;
    delete[] mas2;
}
