#include "array.h"

int map_type(int type, int items)
{
    int size;
    switch (type)
    {
    case INT:
        size = sizeof(int);

    case FLOAT:
        size = sizeof(float);

    case CHAR:
        return sizeof(char) * (items + 1);

    case BOOL:
        size = sizeof(bool);

    default:
        size = type;
    }

    return size * items;
}

Array *create_array(int type)
{
    Array *array = malloc(sizeof(*array));

    array->type = type;
    array->length = 0;
    array->values = malloc(0);
    return array;
}

void push_to_array(Array *array, void *item)
{
    // if (item->type != array->type && array->type != ANY)
    // TODO throw error
    int last = array->length, bytes = map_type(array->type, ++array->length);
    array->values = realloc(array->values, bytes);
    array->values[last] = item;
}

void close_array(Array *array, void (*close)(void *))
{
    for (int i = 0; i < array->length; ++i)
    {
        close(array->values[i]);
    }
    free(array->values);
    free(array);
}