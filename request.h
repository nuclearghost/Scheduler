
#ifndef REQUEST_H
#define REQUEST_H

#include <queue>
#include <chrono>

class Request {
public:
	int size;
	high_resolution_clock::time_point insert;
	Request(int _size){
		size = _size;
		insert = high_resolution_clock::now();
	}

};

#endif //SCHEDULER_H
