#include "log.h"

void exists_or_exit(void *ptr)
{
    if (ptr == NULL)
        exit(139);
}

void copy_string(char **dest, char *src)
{
    int len = strlen(src);
    *dest = calloc(len + 1, sizeof(char));
    strcpy(*dest, src);
}

void push_to_string(char **dest, char *src, int do_free)
{
    char *copy;
    int plen = 0, slen = strlen(src);

    copy_string(&copy, *dest);

    if (*dest != NULL)
        plen = strlen(*dest);
    
    if (do_free) free(*dest);
    *dest = calloc(slen + plen + 1, sizeof(char));

    strncat(*dest, copy, plen);
    strncat(*dest, src, slen);
    free(copy);
}

void set_console_defaults(Console *console)
{
    console->stream = stdout;
}

int console_print(Console *console, char *str, ...)
{
    char *print;
    int rc;
    va_list args;

    set_console_defaults(console);
    copy_string(&print, console->prefix);
    push_to_string(&print, str, 1);
    va_start(args, str);
    rc = vfprintf(console->stream, print, args);

    va_end(args);
    free(print);
    return rc;
}

int console_println(Console *console, char *str, ...)
{
    int rc;
    va_list args;

    push_to_string(&str, "\n", 0);
    va_start(args, str);
    rc = console_print(console, str, args);

    va_end(args);
    free(str);
    return rc;
}

void console_stream(Console *console, FILE *stream)
{
    exists_or_exit(console);
    exists_or_exit(stream);
    console->stream = stream;
}

void console_prefix(Console *console, char *prefix)
{
    exists_or_exit(&console);
    exists_or_exit(prefix);
    copy_string(&console->prefix, prefix);
}

void console_level(Console *console, int level)
{
    exists_or_exit(&console);
    console->level = level;
}