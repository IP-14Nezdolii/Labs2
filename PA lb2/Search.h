#pragma once
#include "Table.h"
#include "State.h"
#include "Queue.h"
#include <List>

void nQueen_BFS(Table& tbl)
{
	//Змінні, необхідні для тестування
	size_t numb_of_iter = 0;
	size_t numb_of_gen_states = 0;
	size_t numb_of_states = 0;
	//

	Table table1(tbl);
	Table table2(tbl);

	std::list<Table> lst;
	lst.push_back(table1);

	size_t size = table1.size_of()*2 + sizeof(lst);
	size_t numb_of_elems = 1;

	size_t numb = table1.numb();

	if (table1.numb_of_conf() == 0) return;

	while (numb_of_elems * size <= size_t(1024) * 1024 * 1024)
	{
		//
		numb_of_iter++;
		//

		table2.copy(lst.front());
		lst.pop_front();

		for (size_t i = 0; i < numb; i++)
		{
			for (size_t j = 0; j < numb; j++)
			{
				table1.copy(table2);
				if (table1.change_pos(i, j))
				{
					//
					numb_of_gen_states++;
					//
					if (table1.numb_of_conf() == 0)
					{
						//
						numb_of_states = lst.size();
						std::cout << std::endl << "numb of iterations: " << numb_of_iter;
						std::cout << std::endl << "numb of gen states: " << numb_of_gen_states;
						std::cout << std::endl << "numb of states: " << numb_of_states;
						//
						tbl.copy(table1);
						return;
					}
					lst.push_back(table1);
					numb_of_elems++;
				}
			}
		}
	}
	tbl.copy(table1);
	//
	numb_of_states = lst.size();
	std::cout << std::endl << "numb of iterations: " << numb_of_iter;
	std::cout << std::endl << "numb of gen states: " << numb_of_gen_states;
	std::cout << std::endl << "numb of states: " << numb_of_states;
	//
}

void nQueen_A_star(Table& tbl)
{
	//Змінні, необхідні для тестування
	size_t numb_of_iter = 0;
	size_t numb_of_gen_states = 0;
	size_t numb_of_states = 0;
	//

	State state1(tbl);
	State state2(tbl);
	Queue queue(__int64(1024) * 1024 * 1024);
	size_t numb = state1.numb();

	if (state1.numb_of_conf() == 0) return;

	queue.push(state1);
	while (queue.size() < queue.max_size()) 
	{
		//
		numb_of_iter++;
		//

		state2.copy(queue.front());
		queue.pop();

		for (size_t i = 0; i < numb; i++)
		{			
			for (size_t j = 0; j < numb; j++)
			{
				state1.copy(state2);
				if (state1.change_pos(i, j))
				{
					//
					numb_of_gen_states++;
					//
					if (state1.numb_of_conf() == 0)
					{
						//
						numb_of_states = queue.size();
						std::cout << std::endl << "numb of iterations: " << numb_of_iter;
						std::cout << std::endl << "numb of gen states: " << numb_of_gen_states;
						std::cout << std::endl << "numb of states: " << numb_of_states;
						//
						tbl.copy(state1);
						return;
					}
					queue.push(State(state1, state1.path_len()+1));
				}
			}
		}
	}
	tbl.copy(state1);
	//
	numb_of_states = queue.size();
	std::cout << std::endl << "numb of iterations: " << numb_of_iter;
	std::cout << std::endl << "numb of gen states: " << numb_of_gen_states;
	std::cout << std::endl << "numb of states: " << numb_of_states;
	//
}