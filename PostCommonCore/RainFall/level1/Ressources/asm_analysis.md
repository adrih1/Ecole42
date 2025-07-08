# Function Analysis

## Main
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


```bash
Address        Instruction              Explanation
0x08048480	    push %ebp	            Save the previous base pointer
0x08048481	    mov %esp, %ebp	        Set current stack pointer as new base pointer
0x08048483	    and $0xfffffff0, %esp	Align the stack to 16 bytes (for performance optimization)
0x08048486	    sub $0x50, %esp	        Allocate 80 bytes (0x50) on the stack for local variables
0x08048489	    lea 0x10(%esp), %eax	Store the address ESP + 0x10 in EAX (→ pointer to buffer)
0x0804848d	    mov %eax, (%esp)	    Place this pointer as argument for gets()
0x08048490	    call gets@plt	        Call gets(buffer) — 🔥 DANGER: unsafe function
0x08048495	    leave	                Restore EBP and ESP (function epilogue)
0x08048496	    ret	                    Return to the saved address (stored on the stack)
```

### Stack during Main

```bash
+------------------+
|  Return address  | ← Overwritable if too much input is passed to gets()
+------------------+
|  Old EBP         |
+------------------+
|                  |
|  Reserved zone   |
|    (80 bytes)    | ← buffer used by gets()
|                  |
+------------------+
```

# What we can understand
We allocate 0x50 (80 in decimal) bytes on the stack with 'sub'. 
Then 'lea' and 'mov', calculate the address of the variable located at esp + 0x10 and puts that address as argument for the 'gets()' call. 


## Run

```bash
Dump of assembler code for function run:
0x08048444 <+0>:	push   %ebp
0x08048445 <+1>:	mov    %esp,%ebp
0x08048447 <+3>:	sub    $0x18,%esp
0x0804844a <+6>:	mov    0x80497c0,%eax
0x0804844f <+11>:	mov    %eax,%edx
0x08048451 <+13>:	mov    $0x8048570,%eax
0x08048456 <+18>:	mov    %edx,0xc(%esp)
0x0804845a <+22>:	movl   $0x13,0x8(%esp)
0x08048462 <+30>:	movl   $0x1,0x4(%esp)
0x0804846a <+38>:	mov    %eax,(%esp)
0x0804846d <+41>:	call   fwrite@plt
0x08048472 <+46>:	movl   $0x8048584,(%esp)
0x08048479 <+53>:	call   system@plt
0x0804847e <+58>:	leave  
0x0804847f <+59>:	ret
```

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


```bash
+--------------------+
| Return address     |
+--------------------+
| Old EBP            |
+--------------------+
| Temporary zone     |
| reserved (24 bytes)|
+--------------------+
```

# What we can understand
The run() function :
Displays a message with fwrite()
Executes a system command /bin/sh
It is never called in main