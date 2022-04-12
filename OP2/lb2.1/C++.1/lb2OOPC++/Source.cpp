#include <string> 
#include <iostream>
#include <fstream>
#include "Header.h"
#include "Windows.h"
#include "stdlib.h"

struct Cars {
    char  name[15],      //назва автомоб≥л€                
          releaseD[15],  //дата випуску
          saleD[15];     //дата надходженн€ у продаж 
};

void outList(std::string fileName)        //функц≥€ запису/перезапису списку автомоб≥л≥в у файл≥; €кщо файл в≥дсутн≥й, то в≥н створюЇтьс€
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    std::ofstream outFile(fileName, std::ios::binary);
    Cars b;
    
    int n;
    std::cout << "¬вед≥ть к≥льк≥сть автомоб≥л≥в: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++)
    {
        std::cout << "¬вед≥ть назву автомоб≥л€: ";
        std::cin >> b.name;
        std::cout << "¬вед≥ть дату випуску: ";
        std::cin >> b.releaseD;
        std::cout << "¬вед≥ть дату початку продажу: ";
        std::cin >> b.saleD;
        outFile.write((char*)&b, sizeof(Cars));
    }
      
    outFile.close();
}

void inList(std::string fileName)     //функц≥€ виведенн€ списку автомоб≥л≥в ≥з файлу                                        
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "\n—писок автомоб≥л≥в:"<< "\n";
    std::ifstream inFile(fileName, std::ios::binary);
    Cars b;

    while (inFile.read((char*)&b, sizeof(Cars)))                                      
    {
        std::cout << b.name <<' '<< b.releaseD << ' ' << b.saleD << "\n";
    }

    inFile.close();
}

void data(std::string l, int d[2][3])   //функц≥€ заповненн€ масиву даними з≥ списку
{
    d[0][0] = std::stoi(l.substr(0, 2));
    d[0][1] = std::stoi(l.substr(3, 2));
    d[0][2] = std::stoi(l.substr(6, 4));
    d[1][0] = std::stoi(l.substr(10, 2));
    d[1][1] = std::stoi(l.substr(13, 2));
    d[1][2] = std::stoi(l.substr(16, 4));
}

void newList(std::string fileName1, std::string fileName2)     //функц≥€ створенн€ нового б≥нарного файлу на основ≥ першого б≥нарного файлу з урахуванн€м умов завданн€
{
    std::ifstream inFile(fileName1, std::ios::binary);
    std::ofstream outFile(fileName2, std::ios::binary);
    int dif; //р≥зниц€ в датах
    Cars b;
    int d[2][3];

    while (inFile.read((char*)&b, sizeof(Cars)))
    {
        data(std::string(b.releaseD) + std::string(b.saleD), d);
        dif = (d[1][2]- d[0][2])*365 + (d[1][1] - d[0][1])*30 + (d[1][0] - d[0][0]);
        if (dif <= 60)
        {
            outFile.write((char*)&b, sizeof(Cars));
        }
    }

    inFile.close();
    outFile.close();
}

void inList2(std::string fileName)                                                       
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream inFile(fileName, std::ios::binary);
    Cars b;
    int d[2][3];
    int year;
    std::cout << "\n¬вед≥ть р≥к: "; std::cin >> year;
    std::cout << "—писок автомоб≥л≥в, €к≥ були випущен≥ не ран≥ше вказаного року:" << "\n";

    while (inFile.read((char*)&b, sizeof(Cars)))
    {
        data(std::string(b.releaseD) + std::string(b.saleD), d);
        if (d[0][2] >= year)
        {
            std::cout << b.name << ' ' << b.releaseD << ' ' << b.saleD << "\n";
        }       
    }

    inFile.close();
}

void adList(std::string fileName)      //функц≥€ доданн€ елемент≥в списку у б≥нарний файл
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ofstream adFile(fileName, std::ios::app, std::ios::binary );
    Cars b;

    int n;
    std::cout << "¬вед≥ть €ку к≥льк≥сть автомоб≥л≥в ви хочете додати: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++)
    {
        std::cout << "¬вед≥ть назву автомоб≥л€: ";
        std::cin >> b.name;
        std::cout << "¬вед≥ть дату випуску: ";
        std::cin >> b.releaseD;
        std::cout << "¬вед≥ть дату початку продажу: ";
        std::cin >> b.saleD;
        adFile.write((char*)&b, sizeof(Cars));
    }

    adFile.close();
}