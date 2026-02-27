#include "terminal.h"
#include "tty.h"

void kernel_main(void) {
    terminal_initialize();
    tty_init(); // Initialise les buffers des écrans virtuels

    terminal_setcolor(VGA_COLOR_CYAN, VGA_COLOR_BLACK);
    printk("KFS-1 Kernel loaded successfully !\n");

    terminal_setcolor(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
    printk("42\n");

    terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    printk("Kernel Loaded. Use F1, F2, F3 to switch screens.\n");

    while (1) {
        if (inb(0x64) & 0x01) {
            uint8_t scancode = inb(0x60);
            
            if (scancode == 0x3B) tty_switch(0);      // F1
            else if (scancode == 0x3C) tty_switch(1); // F2
            else if (scancode == 0x3D) tty_switch(2); // F3
            else if (scancode < 0x80) {
                char c = g_kbd_qwerty[scancode];
                if (c > 0) terminal_putchar(c);
            }
        }
    }
}