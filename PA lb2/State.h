#pragma once
#ifndef STATE_H
#define STATE_H

#include "Table.h"

/*����, ���� ����������� ���� ��� ��������� ��������� A* */
class State : public Table
{
private:
	size_t _path_len;		//������� �����(������� ��������� �����)
	size_t _numb_of_conf;	//������� ��������

public:
	State(Table& table, size_t len = 0) :Table(table)
	{
		_path_len = len;
		_numb_of_conf = table.numb_of_conf();
	};

	State(State* state): Table(state)
	{
		_path_len = state->path_len();
		_numb_of_conf = state->numb_of_conf();
	}

	State(const State& state):Table(state)
	{
		this->_path_len = state._path_len;
		this->_numb_of_conf = state._numb_of_conf;
	};

	void copy(const State& state)
	{
		this->Table::copy(state);
		this->_path_len = state._path_len;
		this->_numb_of_conf = state._numb_of_conf;
	};

	bool change_pos(size_t row, size_t col )
	{ 
		bool b = this->Table::change_pos(row, col);
		this->_numb_of_conf = this->Table::numb_of_conf();
		return b;

	};

	size_t path_len(){return _path_len;};
	size_t numb_of_conf() { return 	_numb_of_conf;};
	size_t fun�_val() {return _path_len + _numb_of_conf;}
	size_t size_of() { return this->size_of() + sizeof(size_t) * 2; };
	
};

#endif