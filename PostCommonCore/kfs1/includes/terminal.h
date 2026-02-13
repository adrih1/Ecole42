#ifndef TERMINAL_H
# define TERMINAL_H

# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

/* Scancode -> ASCII (QWERTY) */
extern const unsigned char g_kbd_qwerty[128];

void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_putstr(const char* data);
void terminal_putnbr_base(uint32_t n, int base);
void terminal_setcolor(enum vga_color fg, enum vga_color bg);
void printk(const char *format, ...);
size_t strlen(const char* str);
extern void outb(uint16_t port, uint8_t data);
extern uint8_t inb(uint8_t data);


#endif