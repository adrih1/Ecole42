#ifndef TERMINAL_H
# define TERMINAL_H

# include <stddef.h>
# include <stdint.h>

/* Prototypes Driver */
void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_putstr(const char* data);
void printk(const char *format, ...);

/* Helpers demandés par le sujet */
size_t strlen(const char* str);

#endif