## Exploring the Computer

### Doing the previous level commands, just in case

```bash
$ find / -user level01
(nothing)
$ find / -user flag01
(nothing)
```
### What access do I have ?
```bash
$ id
uid=2001(level01) gid=2001(level01) groups=2001(level01),100(users)
```

## Password config (thought about it thanks to b2br)

```bash
$ cat /etc/passwd
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```
I see that flag01 has a visible password

### Decrypting the code
dcode identified it as base58 encrypted but it gave nothing that had sense. So I thought about the intra video which said that we would need John The Ripper. 

I remembered that flag00 had a john executable
```bash
$ john --version
bash: /usr/sbin/john: Permission denied
```
```bash
$ ls -la  /usr/sbin/john
----r--r-- 1 flag00 flag00 15 Mar  5  2016 /usr/sbin/john
```
It gave nothing. So I decided to do a VM with John, I didn't have enough storage so chatGPT advised me to do a docker image.

### Installing John on a Docker Image
```bash
docker pull kalilinux/kali-rolling 
```

```bash
docker run -it kalilinux/kali-rolling /bin/bash
```

```bash
apt update && apt uprade -y
```

```bash
apt install john -y
```

```bash
echo "42hDRfypTqqnw" > /root/hash.txt
```

```bash
$ john --show /root/hash.txt 
?:abcdefg

1 password hash cracked, 0 left
```

Pasword for flag connection is : abcdefg

