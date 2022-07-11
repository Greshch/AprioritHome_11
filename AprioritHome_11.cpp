// AprioritHome_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Worker {
    int id;
    int salary;
	Worker* next = nullptr;
};

int main()
{
	srand(time(0));
	const int workersSize = 20;
	const int minSalary = 9000;
	const int maxSalary = 45000;
	const int trickSalary = 30000;
	Worker* head = nullptr;
	Worker* tail = nullptr;
	// Fill work list by 20 workers
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
	for (Worker* cur = head; cur!= nullptr; cur = cur->next)
	{
		std::cout << cur->id << "\t" << cur->salary << "\n";
	}

	// Remove workers with too big salary

	int dismised = 0;
	for (Worker* cur = head; cur != nullptr; cur = cur->next)
	{
		if (cur->salary > trickSalary)
		{
			cur->salary = 0;
			++dismised;
		}
	}

	std::cout << "\n";
	std::cout << "dismised : " << dismised << "\n";
	std::cout << "\n";
	std::cout << "\n";

	for (int i = 0; i < dismised; i++)
	{
		for (Worker* cur = head; cur != nullptr; cur = cur->next)
		{
			if (cur->next != nullptr && cur->salary == 0)
			{
				Worker* next = cur->next;
				int tmpId = cur->id;
				cur->id = next->id;
				next->id = tmpId;

				int tmpSalary = cur->salary;
				cur->salary = next->salary;
				next->salary = tmpSalary;
			}
		}
	}

	// Worker's print
	for (Worker* cur = head; cur != nullptr; cur = cur->next)
	{
		std::cout << cur->id << "\t" << cur->salary << "\n";
	}
}

