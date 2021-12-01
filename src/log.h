#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct console
{
    FILE *stream;
    char *prefix;
    int level;
} Console;

void exists_or_exit(void *ptr);
void push_to_string(char **dest, char *add, int do_free);
void realloc_push_to_string(char **dest, char *add);
void auto_push_to_string(char **dest, char *add);
void copy_string(char **dest, char *src);

int console_print(Console *console, char *str, ...);
int console_printdf(Console *console, char *str, va_list args);
int console_println(Console *console, char *str, ...);
void set_console_defaults(Console *console);

void console_stream(Console *console, FILE *stream);
void console_prefix(Console *console, char *prefix);
void console_level(Console *console, int level);

#endif