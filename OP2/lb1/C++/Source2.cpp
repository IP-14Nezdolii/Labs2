#include <string> 
#include <iostream>
#include <fstream>
#include "Header.h"

void outText(std::string fileName)                                                       //ôóíêö³ÿ çàïèñó/ïåðåçàïèñó òåêñòó ó ôàéë³; ÿêùî ôàéë â³äñóòí³é, òî â³í ñòâîðþºòüñÿ
{
    std::ofstream outFile(fileName);
    std::string str;                                                                     //äîïîì³æíèé "áóôåðíèé" ðÿäîê
    bool works = true;
    while (works)
    {
        std::getline(std::cin, str);
        if (str.rfind(char(25)) == (str.length() - 1))                                   //ÿêùî çàäàíèé ñèìâîë áóäå â ê³íö³ ðÿäêà
        {                                            
            str.resize(str.length() - 1);                                                //çìåíøèòè ðÿäîê íà 1 ñèìâîë
            outFile << str << '\n';                                                      //çàïèñàòè ðÿäîê ó ôàéë
            works = false;
        }
        else outFile << str << '\n';
    }
    outFile.close();
}

void inText(std::string fileName)                                                       //ôóíêö³ÿ âèâåäåííÿ òåêñòó ³ç ôàéëó
{
    std::ifstream inFile(fileName);
    std::string str;                                                                    //äîïîì³æíèé "áóôåðíèé" ðÿäîê
    while (!inFile.eof())                                                               //ïîêè íå çàê³í÷àòüñÿ ðÿäêè
    {
        std::getline(inFile, str);
        std::cout <<"\n"<<str;
    }
    inFile.close();
}

void newText(std::string fileName, std::string newfileName) {                          //ôóíêö³ÿ ñòâîðåííÿ íîâîãî òåêñòîâîãî ôàéëó íà îñíîâ³ ïåðøîãî òåêñòîâîãî ôàéëó ç óðàõóâàííÿì óìîâ çàâäàííÿ
    std::string str;                                                                   //äîïîì³æíèé "áóôåðíèé" ðÿäîê
    int a;                                                                             //ïîçèö³ÿ îñòàííüîãî ñèìâîëó

    std::ifstream inFile1(fileName);
    std::ofstream outFile2(newfileName);
    while (!inFile1.eof())
    {
        std::getline(inFile1, str);
        a = str.length() - 1;
        if ((str.rfind(' ') != a) && (str.rfind(',') != a) && (str.rfind('.') != a))  //ÿêùî â ê³íö³ ðÿäêà â³äñóñòí³ ïðîá³ë, êðàïêà ÷è êîìà
        {
            str = "-";                                                                    
        } 
        outFile2 << str << '\n';
    }

    inFile1.close();
    outFile2.close();
}

void appText(std::string fileName)                                                    //ôóíêö³ÿ äîäàííÿ òåêñòó ó ôàéë
{
    std::ofstream outFile(fileName,std::ios::app);
    std::string str;                                                                  //äîïîì³æíèé "áóôåðíèé" ðÿäîê
    while (true)
    {
        std::getline(std::cin, str);
        if (str.rfind(char(25)) == (str.length() - 1))                                //ÿêùî çàäàíèé ñèìâîë áóäå â ê³íö³ ðÿäêà
        {
            str.resize(str.length() - 1);                                             //çìåíøèòè ðÿäîê íà 1 ñèìâîë
            outFile << str << '\n';                                                   //çàïèñàòè ðÿäîê ó ôàéë
            break;
        }
        outFile << str << '\n';
    }
    outFile.close();
}
