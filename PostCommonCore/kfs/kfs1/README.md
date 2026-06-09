# Global View

## Bootloader
In order to boot, GRUB looks for a Header Multiboot in the first 8 Ko of ourn binary.
We need a boot.s file in nasm that :
```plaintext
    --> Defines "Magic Numbers"
    --> Defines a stack because the CPU doesn't have one yet
    --> Calls the kernel_main 
```

## Linker Sript (linker.ld)

A kernel needs to be placed at a specific place (usually at 1Mo). 
The .ld file will tell the linker:
```plaintext
    --> Put the .multiboot section at the beginning of the file
    --> The start address is <this>
    --> Merge all my .o files here
```

## Talking to the screen (VGA Text Mode)

Since we do not have a write function, we have to write in the video memory.
In the x86 architecture, the video memory starts at the physical addres 0XB8000. It is an array of characters where every charcaters takes 2 bytes:

```plaintext
    1. Data byte (ex; "4")
    2. Attribute byte: color of the text and background (ex: 0x07)
```

# Compilation Workflow

```plaintext
1. Compile the ASM : nasm -f elf32 boot.s -o boot.o
2. Compile the C : gcc -m32 -c kernel.c -o kernel.o -fno-builtin -nostdlib ... (We use -m32 because we target i386).
3. Link: ld -m elf_i386 -T linker.ld boot.o kernel.o -o kfs.bin
4. Verifiy : Use this command: grub-file --is-x86-multiboot kfs.bin. If it returns nothing then it works.
```


# Detail 

## Bootloader

GRUB looks for a sequence of specific bytes. We must define 3 constants.
```plaintext
MAGIC : 0x1BADB002 (Magic signature).
FLAGS : We ask GRUB to align the modules in memory (1 << 0) and to give us info on memory (1 << 1).
CHECKSUM : A math check : MAGIC+FLAGS+CHECKSUM=0.
```