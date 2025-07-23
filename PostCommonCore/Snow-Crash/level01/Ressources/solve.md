# Level01

## Exploring the computer

```bash
$ find / -user level01
(nothing)
$ find / -user flag01
(nothing)
```
## What access do I have ?
```bash
$ id
uid=2001(level01) gid=2001(level01) groups=2001(level01),100(users)
```

## Password config

We had the idea to crack the users password, we thought about it thanks to a previous 42 project : "Born2BeRoot"

```bash
$ cat /etc/passwd
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```
As we see, flag01 has a visible password

## Decrypting the password

dcode identified it as base58 encrypted but it gave nothing that had sense. So we thought about the intra video which said that we would need John The Ripper. 

Then we remembered that flag00 had a john executable

```bash
$ john --version
bash: /usr/sbin/john: Permission denied
```
```bash
$ ls -la  /usr/sbin/john
----r--r-- 1 flag00 flag00 15 Mar  5  2016 /usr/sbin/john
```
It gave nothing. So we decided to do a docker image witth John The Ripper.


## Installing John on a Docker Image

```bash
$ docker pull kalilinux/kali-rolling 
$ docker run -it kalilinux/kali-rolling /bin/bash
$ apt update && apt uprade -y
$ apt install john -y
$ echo "42hDRfypTqqnw" > /root/hash.txt
$ john --show /root/hash.txt 
?:abcdefg
1 password hash cracked, 0 left
```

Pasword for flag connection is : abcdefg

## Getting the flag

```bash
$ su flag01
Password: 
Don't forget to launch getflag !
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : **************
```