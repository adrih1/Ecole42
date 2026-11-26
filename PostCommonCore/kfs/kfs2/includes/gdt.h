#ifndef GDT_H
# define GDT_H

# include <stdint.h>

// GDT entry (8 bytes). Base and limit are split for 286 compatibility.
struct gdt_entry
{
    uint16_t limit_low;     // limit 0-15
    uint16_t base_low;      // base 0-15
    uint8_t base_middle;    // base 16-23
    uint8_t access;         // type + privilege
    uint8_t granularity;    // flags (high 4 bits) + limit 16-19 (low 4 bits)
    uint8_t base_high;      // base 24-31
} __attribute__((packed));

// Operand of lgdt (6 bytes)
struct gdt_ptr
{
    uint16_t limit;         // GDT size - 1
    uint32_t base;          // GDT address
} __attribute__((packed));

void gdt_set_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);
void gdt_init(void);

#endif
