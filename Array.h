#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdlib.h>


#define data_type int

typedef struct
{
	data_type *array;
	size_t used;
	size_t size;
} Array_t;

void initArray(Array_t* a, size_t initialSize)
{
	a->array = malloc(initialSize* sizeof(data_type) );
	a->used = 0;
	a->size = initialSize;
}

void insertArray(Array_t* a, data_type element)
{
	if(a->used == a->size){
		a->size = (int)a->size*1.5;
		a->array = realloc(a->array, a->size * sizeof(data_type) );
	}	
	a->array[a->used++] = element;
}

void freeArray(Array_t* a)
{
	free(a->array);
	a->array = NULL;
	a->used = (a->size = 0);
}

#endif
