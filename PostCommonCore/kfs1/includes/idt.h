#ifndef IDT_H
# define IDT_H

// intx_t and uintx_t datatypes 
# include <stdint.h> 

/* Structure d'une entrée de l'IDT (Gate Descriptor) */
struct idt_entry {
    uint16_t base_low;    // Partie basse de l'adresse de la fonction
    uint16_t selector;    // Segment de code (toujours 0x08 pour nous)
    uint8_t  zero;        // Toujours à 0
    uint8_t  flags;       // Droits d'accès et type
    uint16_t base_high;   // Partie haute de l'adresse
} __attribute__((packed));

/* Structure du registre IDTR que le CPU va charger */
struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

void idt_init(void);

#endif