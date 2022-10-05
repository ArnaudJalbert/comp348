// header inclusion
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
 * stdio.h: printf()
 * time.h: time()
 * stdlib.h: rand()
 */



// simple constants
#define LOOP 10
#define RANGE 100


int main(void) {

	int i;
	time_t t; // time data type required by time functions


	// Initializes random number generator  with current time
	// comment this line to see what happens without it
	srand((unsigned) time(&t));


	/* Print LOOP random numbers from 0 to RANGE - 1 */
	for( i = 0 ; i < LOOP ; i++ ) {
		printf("%d\n", rand() % RANGE);
	}

	return 0;
}
