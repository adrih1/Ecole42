#include "woody.h"

void patchSegment(Elf64_Phdr *phdr, size_t payloadSize)
{
    phdr->p_filesz += payloadSize;
    phdr->p_memsz += payloadSize;

}

void patchEntryPoint(Elf64_Ehdr *header, t_woody *data)
{
    header->e_entry = data->cave_vaddr;
}
