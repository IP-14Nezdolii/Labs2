
#include <iostream>
#include <iomanip>
#include <string>
#include "Header.h"



void Add(char aData, Branch*& aBranch)
{
	if (aBranch == 0)
	{
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftB = 0;
		aBranch->RightB = 0;
		return;
	}

	if (aBranch->Data > aData)
	{
		Add(aData, aBranch->LeftB);
		return;
	}

	if (aBranch->Data < aData)
	{
		Add(aData, aBranch->RightB);
		return;
	};
}


void createTree(Branch*& aBranch, std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		Add(str[i], aBranch);
	}
}


void FreeTree(Branch* aBranch)
{
	if (!aBranch) return;
	FreeTree(aBranch->LeftB);
	FreeTree(aBranch->RightB);
	delete aBranch;
	return;
}

void print(Branch* aBranch)
{
	if (aBranch == 0) return;
	std::cout << aBranch->Data << std::setw(2);
	print(aBranch->LeftB);
	print(aBranch->RightB);
}

void find(Branch* aBranch, char symb, int n)
{
	if (aBranch != 0)
	{
		if (aBranch->Data == symb)
		{
			std::cout << n;
			return;
		}
		else
		{
			find(aBranch->LeftB, symb, n + 1);
			find(aBranch->RightB, symb, n + 1);
		}
	}
}
