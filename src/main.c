#include "engine/engine.h"

int main()
{
    Console console = {.stream = stdout};
    start_engine(&console);
    free(console.prefix);
}