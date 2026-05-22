# Hidden Email Field in Password Recover Page 

## Vulnerability

When cliking on the forgot password in the sign in page, we get to :
```plaintext
http://127.0.0.1:8080/index.php?page=recover
```

We see a subit button, with no connected field such as an email input to recieve your reste link. 

Looking at the inspector, we see 
```plaintext
<input type="hidden" name="mail" value="webmaster@borntosec.com" maxlength="15">
```

Changing the value to my own email, and clicking the submit button displayed the flag. 

## Solution 
Do not put such information in a form and handle the request on the server side.
