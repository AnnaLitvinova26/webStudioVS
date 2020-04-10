#ifndef __WORKER_INCLUDED
#define __WORKER_INCLUDED


#include <string>
#include <vector>

#include "Task.h"
#include "Listener.h"

class Worker {
public:
	Worker(std::string surname, std::string name);
	void addTask(Task* task);
	void process();
	bool haveWork();
	void deleteTask();
	void setScore(int sc);

	std::string getWorker();
	void addListener(Listener* listener);

private:
	std::string _surname;
	std::string _name;
	int score;
	std::vector <Task*> tasks;
	std::vector <Listener*> listeners;
};

#endif