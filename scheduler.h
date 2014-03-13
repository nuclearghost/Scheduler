
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <iostream>

#include "request.h"

class Scheduler {
	protected:
		std::queue<Request> jobs;
		std::queue<Request> resources;

		void printSchedule(Request _job, std::queue<Request> _resources);

		double waitTime(Request req);

		virtual void schedule() = 0;
	public:
		virtual ~Scheduler(){

		}
		virtual void addJob(unsigned long job);

		void addResource(unsigned long resource) {
			resources.push(Request(resource));
			schedule();
		}
};

#endif //SCHEDULER_H
