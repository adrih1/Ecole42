# Level0

## Basic Info
```bash
GCC stack protector support:            Enabled
Strict user copy checks:                Disabled
Restrict /dev/mem access:               Enabled
Restrict /dev/kmem access:              Enabled
grsecurity / PaX: No GRKERNSEC
Kernel Heap Hardening: No KERNHEAP
System-wide ASLR (kernel.randomize_va_space): Off (Setting: 0)
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX enabled    No PIE          No RPATH   No RUNPATH   /home/user/level0/level0
```

We have a script with several security checks disabled.

## Testing the script

```bash
$ ./level0 
Segmentation fault (core dumped)

level0@RainFall:~$ ./level0 coucou
No !
```

Okay so the script takes an argument, probably does a check and display a string based on that check. 

## Analysing the program 

```bash
(gdb) disas main
Dump of assembler code for function main:
[...]
0x08048ec9 <+9>:    mov    0xc(%ebp),%eax    ; argv
0x08048ecc <+12>:   add    $0x4,%eax         ; argv[1]
0x08048ecf <+15>:   mov    (%eax),%eax       ; *argv[1]
0x08048ed1 <+17>:   mov    %eax,(%esp)
0x08048ed4 <+20>:   call   0x8049710 <atoi>
[...]
```

As confirmed by gdb, the program takes an argument converts it with atoi.
Then if atoi(argv[1]) != 423 (0x1a7 in decimal), we jump to an error else we continue. 

```bash
[...]
0x08048ed9 <+25>:   cmp    $0x1a7,%eax 
0x08048ede <+30>:   jne    0x8048f58 <main+152>
[...]
```

If that check is pass we see there is a call to execv :

```bash
0x08048f46 <+134>:	mov    %eax,0x4(%esp)
0x08048f4a <+138>:	movl   $0x80c5348,(%esp)
0x08048f51 <+145>:	call   0x8054640 <execv>
```

Let's check the value at 0x80c5348

```bash
$ x/s 0x80c5348
0x80c5348:	 "/bin/sh"
```

## Getting access to the shell

Alright let's try to execute the program with 423 as an argument ! 


```bash
./level0 423
$ cat /home/user/level1/.pass
***************************************
```

We have access let's [script it](./Ressources/exploit.py)! 