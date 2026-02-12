#include "idt.h"
#include "terminal.h"

struct idt_entry idt[256];
struct idt_ptr   idtp;

extern void load_idt(uint32_t);
extern void irq1_handler(void);
extern void outb(uint16_t port, uint8_t data);
extern uint8_t inb(uint16_t port);

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low = (base & 0xFFFF);
    idt[num].base_high = (base >> 16) & 0xFFFF;
    idt[num].selector = sel;
    idt[num].zero = 0;
    idt[num].flags = flags;
}

/* Le vrai gestionnaire de clavier appelé par l'ASM */
void keyboard_handler_main(void) {
    uint8_t scancode = inb(0x60);
    
    // On affiche le scancode pour tester
    if (!(scancode & 0x80)) { // Si bit 7 est 0, c'est une touche pressée
        printk("Key pressed: %x ", scancode);
    }

    // On DOIT envoyer un signal "EndOfInterrupt" au contrôleur (PIC)
    outb(0x20, 0x20); 
}

void idt_init(void) {
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (uint32_t)&idt;

    // 0x8E = Présent, Ring 0, Interrupt Gate
    idt_set_gate(33, (uint32_t)irq1_handler, 0x08, 0x8E); 

    load_idt((uint32_t)&idtp);
    
    // Activer les interruptions sur le processeur
    __asm__ __volatile__("sti");
}