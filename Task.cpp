#include "pch.h"
#include "Task.h"

Task::Task(std::string name, int level) {
	_name = name;
	_level = level;
}

std::string Task::getTask() {
	return _name;
}

int Task::getLvl() {
	return _level;
}

void Task::setDone(bool value) {
	done = value;
}

bool Task::getDone() {
	return done;
}