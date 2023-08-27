#include "Array.h"
#include <stdio.h>

int main()
{
	Array_t test;
	initArray(&test, 5);
	for(int i = 0; i < 100; i++){
		insertArray(&test, i);
	}
	printf("%d\n", test.array[9]);
	printf("%ld\n", test.used);
	freeArray(&test);

	return 0;
}
