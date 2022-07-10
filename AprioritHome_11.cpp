// AprioritHome_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Worker {
    int id;
    int salary;
	Worker* next;
};

int main()
{
	srand(time(0));
	const int workersSize = 20;
	const int minSalary = 9000;
	const int maxSalary = 45000;

	Worker* head = nullptr;
	Worker* tail = nullptr;
	for (int i = 0; i < workersSize; i++)
	{
		Worker* worker = new Worker;
		worker->id = i + 1;
		worker->salary = minSalary + rand() % (maxSalary - minSalary + 1);
		if (i == 0)
		{
			head = worker;
		}

		if (tail != nullptr)
		{
			tail->next = worker;
		}

		tail = worker;
	}

	// Worker's print
	for (Worker* cur = head; cur != nullptr; cur = cur->next)
	{
		std::cout << cur->id << "\t" << cur->salary << "\n";
	}
}

