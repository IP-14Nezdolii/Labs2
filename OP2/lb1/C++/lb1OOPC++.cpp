#include <iostream>
#include <string>
#include "Header.h"
#include "windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Для введення тексту у файл з нового рядка натисніть Enter.\n"
        "Для завершення введення тексту у файл в кінці введеного рядка натисніть Ctrl+y, а потім Enter.\n";

    std::string fileName;
    std::cout << '\n' << "Введіть ім'я першого файлу: "; std::getline(std::cin, fileName);

    std::cout << '\n' << "Введіть текст: " << '\n';
    outText(fileName);

    std::string newfileName;
    std::cout << '\n' << "Введіть ім'я другого файлу: "; std::getline(std::cin, newfileName);

    newText(fileName, newfileName);

    std::cout << '\n' << "Текст у першому файлі: ";
    inText(fileName);
    std::cout << '\n' << "Текст у другому файлі: ";
    inText(newfileName);

    std::cout << '\n' << "Додати текст у перший файл: " << '\n';
    appText(fileName);
    std::cout << '\n' << "Текст у першому файлі: ";
    inText(fileName);
}