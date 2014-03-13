
#ifndef WPQS_H
#define WPQS_H

#include <iostream>
#include "scheduler.h"


class Fifo : public Scheduler {
public:
	void addJob(int job);
	void addResource(int resource);
	void schedule();
};

#endif
