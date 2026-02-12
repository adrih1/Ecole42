#include "terminal.h"

void kernel_main(void) {
    terminal_initialize();

    terminal_setcolor(VGA_COLOR_CYAN, VGA_COLOR_BLACK);
    printk("KFS-1 Kernel chargé avec succès !\n");

    terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    printk("Affichage de 42 : ");
    
    terminal_setcolor(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
    printk("42\n");

    terminal_setcolor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    printk("Test du scroll avec couleurs...\n");
    for (int i = 0; i < 5; i++) {
        terminal_setcolor(i + 1, VGA_COLOR_BLACK);
        printk("Ligne coloree %d\n", i);
    }

    while (1);
}