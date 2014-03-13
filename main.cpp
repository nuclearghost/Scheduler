
#include <iostream>
#include "fifo.h"

int main(int argc, char **argv){
	Fifo *f = new Fifo();
	f->addResource(1);
	f->addResource(3);
	f->addResource(1);
	f->addJob(2);
	f->addJob(1);
	return 0;
}
