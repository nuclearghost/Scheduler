
#ifndef WPQS_H
#define WPQS_H

#include <chrono>
#include <queue>

#include "scheduler.h"
#include "request.h"

class priorityComparison{ 
private:
	double priority(Request req) const{
		std::chrono::high_resolution_clock::time_point current = 
			std::chrono::high_resolution_clock::now(); 
		std::chrono::duration<double> time_span = 
			std::chrono::duration_cast< std::chrono::duration<double> > 
				(current - req.insert);

		return 1 + (time_span.count() / req.size);
	}
public:
	bool operator() (const Request& lhs, const Request& rhs) const {
		//return priority(lhs) > priority(rhs);
		return lhs.size > rhs.size;
	}
};

//Weighted Priority Queue Scheduler
class Wpqs : public Scheduler {
private:
	std::priority_queue<Request, std::vector<Request>, priorityComparison> priority_jobs;
public:
	void addJob(unsigned long job);
	void schedule();
};

#endif
