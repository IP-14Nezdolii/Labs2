#include "Table.h"

void Table::gen_table()
{
	for (size_t i = 0; i < _numb; i++)
	{
		for (size_t j = 0; j < _numb; j++)
		{
			mat[i][j] = '-';
		}
	}

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, _numb - 1);
	for (int i = 0; i < _numb; i++)
	{
		mat[i][dist(mt)] = 'Q';
	}
}

bool Table::change_pos(size_t row, size_t col)
{
	size_t ind1 = find(row);
	size_t ind2 = col;

	if (ind1 == ind2) return false;

	mat[row][ind1] = '-';
	mat[row][ind2] = 'Q';
	return true;
}

size_t Table::find(size_t row)
{
	for (size_t i = 0; i < _numb; i++)
	{
		if (mat[row][i] == 'Q') return i;
	}
	return 0;
}

void Table::copy(const Table& table)
{
	if (this != &table) 
	{
		if (table._numb == _numb)
		{
			for (size_t i = 0; i < _numb; i++)
			{
				for (size_t j = 0; j < _numb; j++)
				{
					mat[i][j] = table.mat[i][j];
				}
			}
		}
	}
}

size_t Table::size_of()
{
	size_t size = 0;
	for (size_t i = 0; i < _numb; i++)
	{
		size += _msize(mat[i]) + sizeof(mat[i]);
	}
	return   sizeof(mat) + size;
}

std::ostream& operator<< (std::ostream& out, const Table& table)
{
	for (size_t i = 0; i < table._numb; i++)
	{
		out << std::endl;
		for (size_t j = 0; j < table._numb; j++)
		{
			out << ' ' << table.mat[i][j];
		}
	}
	return out;
}

size_t Table::numb_of_conf()
{
	size_t row;
	size_t col;
	size_t numb_of_conf = 0;

	int ind1;
	int ind2;

	for (size_t i = 0; i < _numb; i++)
	{
		row = i;
		col = find(i);

		for (size_t i = row + 1; i < _numb; i++)
		{
			if (mat[i][col] == 'Q')
			{
				numb_of_conf++;
			}
		}

		ind1 = row + 1;
		ind2 = col + 1;
		while (ind1 < _numb && ind2 < _numb)
		{
			if (mat[ind1][ind2] == 'Q')
			{
				numb_of_conf++ ;
			}
			ind1 += 1;
			ind2 += 1;
		}

		ind1 = row + 1;
		ind2 = col - 1;
		while (ind1 < _numb && ind2 >= 0)
		{
			if (mat[ind1][ind2] == 'Q')
			{
				numb_of_conf++;
			}
			ind1 += 1;
			ind2 -= 1;
		}
	}

	return numb_of_conf;
}

Table& Table::operator = (const Table& table)
{
	if (this != &table)
	{
		if (this == NULL)
		{
			*this = Table(table);
		}
		else if (this->is_init() && _numb == table._numb)
		{
			this->copy(table);
		}
		else 
		{
			for (size_t i = 0; i < _numb; i++) delete[] mat[i];
			delete[] mat;

			_numb = table._numb;
			mat = new char* [_numb];

			for (size_t i = 0; i < _numb; i++)
			{
				mat[i] = new char[_numb];
				for (size_t j = 0; j < _numb; j++)
				{
					for (size_t j = 0; j < _numb; j++) mat[i][j] = table.mat[i][j];
				}
			}
		}	
	}
	return *this;
}