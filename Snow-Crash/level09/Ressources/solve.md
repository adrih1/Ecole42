## Exploring the exercice

```bash 
$ ls -la
-rwsr-sr-x 1 flag09  level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09  level09   26 Mar  5  2016 token
```


Let's do some tests

```bash 
$ ./level09 
You need to provied only one arg.

$ ./level09 token
tpmhr

$ ./level09 test
tfuw
```

Okay so there's seems to be some cipher going on, each letter gets added their index. 
e + 1 = f
s + 2 = u 







