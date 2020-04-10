#ifndef __TASK_INCLUDED
#define __TASK_INCLUDED

#include <string>

class Task {
public:
	Task(std::string name, int level);
	std::string getTask();
	int getLvl();
	void setDone(bool value);
	bool getDone();
private:
	std::string _name;
	int _level;
	bool done;
};

#endif