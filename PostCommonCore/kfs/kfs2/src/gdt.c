#include <gdt.h>

#define GDT_ENTRIES 7

struct gdt_entry *gdt_entries = (struct gdt_entry *)0x800;
struct gdt_ptr gdt_p;

extern void gdt_flush(struct gdt_ptr *ptr); // io.s

void gdt_set_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high = (base >> 24) & 0xFF;

    gdt_entries[num].limit_low = (limit & 0xFFFF);
    gdt_entries[num].granularity = ((limit >> 16) & 0x0F) | (gran & 0xF0);
    gdt_entries[num].access = access;
}

// Access: P | DPL | S | E | DC | RW | A  (0x9A/0x92 = ring 0, 0xFA/0xF2 = ring 3)
// Flags 0xC: 4 KB granularity + 32-bit -> limit 0xFFFFF = 4 GB
void gdt_init(void)
{
    gdt_set_gate(0, 0, 0,       0,    0);       // 0x00 Null
    gdt_set_gate(1, 0, 0xFFFFF, 0x9A, 0xC0);    // 0x08 Kernel code
    gdt_set_gate(2, 0, 0xFFFFF, 0x92, 0xC0);    // 0x10 Kernel data
    gdt_set_gate(3, 0, 0xFFFFF, 0x92, 0xC0);    // 0x18 Kernel stack
    gdt_set_gate(4, 0, 0xFFFFF, 0xFA, 0xC0);    // 0x20 User code
    gdt_set_gate(5, 0, 0xFFFFF, 0xF2, 0xC0);    // 0x28 User data
    gdt_set_gate(6, 0, 0xFFFFF, 0xF2, 0xC0);    // 0x30 User stack

    gdt_p.limit = sizeof(struct gdt_entry) * GDT_ENTRIES - 1;
    gdt_p.base = 0x800;
    gdt_flush(&gdt_p);
}
