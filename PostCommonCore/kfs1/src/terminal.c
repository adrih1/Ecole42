#include "terminal.h"
#include <stdarg.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_BUF 0xB8000

static size_t   g_x = 0;
static size_t   g_y = 0;
static uint8_t  g_color = 0x07; // Gris clair sur noir

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len]) len++;
    return len;
}

void terminal_initialize(void) {
    uint16_t *buffer = (uint16_t*)VGA_BUF;
    for (size_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        buffer[i] = (uint16_t)' ' | (uint16_t)g_color << 8;
    }
}

// Prototype de la fonction ASM
extern void outb(uint16_t port, uint8_t data);

void terminal_update_cursor(void) {
    uint16_t pos = g_y * VGA_WIDTH + g_x;

    // On dit au contrôleur VGA qu'on va envoyer l'octet bas (0x0F) (Index)
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(pos & 0xFF));
    
    // On dit au contrôleur VGA qu'on va envoyer l'octet haut (0x0E) (Valeur)
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}

void terminal_putchar(char c) {
    uint16_t *buffer = (uint16_t*)VGA_BUF;

    if (c == '\n') {
        g_x = 0;
        g_y++;
    } else {
        buffer[g_y * VGA_WIDTH + g_x] = (uint16_t)c | (uint16_t)g_color << 8;
        if (++g_x == VGA_WIDTH) {
            g_x = 0;
            g_y++;
        }
    }

    /* Logique de Scroll */
    if (g_y >= VGA_HEIGHT) {
        for (size_t i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++)
            buffer[i] = buffer[i + VGA_WIDTH];
        for (size_t i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_HEIGHT * VGA_WIDTH; i++)
            buffer[i] = (uint16_t)' ' | (uint16_t)g_color << 8;
        g_y = VGA_HEIGHT - 1;
    }
    terminal_update_cursor();
}

void terminal_putstr(const char* data) {
    for (size_t i = 0; data[i] != '\0'; i++) {
        terminal_putchar(data[i]);
    }
}

#include <stdarg.h>

// Helper pour convertir un nombre en chaîne (Base 10 ou 16)
void terminal_putnbr_base(uint32_t n, int base) {
    char *digits = "0123456789abcdef";
    if (n >= (uint32_t)base)
        terminal_putnbr_base(n / base, base);
    terminal_putchar(digits[n % base]);
}

void printk(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (size_t i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++; // On regarde le caractère après le '%'
            
            switch (format[i]) {
                case 's': { // String
                    char *s = va_arg(args, char *);
                    if (!s) s = "(null)";
                    terminal_putstr(s);
                    break;
                }
                case 'd': { // Decimal (signé)
                    int d = va_arg(args, int);
                    if (d < 0) {
                        terminal_putchar('-');
                        d = -d;
                    }
                    terminal_putnbr_base((uint32_t)d, 10);
                    break;
                }
                case 'x': { // Hexadecimal
                    uint32_t x = va_arg(args, uint32_t);
                    terminal_putstr("0x");
                    terminal_putnbr_base(x, 16);
                    break;
                }
                case 'c': { // Character
                    char c = (char)va_arg(args, int);
                    terminal_putchar(c);
                    break;
                }
                case '%': { // Le signe % lui-même
                    terminal_putchar('%');
                    break;
                }
                default: // Si on ne connaît pas, on affiche tel quel
                    terminal_putchar('%');
                    terminal_putchar(format[i]);
                    break;
            }
        } else {
            terminal_putchar(format[i]);
        }
    }
    va_end(args);
}