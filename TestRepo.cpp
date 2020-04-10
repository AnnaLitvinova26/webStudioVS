#include "pch.h"
#include "TestRepo.h"


TestRepo::TestRepo() {
	_back = new Dept(0);
	_front = new Dept(_back);
	_design = new Dept(_front);

	std::string surname;
	std::string name;

	int i = 0;
	for (; i < 5; i++) {
		std::string s = std::to_string(i + 1);
		surname = "Ivanov" + s + " ";
		name = "Ivan" + s;
		_design->addWorker(new Worker(surname, name));
	}
	_design->setBoss(_design->getWorkers()[0]);

	for (; i < 10; i++) {
		std::string s = std::to_string(i + 1);
		surname = "Ivanov" + s + " ";
		name = "Ivan" + s;
		_front->addWorker(new Worker(surname, name));
	}
	_front->setBoss(_front->getWorkers()[0]);

	for (; i < 15; i++) {
		std::string s = std::to_string(i + 1);
		surname = "Ivanov" + s;
		name = "Ivan" + s;
		_back->addWorker(new Worker(surname, name));
	}
	_back->setBoss(_back->getWorkers()[0]);
}

Dept* TestRepo::getDesign() {
	return _design;
}
Dept* TestRepo::getFront() {
	return _front;
}
Dept* TestRepo::getBack() {
	return _back;
}

Repo* getInstance() {
	static Repo* _instance = 0;
	if (_instance == 0) {
		_instance = new TestRepo();
	}
	return _instance;
}