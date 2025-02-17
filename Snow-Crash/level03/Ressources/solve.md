## Exploring the computer 

```bash 
$ ls
level03
```

## Learning more about level03 

```bash 
$ls -la level03

total 24
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
```

We have a file taht belons to flag03. 

```bash
$ file level03 

level03: setuid setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0x3bee584f790153856e826e38544b9e80ac184b7b, not stripped
```

It is an executable, so naturally I try to execute it 

```bash
$ ./level03
Exploit me
```
