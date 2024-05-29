#include <cstdio>
// #include "Observer.h"
#include "Net.h"

int main(int argc, char** argv) {
	// Observer ob();
	Net n;
	// n.setLevel(HIGH);
	int level = 22;
	level = n.getLevel();
	printf("hello world! %d\n", level);
	return 0;
}

