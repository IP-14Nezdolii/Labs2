#include <iostream>
#include <string>
#include "Header.h"
#include "windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    outList("File.dat");
    inList("File.dat");
    newList("File.dat", "File2.dat");
    inList("File2.dat");
    inList2("File2.dat");
}
