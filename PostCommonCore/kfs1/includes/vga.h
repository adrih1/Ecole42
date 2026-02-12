#ifndef VGA_H
# define VGA_H

# include <stdint.h>

/* Standard VGA : l'écran fait 80x25 caractères */
# define VGA_WIDTH 80
# define VGA_HEIGHT 25
/* L'adresse physique de la mémoire vidéo en mode texte */
# define VGA_BUFFER 0xB8000

/* Couleurs standards du mode texte VGA */
enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_WHITE = 15,
    /* Tu pourras ajouter les autres pour le bonus couleurs */
};

#endif