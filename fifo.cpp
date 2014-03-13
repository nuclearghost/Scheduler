#include "fifo.h"

void Fifo::schedule(){
	while (jobs.size() > 0){
		Request head = jobs.front();
		if (head.size <= resources.size()){
			std::queue<Request> _resources;
			for (unsigned long i = 0; i < head.size; i++){
				_resources.push(resources.front());
				resources.pop();
			}
			jobs.pop();
			printSchedule(head, _resources);
		} else {
			break;
		}
	}	
}
