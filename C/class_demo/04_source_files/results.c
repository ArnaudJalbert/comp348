#include <stdio.h>

// source files often include their own header file
#include "results.h"

#define TAX 0.15

// try a couple fo things here
// 1] remove the static qualifier on the prototype
// 2] put this prototype in the results.h header file

int get_item_count()
{

	int count;
	printf("\nEnter item count: ");
	scanf("%d", &count); // scanf defined in stdio.h

	return count;
}

double calculate_total(int count)
{

	double result = (get_one() + TAX) * count;

	return result;
}

// remove the prototype above and see what happens
static double get_one()
{
	return 1.0;
}
