#ifndef TTY_H
# define TTY_H

# include "terminal.h"

#define MAX_TTY 3
#define VRAM_SIZE (VGA_WIDTH * VGA_HEIGHT)

typedef struct {
    uint16_t buffer[VRAM_SIZE]; // Sauvegarde des caractères et couleurs
    size_t x;                   // Position curseur X
    size_t y;                   // Position curseur Y
    uint8_t color;              // Couleur du TTY
} tty_t;

void tty_init(void);
void tty_switch(int new_tty);
int  tty_get_current(void);

#endif