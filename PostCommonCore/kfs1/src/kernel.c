#include "terminal.h"

void kernel_main(void) {
    terminal_initialize();

    terminal_setcolor(VGA_COLOR_CYAN, VGA_COLOR_BLACK);
    printk("KFS-1 Kernel loaded successfully !\n");
    
    terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    printk("Test du scroll avec couleurs...\n");
    for (int i = 0; i < 5; i++) {
        terminal_setcolor(i + 1, VGA_COLOR_BLACK);
        printk("Ligne coloree %d\n", i);
    }
    
    terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    printk("Display 42 : ");
    
    terminal_setcolor(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
    printk("42\n");

    terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    printk("Press a key: ");
  

    while (1) {
        if (inb(0x64) & 0x01) {
            uint8_t scancode = inb(0x60);

            // On ne traite que l'appui (Key Press), pas le relâchement
            if (scancode < 128) {
                char c = g_kbd_qwerty[scancode];
                if (c > 0) {
                    terminal_putchar(c);
                }
            }
        }
    }
}