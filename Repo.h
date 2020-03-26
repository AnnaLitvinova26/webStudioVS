#ifndef __REPO_INCLUDED
#define __REPO_INCLUDED

#include "Company.h"

class Repo {
public:
	virtual Dept* getDesign() = 0;
	virtual Dept* getFront() = 0;
	virtual Dept* getBack() = 0;
private:
	static Repo* _instance;
};


Repo* getInstance();


#endif

