#ifndef __DEPT_INCLUDED
#define __DEPT_INCLUDED

#include <vector>

#include "Worker.h"

class Dept :public Listener {
public:
	Dept(Dept* next);
	std::vector <Worker> getWorkers();
	void addWorker(Worker worker);

	void AddTask(Task* task);
	bool Process();
	bool HaveWork();

	void onWorkReady(Task* task, Worker* worker);

private:
	std::vector <Worker> workers;
	Worker* boss;

	Dept* _next;

	int countW;
};

#endif

