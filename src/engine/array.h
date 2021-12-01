#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT 0
#define FLOAT 1
#define BOOL 2
#define CHAR 3
#define ANY 4

typedef struct array
{
    int length;
    int type;
    void **values;
} Array;

int map_type(int type, int items);

Array *create_array(int type);
void push_to_array(Array *array, void *item);

void close_array(Array *array, void (*close)(void *));

#endif