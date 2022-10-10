#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_sizes();
void show_arrays();
void show_structs();
void show_memory();
void show_strings();

int main(void)
{

	// show_sizes();
	// show_arrays();
	// show_structs();
	// show_memory();
	show_strings();

	return EXIT_SUCCESS;
}

void show_sizes()
{

	printf("\n** Type output:\n");

	// use sizeof to see the size used by type in memory
	printf(" char size: %d\n", (int)sizeof(char));
	printf(" short int size: %d\n", (int)sizeof(short int));
	printf(" int size: %d\n", (int)sizeof(int));
	printf(" long int size: %d\n", (int)sizeof(long int));
	printf(" long long int size: %d\n", (int)sizeof(long long int));

	printf(" float size: %d\n", (int)sizeof(float));
	printf(" double size: %d\n", (int)sizeof(double));
	printf(" long double size: %d\n", (int)sizeof(long double));

	int foo;
	printf(" foo(variable) size: %d\n", (int)sizeof foo);
	printf("\n");
}

void show_arrays()
{

	printf("\n** Array output:\n");

	// automatic allocation here, adds to the stack
	int foo[4];
	foo[1] = 99;
	printf(" foo[1]: %d\n", foo[1]);
	printf(" foo[2]: %d\n", foo[2]);

	float bar[6][10];
	bar[4][2] = 77.6;
	printf(" bar[4][2]: %f\n", bar[4][2]);

	// no bounds checking
	printf(" bar[99][4]: %f\n", bar[99][7]);

	printf(" sizeof foo array: %d\n", (int)sizeof foo);
	printf(" number of elements: %d\n", (int)(sizeof foo / sizeof foo[0]));
	printf("\n");
}

void show_structs()
{

	printf("\n** struct output:\n");

	// this is a type definition
	struct foo
	{
		int x;
		double y;
	};

	struct foo woohoo; // woohoo is a variable of type struct foo

	// similar to oop, can access the different variable in the struct
	woohoo.x = 99;
	woohoo.y = 99.99;

	printf(" woohoo.x: %d\n", woohoo.x);
	printf(" woohoo.y: %f\n", woohoo.y);

	// note the size of the struct
	printf(" sizeof woohoo: %d\n", (int)sizeof woohoo);
  	printf("\n");
}

void show_memory()
{
	int *intBuf = (int *)malloc(10 * sizeof(int));

	int count;

	// add values to array
	for (count = 0; count < 10; count++)
	{
		intBuf[count] = count;
	}

	// print array
	printf("\n");
	for (count = 0; count < 10; count++)
	{
		printf("intBuf[%d]: %d\n", count, intBuf[count]);
	}

	// make a copy of the pointer
	int *tmp = intBuf;

	// print array
	printf("\n");
	for (count = 0; count < 10; count++)
	{
		printf("array pointer[%d]: %p\n", count, tmp);
		printf("array value[%d]: %d\n", count, *tmp);
		tmp++;
	}

	// what does this do?
	long int intPtr = (long int)intBuf + sizeof(int) + 2;
	int *ptr = (int *)intPtr;
	*ptr = 1111;

	printf("\n");
	for (count = 0; count < 10; count++)
	{
		printf("intBuf[%d]: %d\n", count, intBuf[count]);
	}

	// some pointer copies
	int *original = intBuf;

	// remove comment to make a copy
	// int *original2 = intBuf;

	// what does this do
	intBuf += 5;

	printf("\n");
	for (count = 0; count < 10; count++)
	{
		printf("intBuf[%d]: %d\n", count, intBuf[count]);
	}

	// what happens with these de-allocation instances
	// free(intBuf);
	free(original);
	// free(original2);
}

void show_strings()
{

	// start with a 3-char array, plus teminating char
	char str1[4] = {'a', 'b', 'c', '\0'};

	// make an new string with 7 spaces
	char *str2 = (char *)malloc(7);

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);

	// write something to str2
	str2 = strcpy(str2, str1);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);

	// write again
	str2 = strcat(str2, str1);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);

	// ...and again
	str2 = strcat(str2, str1);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);

	// let's put some stuff at the end of the string
	char i;
	for (i = 9; i < 20; i++)
	{
		str2[(int)i] = i;
	}

	printf("final str1: %s\n", str1);
	printf("final str2: %s\n", str2);
}
