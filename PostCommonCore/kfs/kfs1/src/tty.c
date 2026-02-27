#include "tty.h"

static tty_t g_ttys[MAX_TTY];
static int    g_current_tty = 0;

/* Import des variables globales de terminal.c pour les synchroniser */
extern size_t g_x;
extern size_t g_y;
extern uint8_t g_color;

void tty_init(void) {
    for (int i = 0; i < MAX_TTY; i++) {
        g_ttys[i].x = 0;
        g_ttys[i].y = 0;
        // On donne une couleur différente par défaut à chaque écran pour bien les distinguer
        // TTY0: Gris, TTY1: Vert, TTY2: Cyan
        uint8_t colors[] = {0x07, 0x02, 0x03};
        g_ttys[i].color = colors[i];

        // On remplit le buffer de chaque TTY avec des espaces vides
        for (size_t j = 0; j < VRAM_SIZE; j++) {
            g_ttys[i].buffer[j] = (uint16_t)' ' | (uint16_t)g_ttys[i].color << 8;
        }
    }
    // Au démarrage, le terminal.c a déjà initialisé g_x, g_y et g_color.
    // On s'assure que le TTY 0 reflète l'état initial.
    g_current_tty = 0;
}

void tty_switch(int new_tty) {
    if (new_tty < 0 || new_tty >= MAX_TTY || new_tty == g_current_tty)
        return;

    uint16_t *vga = (uint16_t*)VGA_BUF;

    // 1. SAUVEGARDE du TTY actuel
    g_ttys[g_current_tty].x = g_x;
    g_ttys[g_current_tty].y = g_y;
    g_ttys[g_current_tty].color = g_color;
    for (size_t i = 0; i < VRAM_SIZE; i++) {
        g_ttys[g_current_tty].buffer[i] = vga[i];
    }

    // 2. CHANGEMENT d'index
    g_current_tty = new_tty;

    // 3. RESTAURATION du nouveau TTY
    g_x = g_ttys[g_current_tty].x;
    g_y = g_ttys[g_current_tty].y;
    g_color = g_ttys[g_current_tty].color;
    for (size_t i = 0; i < VRAM_SIZE; i++) {
        vga[i] = g_ttys[g_current_tty].buffer[i];
    }

    // 4. MAJ du curseur matériel
    terminal_update_cursor();
}

int tty_get_current(void) {
    return g_current_tty;
}