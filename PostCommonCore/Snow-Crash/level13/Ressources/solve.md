# Level13

## Exploring the exercice

```bash 
$ ls -la
-rwsr-sr-x 1 flag13  level13 7303 Aug 30  2015 level13
```

We have a binary setuid/setgid

## Inspecting the file

```bash 
$ ./level13 
UID 2013 started us but we we expect 4242
```

It asks to be executed by a specific UID, let's look at the executable with strings. 


```bash 
$ strings level13 
[...]
getuid
[...]
0123456
UID %d started us but we we expect %d
boe]!ai0FB@.:|L6l@A?>qJ}I
your token is %s
;*2$"$
GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
[...]
```

We are going to change the UID during the execution with GDB. 

```bash
Breakpoint 1, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
(gdb) step 
Single stepping until exit from function getuid,
which has no line number information.
0x0804859a in main ()
(gdb) p $eax # Here we display the eax, it is a container the CPU uses for calculations and temporary storage 
$1 = 2013
(gdb) set $eax=4242 #We change the UID value
(gdb) step
Single stepping until exit from function main,
which has no line number information.
your token is ********
```