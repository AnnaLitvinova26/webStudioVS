#pragma once
#ifndef __COMPANY_INCLUDED
#define __COMPANY_INCLUDED

#include "Dept.h"
#include "Task.h"


#include <queue>


/*void test(int task){
	std::queue<int> q;
	q.push(task);

	//process

	int t = q.front();
	q.pop();
}*/

class Company {
public:
	Company();

	void addTask(Task* task);
	void process();
	bool haveWork();

	void getWorkers();

	std::vector<Worker*> getWorkersDesign();
	std::vector<Worker*> getWorkersFront();
	std::vector<Worker*> getWorkersBack();
private:
	Dept* design;
	Dept* front;
	Dept* back;
};

#endif

