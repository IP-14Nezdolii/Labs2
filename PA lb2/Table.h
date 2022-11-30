#pragma once
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <random>

/*клас, який представляє дошку*/
class Table {
private:
	size_t _numb;
	char** mat = NULL;	

public:
	Table(int num)
	{
		_numb = num;
		mat = new char* [_numb];
		for (size_t i = 0; i < _numb; i++)
		{
			mat[i] = new char[_numb];
			for (size_t j = 0; j < _numb; j++) mat[i][j] = '-';
		}
	};

	Table(const Table& table)
	{
		_numb = table._numb;
		
		char** k = mat;

		mat = new char* [_numb];
		for (size_t i = 0; i < _numb; i++)
		{
			mat[i] = new char[_numb];
			for (size_t j = 0; j < _numb; j++) mat[i][j] = table.mat[i][j];
		}
	}

	Table(Table* table)
	{
		_numb = table->_numb;
		mat = new char* [_numb];

		for (size_t i = 0; i < _numb; i++)
		{
			mat[i] = new char[_numb];
			for (size_t j = 0; j < _numb; j++) mat[i][j] = table->mat[i][j];
		}
	}

	~Table()
	{
		for (size_t i = 0; i < _numb; i++) delete[] mat[i];
		delete[] mat;
	};

	void gen_table();/*розміщує на випадковій позиції в кожному рядку ферзя*/

	size_t find(size_t row);/*повертає індекс колонки, на якій знаходиться ферзь*/

	virtual bool change_pos(size_t row, size_t col);/*змінює позицію ферзя в рядку*/

	size_t numb() { return _numb; };/*повертає кількість рядків дошки*/

	void copy(const Table& table);

	friend std::ostream& operator<< (std::ostream& out, const Table& table);

	virtual size_t size_of();/*повертає приблизну кількість байтів, що займає дошка*/

	virtual size_t numb_of_conf();/*повертає кількість конфліктів між ферзями на дошці*/

	Table& operator = (const Table& table);

	bool is_init() 
	{
		if (this == NULL) return false;
		if (mat == NULL) return false;
		return true;
	}
};

#endif

