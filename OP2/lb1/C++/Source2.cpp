#include <string> 
#include <iostream>
#include <fstream>
#include "Header.h"

void outText(std::string fileName)                                                       //функція запису/перезапису тексту у файлі; якщо файл відсутній, то він створюється
{
    std::ofstream outFile(fileName);
    std::string str;                                                                     //допоміжний "буферний" рядок
    while (true)
    {
        std::getline(std::cin, str);
        if (str.rfind(char(25)) == (str.length() - 1))                                   //якщо заданий символ буде в кінці рядка
        {                                            
            str.resize(str.length() - 1);                                                //зменшити рядок на 1 символ
            outFile << str << '\n';                                                      //записати рядок у файл
            break;
        }
        outFile << str << '\n';
    }
    outFile.close();
}

void inText(std::string fileName)                                                       //функція виведення тексту із файлу
{
    std::ifstream inFile(fileName);
    std::string str;                                                                    //допоміжний "буферний" рядок
    while (!inFile.eof())                                                               //поки не закінчаться рядки
    {
        std::getline(inFile, str);
        std::cout <<"\n"<<str;
    }
    inFile.close();
}

void newText(std::string fileName, std::string newfileName) {                          //функція створення нового текстового файлу на основі першого текстового файлу з урахуванням умов завдання
    std::string str;                                                                   //допоміжний "буферний" рядок
    int a;                                                                             //позиція останнього символу

    std::ifstream inFile1(fileName);
    std::ofstream outFile2(newfileName);
    while (!inFile1.eof())
    {
        std::getline(inFile1, str);
        a = str.length() - 1;
        if ((str.rfind(' ') != a) && (str.rfind(',') != a) && (str.rfind('.') != a))  //якщо в кінці рядка відсустні пробіл, крапка чи кома
        {
            str = "-";                                                                    
        } 
        outFile2 << str << '\n';
    }

    inFile1.close();
    outFile2.close();
}

void appText(std::string fileName)                                                       //функція додання тексту у файл
{
    std::ofstream outFile(fileName,std::ios::app);
    std::string str;                                                                     //допоміжний "буферний" рядок
    while (true)
    {
        std::getline(std::cin, str);
        if (str.rfind(char(25)) == (str.length() - 1))                                   //якщо заданий символ буде в кінці рядка
        {
            str.resize(str.length() - 1);                                                //зменшити рядок на 1 символ
            outFile << str << '\n';                                                      //записати рядок у файл
            break;
        }
        outFile << str << '\n';
    }
    outFile.close();
}