/* * On définit manuellement le pointeur vers la mémoire vidéo VGA.
 * L'adresse 0xB8000 est l'adresse physique standard pour le mode texte.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_COLOR_LIGHT_GREY 7
#define VGA_COLOR_BLACK 0

/* On crée un petit utilitaire pour combiner caractère et couleur */
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t) uc | (uint16_t) color << 8;
}


size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(void) {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = VGA_COLOR_LIGHT_GREY | (VGA_COLOR_BLACK << 4);
    terminal_buffer = (uint16_t*) 0xB8000;
    
    // On efface l'écran (remplissage d'espaces vides)
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_putchar(char c) {
    // Gestion du retour à la ligne
    if (c == '\n') {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT) {
            terminal_row = 0; // On reviendra sur le scroll plus tard
        }
        return;
    }

    // Affichage normal
    const size_t index = terminal_row * VGA_WIDTH + terminal_column;
    terminal_buffer[index] = vga_entry(c, terminal_color);
    
    if (++terminal_column == VGA_WIDTH) {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT) {
            terminal_row = 0;
        }
    }
}

void terminal_putstr(const char* data) {
    for (size_t i = 0; data[i] != '\0'; i++) {
        terminal_putchar(data[i]);
    }
}

void kernel_main(void) {
    /* Initialisation de l'écran */
    terminal_initialize();

    /* Affichage du message */
    terminal_putstr("42\n");
    terminal_putstr("Bienvenue dans mon Kernel !\n");

    while (1) {
        // Boucle infinie
    }
}