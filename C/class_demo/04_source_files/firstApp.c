
#include <stdio.h>
#include <stdlib.h>

// comment the line below, with warnings enabled
#include "results.h"

int main(void)
{

	// if results.h is not included, what happens
	int count = get_item_count();
	double total = calculate_total(count);

	printf("\n\n*** Sales Report ***\n\n");
	printf("Cost: $1.00 per item\n");

	// what happens to total the result.s h is not included
	printf("%d items purchased, total: $%.2f\n\n", count, total);

	return 0;
}