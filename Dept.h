#ifndef __DEPT_INCLUDED
#define __DEPT_INCLUDED

#include <vector>

#include "Worker.h"

class Dept :public Listener {
public:
	Dept(Dept* next);
	std::vector <Worker*> getWorkers();
	void addWorker(Worker* worker);

	void addTask(Task* task);
	void process();
	bool haveWork();
	void setBoss(Worker* worker);

	void onWorkReady(Task* task, Worker* worker) override;

private:
	std::vector <Worker*> workers;
	Worker* boss;

	Dept* _next;

	int countW;
};

#endif

