# Level00 

Thanks to the video, I discovered that the goal is to **'Find the first file who can run only as flag00'**.

---

## EXploring the computer

1. I executed the following command to find the file:

   ```bash
   find / -user flag00 2>/dev/null
   ```

2. The output revealed:

   ```plaintext
   /usr/sbin/john
   /rofs/usr/sbin/john
   ```

3. I used `cat` to inspect the file:

   ```bash
   $ cat /usr/sbin/john
   cdiiddwpgswtgt
   ```

## Decrypting

I wrote the text '`cdiiddwpgswtgt`' on the website [dcode.fr](https://www.dcode.fr/), which sorted the most likely result as:

```plaintext
nottoohardhere
```

### Getting the flag

```bash
$ su flag00
Password: 
Don't forget to launch getflag !
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : **************
```