#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "State.h"

/*клас, який представляє чергу з пріоритетом для реалізації алгоритму A* */
class Queue
{
private:
	size_t _real_size;
	size_t _max_size;
	size_t _size;
	State* arr;

	void _realloc()
	{
		_real_size += size_t(1024) * 1024 * 16 / sizeof(State);
		State* new_arr = (State*)realloc(arr, _real_size);

		if (new_arr == NULL)
		{
			std::cout << std::endl << "memory allocation error";
			exit(1);
		}
		else 
		{
			free(arr);
			arr = new_arr;
		}
	}

public:
	Queue(__int64 size)
	{
		_max_size = size / sizeof(State);
		_real_size = size_t(1024) * 1024 * 16 / sizeof(State);
		_size = 0;

		arr = (State*)malloc(_real_size * sizeof(State));

		if (arr == NULL) 
		{
			std::cout << std::endl<<"memory allocation error";
			exit(1);
		}
	};

	~Queue() { free(arr); };

	void push(State state)
	{
		if (_size < _max_size)
		{
			if (_size == _real_size) _realloc();

			if (_size == 0 || (arr[_size - 1].funс_val() < state.funс_val()))
			{
				arr[_size] = state;
			}
			else
			{
				for (size_t i = 0; i < _size; i++)
				{
					if (arr[i].funс_val() >= state.funс_val())
					{
						for (size_t j = _size; j > i; j--)
						{
							arr[j] = arr[j - 1];
						}
						arr[i] = state;
						break;
					}
					else if (i == _size - 1)
					{
						arr[i] = state;
					}
				}
			}
			_size++;
		}
	}

	void pop()
	{
		if (_size > 0)
		{
			for (size_t i = 1; i < _size; i++)
			{
				arr[i - 1].copy(arr[i]);
			}
			_size--;
		}

	};

	size_t size() { return _size; };
	size_t max_size() { return _max_size; };
	State& front() { return arr[0]; };
};

#endif

/*
class Queue
{
private:
	size_t _max_size;
	size_t _size;
	State* arr;

public:
	Queue(__int64 size)
	{
		_max_size = size / sizeof(State);
		_size = 0;

		try
		{
			arr = (State*)malloc(_max_size * sizeof(State));
		}
		catch (const std::exception&)
		{
			printf("memory allocation error");
			exit(1);
		}

	};

	~Queue() { free(arr); };

	void push(State state)
	{
		if (_size < _max_size)
		{
			if (_size == 0)
			{
				if (arr[0].is_init()) arr[0].copy(state);
				else arr[0] = state;
			}
			else if (arr[_size-1].funс_val() < state.funс_val())
			{
				arr[_size] = state;
			}
			else
			{
				for (size_t i = 0; i < _size; i++)
				{
					if (arr[i].funс_val() >= state.funс_val())
					{
						for (size_t j = _size; j > i; j--)
						{
							arr[j] = arr[j - 1];
						}
						arr[i] = state;
						break;
					}
					else if (i == _size - 1)
					{
						if (arr[i].is_init()) arr[0].copy(state);
						else arr[i] = state;
					}
				}
			}
			_size++;
		}
	}

	void pop()
	{
		if (_size > 0)
		{
			for (size_t i = 1; i < _size; i++)
			{
				arr[i - 1].copy(arr[i]);
			}
			_size--;
		}

	};

	size_t size() { return _size; };
	size_t max_size() { return _max_size; };
	State& front() { return arr[0]; };
};
*/
/*
	
struct MyLst
{
	MyLst* _prev = NULL;
	MyLst* _next = NULL;
	State* _state = NULL;

	void free()
	{
		MyLst* cur = NULL;
		delete this->_state;
		cur = this->_next->_next;

		while (cur->_next != NULL)
		{
			delete cur->_prev;
			delete cur->_state;
			cur = cur->_next;
		}

		delete cur->_prev;
		delete cur->_state;

		delete cur;
	}

	void push(State state)
	{
		MyLst* cur = this;

		if (this->_state == NULL)
		{
			this->_state = new State(state);
		}
		else
		{
			while (true)
			{
				if (cur->_state->funс_val() >= state.funс_val())
				{
					if (cur->_prev == NULL)
					{
						cur = this->_next;
						this->_next = new MyLst;
						this->_next->_prev = this;
						this->_next->_state = this->_state;
						this->_state = new State(state);

						if (this->_next != NULL)
						{
							this->_next->_next = cur;
						}
					}
					else
					{
						cur->_prev->_next = new MyLst;
						cur->_prev->_next->_next = cur;
						cur->_prev = cur->_prev->_next;
						cur->_prev->_state = new State(state);
					}
					return;
				}
				else if (cur->_next == NULL)
				{
					cur->_next = new MyLst;
					cur->_next->_prev = cur;
					cur->_next->_state = new State(state);
					return;
				}
				cur = cur->_next;
			}
		}
	}

	void pop()
	{
		if (_next == NULL)
		{
			delete _state;
			_state = NULL;
		}
		else
		{
			MyLst* cur = this->_next->_next;
			this->_state = this->_next->_state;
			delete this->_next;
			this->_next = cur;
			cur->_prev = this;
		}
	};
};

class Queue
{
private:
	size_t _max_size = 1;
	size_t _size = 0;

	MyLst lst;

public:
	Queue(size_t _size) {};

	~Queue() { lst.free(); };

	bool push(State state)
	{
		lst.push(state);
		return true;
	}

	void pop() { lst.pop(); };

	size_t size() { return _size; };
	size_t max_size() { return _max_size; };
	State front() { return lst._state; };
};

*/