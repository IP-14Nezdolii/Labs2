
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include "Header.h"



int main()
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char symb;
	Branch* Tree = 0;
	std::string str;

	std::cout << "Введіть символи: ";
	std::cin >> str;
	std::cout << "Введіть символ для подальшого пошуку довжини шляху до нього: ";
	std::cin >> symb;

	createTree(Tree, str);

	std::cout << "Елементи дерева: ";
	print(Tree);

	std::cout << "\nДовжина шляху до вказаного символу: ";
	find(Tree, symb);

	FreeTree(Tree);
}