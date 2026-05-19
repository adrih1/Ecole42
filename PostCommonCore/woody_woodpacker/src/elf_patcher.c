#include "woody.h"

void patchSegment(Elf64_Phdr *phdr, size_t payloadSize)
{
    phdr->p_filesz += payloadSize;
    phdr->p_memsz += payloadSize;

	phdr->p_flags |= PF_W;
}

void patchEntryPoint(Elf64_Ehdr *header, t_woody *data)
{
    header->e_entry = data->cave_vaddr;
}
