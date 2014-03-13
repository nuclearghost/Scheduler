
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <iostream>

#include "request.h"

class Scheduler {
	protected:
		std::queue<Request> jobs;
		std::queue<Request> resources;

	public:
		virtual ~Scheduler(){

		}
		virtual void addJob(int job) {
			jobs.push(Request(job));
			schedule();
		}

		void addResource(int resource) {
			resources.push(Request(resource));
			schedule();
		}

		void printSchedule(Request _job, std::queue<Request> _resources){
			std::cout << "Scheduled job for " << _job.size << " resources: ";
			while (!_resources.empty()) {
				std::cout << _resources.front().size << ", ";
				_resources.pop();
			}
			std::cout << std::endl;
		}

		virtual void schedule() = 0;
};

#endif //SCHEDULER_H
