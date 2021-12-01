#include "value.h"

int next_scope_id = 0;
int next_variable_id = 0;

Scope *create_scope()
{
    Scope *scope = malloc(sizeof(*scope));
    scope->id = next_scope_id++;
    scope->variables = create_array(sizeof(Variable));
    return scope;
}

Variable *register_value(char *name, void *value, int type, int length, Scope *scope)
{
    Variable *var = malloc(sizeof(*var));

    var->id = next_variable_id++;
    var->ptr = value;
    var->items = length;
    var->type = type;

    copy_string(&var->name, name);
    push_to_array(scope->variables, var);
    return var;
}

void close_scope(Scope *scope)
{
    close_array(scope->variables, close_variable);
    free(scope);
}

void close_variable(Variable *var)
{
    free(var->name);
    free(var);
}