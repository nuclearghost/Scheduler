
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <request.h>

class Scheduler {
	protected:
		std::queue<int> jobs;
		std::queue<int> resources;

	public:
		virtual ~Scheduler(){

		}
		virtual void addJob(int job) = 0;

		virtual void addResource(int resource) = 0;

		virtual void schedule() = 0;
};

#endif //SCHEDULER_H
