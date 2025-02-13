# Methodology

Thanks to the video, I discovered that the goal is to **'Find the first file who can run only as flag00'**.

---

## Using the terminal

1. I executed the following command to find the file:

   ```bash
   find / -user flag00
   ```

2. The output revealed:

   ```plaintext
   /usr/sbin/john
   ```

3. I used `cat` to inspect the file:

   ```bash
   cat /usr/sbin/john
   ```

4. The result was:

   ```plaintext
   cdiiddwpgswtgt
   ```

## Finding the encryption
I asked ChatGPT what encryption was used for this text, and he responded that it was most likely Caesar code encryption.

## Using dcode.fr
I wrote the text '`cdiiddwpgswtgt`' on the website [dcode.fr](https://www.dcode.fr/), which sorted the most likely result as:

```plaintext
nottoohardhere
```
