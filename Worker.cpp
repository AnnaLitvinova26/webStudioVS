#include "pch.h"
#include "Worker.h"

#include <iostream>
void Worker::AddTask(Task* task) {
	tasks.push_back(task);
}

void Worker::Process() {
	int x = rand() % 100;
	Task* result;
	if (x <= 80) {
		result = tasks[0];
		tasks.erase(tasks.begin());
	}
	else {
		result = 0;
	}
	for (auto l : listeners) {
		//l->onWorkReady(result, );
	}
}
bool Worker::HaveWork() {
	if (tasks.size() != 0) {
		return true;
	}
	else false;
}
void Worker::deleteTask() {
	tasks.erase(tasks.begin());
}

std::string Worker::getWorker() {
	std::string s;

	for (int i = 0; i < tasks.size(); i++) {
		s += tasks[i]->getTask() + " ";
	}
	return _surname + " " + _name + " " + s;
}

void Worker::addListener(Listener* listener) {
	listeners.push_back(listener);
}