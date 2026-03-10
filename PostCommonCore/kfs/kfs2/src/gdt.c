#include <gdt.h>


struct gdt_entry *gdt_entries = (struct gdt_entry *)0x800;
struct gdt_ptr gdt_p;

void gdt_set_gate(int num, uint32_t baser, uint32_t limit, uint8_t access, uint8_t gran)
{
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high = (base >> 24) & 0xFF
    
    gdt_entries[num].
    gdt_entries[num].
    gdt_entries[num].
    gdt_entries[num].

}
