#include <stdint.h>

struct gdt_entry
{
    uint16_t limit_low;     // 16 bits 
    uint16_t base_low;      // 16 bits
    uint8_t base_middle;   // 8 bits
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __atribute__((packed));



struct gdt_ptr
{
    uint16_t limit;
    uint16_t base;
} __atribute__((packed));


