#pragma once
#ifndef HEADER_H
#define HEADER_H

struct Branch
{
	char Data;
	Branch* LeftB;
	Branch* RightB;
};

void Add(char aData, Branch*& aBranch);
void createTree(Branch*& aBranch, std::string str);
void FreeTree(Branch* aBranch);
void print(Branch* aBranch);
void find(Branch* aBranch, char symb, int n = 0);

#endif