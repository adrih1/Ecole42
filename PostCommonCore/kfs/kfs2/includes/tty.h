#ifndef TTY_H
# define TTY_H

# include "terminal.h"

#define MAX_TTY 3
#define VRAM_SIZE (VGA_WIDTH * VGA_HEIGHT)

typedef struct {
    uint16_t buffer[VRAM_SIZE]; // Save chars and their colors for each TTY
    size_t x;                   // X cursor
    size_t y;                   // Y cursor 
    uint8_t color;              // TTY color
} tty_t;

void tty_init(void);
void tty_switch(int new_tty);
int  tty_get_current(void);

#endif