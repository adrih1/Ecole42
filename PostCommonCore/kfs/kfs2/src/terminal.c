#include "terminal.h"
#include <stdarg.h>

/* State of terminal */
size_t   g_x = 0;
size_t   g_y = 0;
uint8_t  g_color;


static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
    return fg | (bg << 4);
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t) uc | (uint16_t) color << 8;
}

/**
 * Defines current display color
 */
void terminal_setcolor(enum vga_color fg, enum vga_color bg) {
    g_color = vga_entry_color(fg, bg);
}


/**
 * Communicates with the CRT controller to move the blinking cursor.
 * Uses I/O ports 0x3D4 (index) and 0x3D5 (data).
 */
void terminal_update_cursor(void) {
    uint16_t pos = g_y * VGA_WIDTH + g_x;

    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(pos & 0xFF));
    
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}

/**
 * Moves all screen 1 row up if we go beyond height.
 * Cleans last line with empty spaces.
 */
static void terminal_scroll(void) {
    uint16_t *buffer = (uint16_t*)VGA_BUF;

    // Move line 0 to 24 up, deletes line 0
    for (size_t i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++) {
        buffer[i] = buffer[i + VGA_WIDTH];
    }

    // Empty last line (line 24)
    for (size_t i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_HEIGHT * VGA_WIDTH; i++) {
        buffer[i] = vga_entry(' ', g_color);
    }
}

/**
 * Initialize screen: empty VGA memory and reset cursor.
 */
void terminal_initialize(void) {
    g_x = 0;
    g_y = 0;
    terminal_setcolor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    
    uint16_t *buffer = (uint16_t*)VGA_BUF;
    for (size_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        buffer[i] = vga_entry(' ', g_color);
    }
    terminal_update_cursor();
}


/**
 * Display one char (handle '\n' and overlay)
 */
void terminal_putchar(char c) {
    uint16_t *buffer = (uint16_t*)VGA_BUF;

    if (c == '\n') {
        g_x = 0;
        g_y++;
    } else {
        buffer[g_y * VGA_WIDTH + g_x] = vga_entry(c, g_color);
        if (++g_x == VGA_WIDTH) {
            g_x = 0;
            g_y++;
        }
    }

    // Handling screen overlay
    if (g_y >= VGA_HEIGHT) {
        terminal_scroll();
        g_y = VGA_HEIGHT - 1;
    }

    terminal_update_cursor();
}

void terminal_putstr(const char* data) {
    for (size_t i = 0; data[i] != '\0'; i++) {
        terminal_putchar(data[i]);
    }
}

/**
 * Fromat and display complex messages.
 */
void printk(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (size_t i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 's': terminal_putstr(va_arg(args, char *)); break;
                case 'c': terminal_putchar((char)va_arg(args, int)); break;
                case 'x': 
                    terminal_putstr("0x"); 
                    terminal_putnbr_base(va_arg(args, uint32_t), 16); 
                    break;
                case 'd': {
                    int d = va_arg(args, int);
                    if (d < 0) { terminal_putchar('-'); d = -d; }
                    terminal_putnbr_base((uint32_t)d, 10);
                    break;
                }
                case '%': terminal_putchar('%'); break;
            }
        } else {
            terminal_putchar(format[i]);
        }
    }
    va_end(args);
}

void terminal_putnbr_base(uint32_t n, int base) {
    char *digits = "0123456789abcdef";
    if (n >= (uint32_t)base)
        terminal_putnbr_base(n / base, base);
    terminal_putchar(digits[n % base]);
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len]) len++;
    return len;
}



