# Level14

## Exploring the exercice

```bash 
$ ls -la
(nothing)

$ find / -user flag14 2> /dev/null | grep -v /proc
(nothing)

$ find / -user level13 2> /dev/null
(nothing)
```

As we can see, there seems to be nothing to exploit in the session of level14. 
Let's look directly at the executable getflag.

```bash 
$ gdb /bin/getflag
(gdb) run
Starting program: /bin/getflag
You should not reverse this
[Inferior 1 (process 3871) exited with code 01]
```

The program prevents us from doing any reverse engeeniring. 
If we deasseamble the main : 

```bash 
$ (gdb) disas main
...
0x08048989 <+67>:	call   0x8048540 <ptrace@plt>
...
0x08048afd <+439>:	call   0x80484b0 <getuid@plt>
```

We discover that there is a call to ptrace. 
After a few research we discovered that ptrace allows a process to observe and control the execution of another process, so in our case, it checks if getflag is being executed inside a debugger. 

So we looked for a way to bypasss that check and found this stack overflow : https://stackoverflow.com/questions/33646927/bypassing-ptrace-in-gdb. 


```bash
$ catch syscall ptrace
Catchpoint 1 (syscall 'ptrace' [26])
(gdb) commands 1
Type commands for breakpoint(s) 1, one per line.
End with a line saying just "end".
>set ($eax) = 0
>continue
>end
(gdb) 
(gdb) run
Starting program: /bin/getflag 

Catchpoint 1 (call to syscall ptrace), 0xb7fdd428 in __kernel_vsyscall ()

Catchpoint 1 (returned from syscall ptrace), 0xb7fdd428 in __kernel_vsyscall ()
Check flag.Here is your token : 
Nope there is no token here for you sorry. Try again :)
```

Okay we were able to execute getflag even if we are in the debugger but we are stil are missing something to get the right response from getflag. 

As we saw earlier the program also calls getuid, so we will have to act as if we are flag14. 

```bash 
$ id flag14
uid=3014(flag14) gid=3014(flag14) groups=3014(flag14),1001(flag)
```

```bash 
(gdb) b getuid
(gdb) step -> jusqu'au returns
(gdb) print $eax
$1 = 2014
```


```bash 
catch syscall ptrace
(gdb) commands 1
>set ($eax) = 0
>continue
>end
(gdb) b getuid
Breakpoint 2 at 0x80484b0
(gdb) run
Starting program: /bin/getflag 

Catchpoint 1 (call to syscall ptrace), 0xb7fdd428 in __kernel_vsyscall ()

Catchpoint 1 (returned from syscall ptrace), 0xb7fdd428 in __kernel_vsyscall ()

Breakpoint 2, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
(gdb) step
Single stepping until exit from function getuid,
which has no line number information.
0x08048b02 in main ()
(gdb) print ($eax)
$1 = 2014
(gdb) set ($eax)=3014
(gdb) step
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : **********
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```



