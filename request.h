
#ifndef REQUEST_H
#define REQUEST_H

#include <queue>
#include <chrono>

class Request {
public:
	unsigned long size;
	std::chrono::high_resolution_clock::time_point insert;
	Request(unsigned long _size){
		size = _size;
		insert = std::chrono::high_resolution_clock::now();
	}

};

#endif //SCHEDULER_H
