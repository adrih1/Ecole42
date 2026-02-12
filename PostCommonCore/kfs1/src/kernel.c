#include "terminal.h"

void kernel_main(void) {
    terminal_initialize();

    // Test de base
    printk("Affichage de %s : 42\n", "la constante");
    printk("KFS Interactif prêt ! Appuie sur une touche...\n");

    // Test des nombres et hexa
    int val = 1337;
    printk("Decimal: %d | Hexa: %x\n", val, val);

    // Test du scroll avec printk
    for (int i = 0; i < 10; i++) {
        printk("Ligne de log numero %d...\n", i);
    }

    printk("\nSysteme pret. Curseur a la ligne %d.\n", 15);

    while (1);
}