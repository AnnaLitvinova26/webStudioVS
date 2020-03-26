#ifndef __TESTREPO_INCLUDED
#define __TESTREPO_INCLUDED

#include <vector>

#include "Repo.h"

class TestRepo : public Repo {
public:
	TestRepo();

	Dept* getDesign() override;
	Dept* getFront() override;
	Dept* getBack()override;
	std::vector<Task> tasks;

private:
	Dept* _design;
	Dept* _front;
	Dept* _back;
};


Repo* getInstance();

#endif  
