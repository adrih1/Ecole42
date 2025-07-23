# Level02

## Exploring the computer

```bash 
$ ls -a
level02.pcap
```

```bash 
$ cat level02.pcap

BB$E4Թ@@~;���;���/Y�O���%������
�F��Xf&N�dC'̊$E5�@@J%;���;��ߙO/Y�����%�s�*
��F�dXf&N�dBB$E4Ժ@@};���;���/Y�O���%�����
�F��Yf&N<TC'̊$E5�@@J$;���;��ߙO/Y�����%�sz�
��F�rYf&N�TBB$E4Ի@@|;���;���/Y�O���%�����E
C'̊$E5�@@J#;���;��ߙO/Y�����%�sl�
BB$E4Լ@@{;���;���/Y�O���%�����
H��[f&NϑC'̊$E5�@@J";���;��ߙO/Y�����%�sk?
��H�[f&N �BB$E4Խ@@z;���;���/Y�O���%�����
�I7�[f&N�8	C'̊$E5�@@J!;���;��ߙO/Y�����%�sj�
��I7[f&N�8	BB$E4Ծ@@y;���;���/Y�O��
```

## What is pcap ?

PCAP (Packet Capture) is a file format used to record network traffic data captured by tools like Wireshark or tcpdump. It stores raw packet data, including headers and payloads, for analysis. Its main purpose is to help diagnose network issues, monitor traffic, or analyze security incidents.


## Reading the file

After a few research about pcap, we see that wireshark is a package already installed which allows us to read those files, so let's copy the file locally. 

```bash
scp -P 12345 level02@localhost:level02.pcap .

wireshark level02.pcap
```

I use the 'Follow' utility to follow the TCP exchaneg of packages that occured and get this result

```plaintext

..%..%..&..... ..#..'..$..&..... ..#..'..$.. .....#.....'........... .38400,38400....#.SodaCan:0....'..DISPLAY.SodaCan:0......xterm.........."........!........"..".....b........b....	B.
..............................1.......!.."......"......!..........."........"..".............	..
.....................
Linux 2.6.38-8-generic-pae (::ffff:10.1.1.2) (pts/10)

..wwwbugs login: l.le.ev.ve.el.lX.X
..
Password: ft_wandr...NDRel.L0L
.
..
Login incorrect
wwwbugs login: 
```

## Cracking the code 

Instinctively we thought about taking out '.' so we get ft_wandrNDRelL0L but that does not work. 

We go back and see that in the ASCII table '.' is 7F in hexadecimal which is the DEL key. 

So if we delete a char before every '.' we get ft_waNDReL0L

## Getting the flag 


```bash
$ su flag02
Password: 
Don't forget to launch getflag !
flag02@SnowCrash:~$ getflag
Check flag.Here is your token : **************
```
