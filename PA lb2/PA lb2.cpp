#include <iostream>
#include <ctime>
#include "Table.h"
#include "Search.h"

int main()
{
	unsigned int start_time;
	unsigned int end_time;
	Table table(8);

	std::cout << std::endl << std::endl << "BFS: ";
	table.gen_table();
	std::cout << std::endl << table;
	std::cout << std::endl << "numb of conflicts: " << table.numb_of_conf();
	start_time = clock();
	nQueen_BFS(table);
	end_time = clock();
	std::cout << std::endl << table;
	std::cout << std::endl << "time: " << float(end_time - start_time) / (60000);
	std::cout << std::endl << "numb of conflicts: " << table.numb_of_conf();
	
	std::cout << std::endl << std::endl << "A*: ";
	table.gen_table();
	std::cout << std::endl << table;
	std::cout << std::endl << "numb of conflicts: " << table.numb_of_conf();
	start_time = clock();
	nQueen_A_star(table);
	end_time = clock();
	std::cout << std::endl << table;
	std::cout << std::endl << "time: " << float(end_time - start_time) / (60000);
	std::cout << std::endl << "numb of conflicts: " << table.numb_of_conf();
	
	getchar();
}
