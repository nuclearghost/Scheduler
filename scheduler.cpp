
#include "scheduler.h"

void Scheduler::printSchedule(Request _job, std::queue<Request> _resources){
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

void Scheduler::addJob(unsigned long job) {
	jobs.push(Request(job));
	schedule();
}

double Scheduler::waitTime(Request req){
	std::chrono::high_resolution_clock::time_point current = 
		std::chrono::high_resolution_clock::now(); 
	std::chrono::duration<double> time_span = 
		std::chrono::duration_cast< std::chrono::duration<double> > 
			(current - req.insert);	
		return time_span.count();
}
