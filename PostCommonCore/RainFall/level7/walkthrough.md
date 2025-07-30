# Level 7

```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/user/level7/level7
```

## Testing the program

```bash
$ ./level7 
Segmentation fault (core dumped)

$ ./level7 hello
Segmentation fault (core dumped)

$ ./level7 hello you
~~

$ ./level7 hello to you
~~

$ ./level7 good day to you
~~
```

We have a program which takes at least two arguments and segfaults if otherwise.

## Learning more


