#include "pch.h"
#include "Company.h"
#include "Repo.h"
#include <iostream>

Company::Company() {
	design = getInstance()->getDesign();
	front = getInstance()->getFront();
	back = getInstance()->getBack();
}

std::vector<Worker> Company::getWorkersDesign() {
	return design->getWorkers();
}
std::vector<Worker> Company::getWorkersFront() {
	return front->getWorkers();
}
std::vector<Worker> Company::getWorkersBack() {
	return back->getWorkers();
}

void Company::getWorkers() {
	for (auto w : design->getWorkers()) {
		std::cout << w.getWorker() << std::endl;
	}
	std::cout << std::endl;
	for (auto w : front->getWorkers()) {
		std::cout << w.getWorker() << std::endl;
	}
	std::cout << std::endl;
	for (auto w : back->getWorkers()) {
		std::cout << w.getWorker() << std::endl;
	}
	std::cout << std::endl;
}

void Company::AddTask(Task* task) {
	design->AddTask(task);
}
void Company::Process() {
	back->Process();
	front->Process();
	design->Process();
}
bool Company::HaveWork() {
	return  design->HaveWork() || front->HaveWork() || back->HaveWork();
}
