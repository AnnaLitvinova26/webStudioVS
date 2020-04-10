#include "pch.h"
#include "Company.h"
#include "Repo.h"
#include <iostream>

Company::Company() {
	design = getInstance()->getDesign();
	front = getInstance()->getFront();
	back = getInstance()->getBack();
}

std::vector<Worker*> Company::getWorkersDesign() {
	return design->getWorkers();
}
std::vector<Worker*> Company::getWorkersFront() {
	return front->getWorkers();
}
std::vector<Worker*> Company::getWorkersBack() {
	return back->getWorkers();
}

void Company::getWorkers() {
	for (auto w : design->getWorkers()) {
		std::cout << w->getWorker() << std::endl;
	}
	std::cout << std::endl;
	for (auto w : front->getWorkers()) {
		std::cout << w->getWorker() << std::endl;
	}
	std::cout << std::endl;
	for (auto w : back->getWorkers()) {
		std::cout << w->getWorker() << std::endl;
	}
	std::cout << std::endl;
}

void Company::addTask(Task* task) {
	design->addTask(task);
}
void Company::process() {
	back->process();
	front->process();
	design->process();
}
bool Company::haveWork() {
	return  design->haveWork() || front->haveWork() || back->haveWork();
}
