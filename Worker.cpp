#include "pch.h"
#include "Worker.h"

#include <iostream>

Worker::Worker(std::string surname, std::string name) {
	_surname = surname;
	_name = name;
	score = 0;
}

void Worker::addTask(Task* task) {
	tasks.push_back(task);
}

void Worker::process() {
	int x = rand() % 100;
	Task* result = tasks[0];
	if (x <= 80) {
		result->setDone(true);
		tasks.erase(tasks.begin());
	}
	else {
		result->setDone(false);
	}
	for (auto l : listeners) {
		l->onWorkReady(result, this);		
	}
}
bool Worker::haveWork() {
	if (tasks.size() != 0) {
		return true;
	}
	else return false;
}
void Worker::deleteTask() {
	tasks.erase(tasks.begin());
}

void Worker::setScore(int sc) {
	score += sc;
}

std::string Worker::getWorker() {
	std::string s;

	for (int i = 0; i < tasks.size(); i++) {
		s += tasks[i]->getTask() + " ";
	}
	return _surname + '\t' + _name + '\t' + s + '\t' + std::to_string(score);
}

void Worker::addListener(Listener* listener) {
	listeners.push_back(listener);
}