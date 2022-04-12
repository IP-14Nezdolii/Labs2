#include <string> 
#include <iostream>
#include <fstream>
#include "Header.h"
#include "Windows.h"
#include "stdlib.h"

struct Cars {
    char  name[15],      //����� ���������                
          releaseD[15],  //���� �������
          saleD[15];     //���� ����������� � ������ 
};

void outList(std::string fileName)        //������� ������/���������� ������ ��������� � ����; ���� ���� �������, �� �� �����������
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    std::ofstream outFile(fileName, std::ios::binary);
    Cars b;
    
    int n;
    std::cout << "������ ������� ���������: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++)
    {
        std::cout << "������ ����� ���������: ";
        std::cin >> b.name;
        std::cout << "������ ���� �������: ";
        std::cin >> b.releaseD;
        std::cout << "������ ���� ������� �������: ";
        std::cin >> b.saleD;
        outFile.write((char*)&b, sizeof(Cars));
    }
      
    outFile.close();
}

void inList(std::string fileName)     //������� ��������� ������ ��������� �� �����                                        
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "\n������ ���������:"<< "\n";
    std::ifstream inFile(fileName, std::ios::binary);
    Cars b;

    while (inFile.read((char*)&b, sizeof(Cars)))                                      
    {
        std::cout << b.name <<' '<< b.releaseD << ' ' << b.saleD << "\n";
    }

    inFile.close();
}

void data(std::string l, int d[2][3])   //������� ���������� ������ ������ � ������
{
    d[0][0] = std::stoi(l.substr(0, 2));
    d[0][1] = std::stoi(l.substr(3, 2));
    d[0][2] = std::stoi(l.substr(6, 4));
    d[1][0] = std::stoi(l.substr(10, 2));
    d[1][1] = std::stoi(l.substr(13, 2));
    d[1][2] = std::stoi(l.substr(16, 4));
}

void newList(std::string fileName1, std::string fileName2)     //������� ��������� ������ �������� ����� �� ����� ������� �������� ����� � ����������� ���� ��������
{
    std::ifstream inFile(fileName1, std::ios::binary);
    std::ofstream outFile(fileName2, std::ios::binary);
    int dif; //������ � �����
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
    std::cout << "\n������ ��: "; std::cin >> year;
    std::cout << "������ ���������, �� ���� ������� �� ����� ��������� ����:" << "\n";

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

void adList(std::string fileName)      //������� ������� �������� ������ � ������� ����
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ofstream adFile(fileName, std::ios::app, std::ios::binary );
    Cars b;

    int n;
    std::cout << "������ ��� ������� ��������� �� ������ ������: ";
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++)
    {
        std::cout << "������ ����� ���������: ";
        std::cin >> b.name;
        std::cout << "������ ���� �������: ";
        std::cin >> b.releaseD;
        std::cout << "������ ���� ������� �������: ";
        std::cin >> b.saleD;
        adFile.write((char*)&b, sizeof(Cars));
    }

    adFile.close();
}