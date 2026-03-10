#include <stdint.h>

struct gdt_entry
{
    uint16_t limit_low;     // 16 bits 
    uint16_t base_low;      // 16 bits
    uint8_t base_middle;    // 8 bits
    uint8_t access;         // Access (Privileges, Segments type)
    uint8_t granularity;    // High limit + flags (4 bits + 4 bits)
    uint8_t base_high;      // Top of the base address (8 bits)
} __atribute__((packed));



struct gdt_ptr
{
    uint16_t limit;         // GDT size - 1
    uint16_t base;          // GDT address (0x800 in our case)
} __atribute__((packed));


