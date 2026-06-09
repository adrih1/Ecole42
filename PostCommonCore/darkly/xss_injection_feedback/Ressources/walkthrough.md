# XSS Injection - Feedback Page

## Vulnerability

We are given a form, in which if we type script in the message input shows us the flag.

In a real case scneario we would have to insert the HTML tags such as 
```plaintext
<script>alert()</script>
```

## Solution 
Every input should have some kind of sanitization, to recognize known and unwanted patterns.
