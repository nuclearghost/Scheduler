
#include <iostream>
#include <unistd.h>

#include "fifo.h"
#include "wpqs.h"

int main(int argc, char **argv){
	Fifo f;
	f.addJob(2);
	f.addJob(9);
	f.addJob(1);
	f.addResource(1);
	f.addResource(3);
	f.addResource(1);

	Wpqs w;
	w.addJob(2);
	w.addJob(9);
	usleep(10000);
	w.addJob(1);
	w.addResource(1);
	w.addResource(3);
	w.addResource(1);
	return 0;
}
