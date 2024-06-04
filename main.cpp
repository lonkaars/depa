#include <cstdio>
// #include "Observer.h"
#include "Net.h"
#include "Gate.h"

int main(int argc, char** argv) {
	// Observer ob();
	Net n;
	Gate *g = new GateAnd;
	g->addInput(&n);
	n.setLevel(HIGH);
	int level = 22;
	level = n.getLevel();
	printf("hello world! %d\n", level);
	return 0;
}

