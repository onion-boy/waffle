#include "log.h"

void exists_or_exit(void *ptr)
{
    if (ptr == NULL)
        exit(1);
}

void copy_string(char **dest, char *src)
{
    int len = strlen(src);
    *dest = calloc(len + 1, sizeof(char));
    strcpy(*dest, src);
}

void push_to_string(char **dest, char *add, int do_free)
{
    char *copy;
    int plen = 0, slen = strlen(add);

    copy_string(&copy, *dest);

    if (*dest != NULL)
        plen = strlen(*dest);

    if (do_free)
        free(*dest);

    *dest = calloc(slen + plen + 1, sizeof(char));
    strncat(*dest, copy, plen);
    strncat(*dest, add, slen);
    free(copy);
}

void realloc_push_to_string(char **dest, char *add)
{
    int plen = strlen(*dest), slen = strlen(add);
    *dest = realloc(*dest, (slen + plen + 1) * sizeof(char));
    strncat(*dest, add, slen);
}

void auto_push_to_string(char **dest, char *add)
{
    strncat(*dest, add, strlen(add));
}

void set_console_defaults(Console *console)
{
    console->stream = stdout;
}

int console_printdf(Console *console, char *str, va_list args)
{
    char *print = calloc(strlen(str) + strlen(console->prefix) + 1, sizeof(char));
    int rc;

    set_console_defaults(console);
    auto_push_to_string(&print, console->prefix);
    auto_push_to_string(&print, str);
    rc = vfprintf(console->stream, print, args);

    va_end(args);
    free(print);
    return rc;
}

int console_print(Console *console, char *str, ...)
{
    va_list args;
    va_start(args, str);
    return console_printdf(console, str, args);
}

int console_println(Console *console, char *str, ...)
{
    va_list args;
    va_start(args, str);
    push_to_string(&str, "\n", 0);
    int rc = console_printdf(console, str, args);
    free(str);
    return rc;
}

void console_stream(Console *console, FILE *stream)
{
    console->stream = stream;
}

void console_prefix(Console *console, char *prefix)
{
    copy_string(&console->prefix, prefix);
}

void console_level(Console *console, int level)
{
    console->level = level;
}