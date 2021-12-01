#include "engine.h"

int start_engine(Console *console)
{
    console_prefix(console, " [ @eg ] ");
    console_println(console, "starting engine");

    // -- //
    test(console);
    // -- //

    return 0;
}

// TODO remove
void test(Console *console)
{
    Scope *scope = create_scope();
    Variable *var = register_value("test", "hello", CHAR, 5, scope);

    console_println(console, "test: %s", ((Variable *) scope->variables->values[0])->ptr);
    close_scope(scope);
}