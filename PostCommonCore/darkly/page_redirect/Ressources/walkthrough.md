# Page Redirect 

## Vulnerability

At the bottom of the page, there are links to social medias. 
However the URLs use the redirect method. 

```plaintext
<a class="icon fa-facebook" href="index.php?page=redirect&amp;site=facebook"></a>
```

We can change the redirect<Plug>PeepOpenarameter to a malicious website. 

```plaintext
b326b5062b2f0e69046810717534cb09
<a class="icon fa-facebook" href="index.php?page=redirect&amp;site=malicious"></a>
```

Changing the redirect to another value and clicking the icon made the flag appeared. 
A mass phishing campaign could be set-up using this flaw. Targets would recieve a link containing:
```plaintext
https://mytrustedbank.com?page=redirect&amp;site=evilwebsite.com
```
Without the obvisous evilwebiste, somtething more blurry would be use, and users would trust it since its a link from their trusted bank.

## Solution 

