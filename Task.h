#ifndef __TASK_INCLUDED
#define __TASK_INCLUDED

#include <string>

class Task {
public:
	Task(std::string name, int level) {
		_name = name;
		_level = level;
	}
	std::string getTask();
private:
	std::string _name;
	int _level;
};

#endif