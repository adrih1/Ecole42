## Exploring the exercice

```bash 
$ ls -la
-rwsr-sr-x+ 1 flag10  level10 10817 Mar  5  2016 level10
-rw-------  1 flag10  flag10     26 Mar  5  2016 token
```

Let's do some tests

```bash 
$ ./level10 
./level10 file host
        sends file to host if you have access to it
````

```bash 
$ ./level10 token coucou
You don't have access to token
````

```bash 
$ echo 'salut' > /tmp/salut.txt
$ ./level10 /tmp/salut.txt level10
Connecting to level10:6969 .. Unable to connect to host level10
````




