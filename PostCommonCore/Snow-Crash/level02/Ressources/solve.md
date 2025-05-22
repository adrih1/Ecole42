
## Exploring the exercice

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

## Reading the file 

After a few research about pcap, I see that wireshark is a package already installed which allows us to read those files. 

So I copy the file locally. 

```bash
scp -P 12345 level02@localhost:level02.pcap .

wireshark level02.pcap
```

I use the Follow utility to follow TCP packages and get this result

```bash

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

Instinctively I take out the '.' so I get ft_wandrNDRelL0L but that does not work. 

I go back and see that in the ASCII table '.' is 7F in hexadecimal which is the DEL key. 

SO I delete a char before every '.' and get ft_waNDReL0L

