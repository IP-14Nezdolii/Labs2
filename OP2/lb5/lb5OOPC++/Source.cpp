#include "TVector.h"
#include "Header.h"
#include <math.h>
#include <iostream>

void input_m(size_t value, TVector mas[])
{
	for (size_t i = 0; i < value; i++)
	{
		std::cout << "Введіть кординати нового вектора номер "<<i+1<<" :\n";
		std::cin >> mas[i];
	}
	std::cout << "\n";
}

void output_m(size_t value, TVector mas[])
{
	for (size_t i = 0; i < value; i++)
	{
		std::cout << "\nКординати вектора номер " << i + 1 << " : ";
		std::cout << mas[i];
	}
	std::cout << "\n";
}
