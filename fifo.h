
#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include "scheduler.h"


class Fifo : public Scheduler {
public:
	void addJob(int job);
	void addResource(int resource);
	void schedule();
};

#endif
