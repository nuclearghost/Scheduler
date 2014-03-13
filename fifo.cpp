#include "fifo.h"

void Fifo::addJob(int job){
	jobs.push(job);
	schedule();
}

void Fifo::addResource(int resource){
	resources.push(resource);
	schedule();
}

void Fifo::schedule(){
	while (jobs.size() > 0){
		int head = jobs.front();
		if (head <= resources.size()){
			std::cout << "Scheduled job for " << head << " resources: ";
			for (int i = 0; i < head; i++){
				int resource = resources.front();
				std::cout << resource << ", ";
				resources.pop();
			}
			std::cout << std::endl;
			jobs.pop();
		} else {
			break;
		}
	}	
}
