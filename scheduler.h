
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <iostream>

#include "request.h"

class Scheduler {
	protected:
		std::queue<Request> jobs;
		std::queue<Request> resources;

		void printSchedule(Request _job, std::queue<Request> _resources){
			std::cout << "Scheduled job for " << _job.size << " resources: ";
			double resourceAvailability = 0;
			while (!_resources.empty()) {
				std::cout << _resources.front().size << ", ";
				resourceAvailability += waitTime(_resources.front());
				_resources.pop();
			}
			std::cout << " job wait time: " << waitTime(_job);
			std::cout << " . Resource available time: " << resourceAvailability;
			std::cout << std::endl;
		}

		double waitTime(Request req){
			std::chrono::high_resolution_clock::time_point current = 
				std::chrono::high_resolution_clock::now(); 
			std::chrono::duration<double> time_span = 
				std::chrono::duration_cast< std::chrono::duration<double> > 
					(current - req.insert);	
				return time_span.count();
		}

		virtual void schedule() = 0;
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
};

#endif //SCHEDULER_H
