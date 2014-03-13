#Scheduler

##Files
* fifo.{h, cpp} - first in first out scheduling
* main.cpp - program entry point
* makefile - defition for compiling on OSX 10.9 with c++11
* request.h - object definition for job request and resource offers
* scheduler.{h, cpp} - base clase for creating schedulers
* wpqs.{h, cpp}, - weighted priority queue scheduler

##To Run
* make
* ./tester

This was only tested on OSX 10.9 using clang++ and the c++11 libraries

##File explanations

###main.cpp
This file serves as the entry point to the program. It instantiates an instance of both scheudlers and inserts some job requests and resources. 
The next step would be to create two threads for generating job requests and simulating the time it might take to run a job. This could better simulate a stream of incomign requests and offers

###request.h
This file outlines a Request object which is used for both job requests and resource offers. It holds the size of the request or the resource being offered. It also tracks the time it was created so that time metrics can be taken.

###scheduler.{h, cpp}
This file is an abstract base class for schedulers. It exposes methods for adding jobs and resources. It has protected methods that its descendants can call to pretty print job schedulings. It also has a pure virtual method for scheduling which its descendants must implement. By default it has queues of Request objects for jobs and resources.

###fifo.{h, cpp}
This is a basic implementation of the fifo scheduler that was suppsoed to be the default. It uses the built in queues for jobs and resources

###wpqs.{h, cpp}
This is my implementation of a scheduler. It is supposed to use a weighted priority queue to determine who should be scheduled next. It is, unfortunately in its current state, just a priority queue based on the size of the request. This works a bit better than just a fifo queue because job starvation where small jobs are blocked by larger jobs is not possible. However if a series of small jobs come in, a large job will be blocked.  I wanted to use the amount of time waiting to create a weighted priority, but was not able to get a good result in this manner, so I just reverted to a priority queue for the time being.