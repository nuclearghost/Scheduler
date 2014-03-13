#include "wpqs.h"
#include <iostream>

void Wpqs::addJob(unsigned long job){
	priority_jobs.push(job);
}

void Wpqs::schedule(){
	while (priority_jobs.size() > 0){
		Request head = priority_jobs.top();
		if (head.size <= resources.size()){
			std::queue<Request> _resources;
			for (unsigned long i = 0; i < head.size; i++){
				_resources.push(resources.front());
				resources.pop();
			}
			priority_jobs.pop();
			printSchedule(head, _resources);
		} else {
			break;
		}
	}	
}
