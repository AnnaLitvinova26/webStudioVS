#ifndef __LISTENER_INCLUDED
#define __LISTENER_INCLUDED

class Task;
class Worker;

class Listener {
public:
	virtual void onWorkReady(Task* task, Worker* worker) = 0;
};

#endif
