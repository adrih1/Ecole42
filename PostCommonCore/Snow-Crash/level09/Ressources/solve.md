# Level09

## Exploring the exercice

```bash 
$ ls -la
-rwsr-sr-x 1 flag09  level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09  level09   26 Mar  5  2016 token
```
## Inspecting the files

Let's do some tests

```bash 
$ ./level09 
You need to provied only one arg.

$ ./level09 token
tpmhr

$ ./level09 test
tfuw

$ cat token
f4kmm6p|=?p?n??DB?Du{??
```

Okay so there's seems to be some cipher going on, each letter gets added their index. 
e + 1 = f
s + 2 = u 

Let's copy the token locally 

```bash 
$ scp -P 4242 level09@192.168.1.75:/home/user/level09/token .
```

Let's do a script to decode that encryption. See [script.c](./script.c) for details, and let's execute it on our token.

```bash 
chmod +x script.py 
chmod 777 token
./script.c $(cat token)

f3iji1ju5yuevaus41q1afiuq
```
## Getting the flag

```bash 
$ su flag09
Password: 
Don't forget to launch getflag !

flag09@SnowCrash:~ $ getflag
Check flag.Here is your token : ************
```









