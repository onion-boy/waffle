#ifndef VALUE_H_
#define VALUE_H_

#include "../log.h"
#include "array.h"

typedef struct variable
{
    int id;
    int type;
    int items;
    char *name;
    void *ptr;
} Variable;

typedef struct scope
{
    int id;
    char *name;
    int variableCount;
    Array *variables;
} Scope;

Scope *create_scope();
Variable *register_value(char *name, void *value, int type, int length, Scope *scope);

void close_scope(Scope *scope);
void close_variable(Variable *var);

#endif