#include "pch.h"
#include "Dept.h"
#include <iostream>

Dept::Dept(Dept* next) {
	_next = next;
	countW = 0;
}

std::vector <Worker*> Dept::getWorkers() {
	return workers;
}

void Dept::addWorker(Worker* worker) {
	workers.push_back(worker);
	worker->addListener(this);
}

void Dept::addTask(Task* task) {
	workers[countW % workers.size()]->addTask(task);
	countW++;
}

void Dept::process() {
	for (int i = 0; i < workers.size(); i++) {
		if (workers[i]->haveWork()) {
			workers[i]->process();
		}
	}
}
bool Dept::haveWork() {
	for (int i = 0; i < workers.size(); i++) {
		if (workers[i]->haveWork()) {
			return true;
		}
	}
	return false;
}

void Dept::setBoss(Worker* worker) {
	boss = worker;
}

void Dept::onWorkReady(Task* task, Worker* worker) {
	if (worker != boss) {
		if (task->getDone() == false) {
			boss->setScore(-task->getLvl());
		}
		else {
			boss->setScore(task->getLvl());			
		}
	}

	if (task->getDone() == false) {
		worker->setScore(-task->getLvl());
	}
	else {
		worker->setScore(task->getLvl());
		if (_next != 0) {
			_next->addTask(task);
		}
	}
	
}
