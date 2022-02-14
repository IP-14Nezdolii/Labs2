#include <string> 
#include <iostream>
#include <fstream>
#include "Header.h"

void outText(std::string fileName)                                                       //������� ������/���������� ������ � ����; ���� ���� �������, �� �� �����������
{
    std::ofstream outFile(fileName);
    std::string str;                                                                     //��������� "��������" �����
    while (true)
    {
        std::getline(std::cin, str);
        if (str.rfind(char(25)) == (str.length() - 1))                                   //���� ������� ������ ���� � ���� �����
        {                                            
            str.resize(str.length() - 1);                                                //�������� ����� �� 1 ������
            outFile << str << '\n';                                                      //�������� ����� � ����
            break;
        }
        outFile << str << '\n';
    }
    outFile.close();
}

void inText(std::string fileName)                                                       //������� ��������� ������ �� �����
{
    std::ifstream inFile(fileName);
    std::string str;                                                                    //��������� "��������" �����
    while (!inFile.eof())                                                               //���� �� ���������� �����
    {
        std::getline(inFile, str);
        std::cout <<"\n"<<str;
    }
    inFile.close();
}

void newText(std::string fileName, std::string newfileName) {                          //������� ��������� ������ ���������� ����� �� ����� ������� ���������� ����� � ����������� ���� ��������
    std::string str;                                                                   //��������� "��������" �����
    int a;                                                                             //������� ���������� �������

    std::ifstream inFile1(fileName);
    std::ofstream outFile2(newfileName);
    while (!inFile1.eof())
    {
        std::getline(inFile1, str);
        a = str.length() - 1;
        if ((str.rfind(' ') != a) && (str.rfind(',') != a) && (str.rfind('.') != a))  //���� � ���� ����� ������� �����, ������ �� ����
        {
            str = "-";                                                                    
        } 
        outFile2 << str << '\n';
    }

    inFile1.close();
    outFile2.close();
}

void appText(std::string fileName)                                                       //������� ������� ������ � ����
{
    std::ofstream outFile(fileName,std::ios::app);
    std::string str;                                                                     //��������� "��������" �����
    while (true)
    {
        std::getline(std::cin, str);
        if (str.rfind(char(25)) == (str.length() - 1))                                   //���� ������� ������ ���� � ���� �����
        {
            str.resize(str.length() - 1);                                                //�������� ����� �� 1 ������
            outFile << str << '\n';                                                      //�������� ����� � ����
            break;
        }
        outFile << str << '\n';
    }
    outFile.close();
}