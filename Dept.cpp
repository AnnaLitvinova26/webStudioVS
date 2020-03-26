#include "pch.h"
#include "Dept.h"
#include <iostream>

Dept::Dept(Dept* next) {
	_next = next;
	countW = 0;
}

std::vector <Worker> Dept::getWorkers() {
	return workers;
}

void Dept::addWorker(Worker worker) {
	workers.push_back(worker);

}

void Dept::AddTask(Task* task) {
	workers[countW % workers.size()].AddTask(task);
	countW++;
}

bool Dept::Process() {
	for (int i = 0; i < workers.size(); i++) {
		if (workers[i].HaveWork()) {
			workers[i].Process();
			/*if (task != 0 && _next != 0) {
				_next->AddTask(task);
			}*/
		}
	}
}
bool Dept::HaveWork() {
	for (int i = 0; i < workers.size(); i++) {
		if (workers[i].HaveWork()) {
			return true;
		}
	}
	return false;
}

void Dept::onWorkReady(Task* task, Worker* worker) {

}
