# Survey Manipulation 

## Vulnerability

On the survey page we see a list of 'subjects' (people) with a select option list to give them a score.

```plaintext
<select name="valeur" onchange="javascript:this.form.submit();">
	<option value="1">1</option>
	<option value="2">2</option>
	<option value="3">3</option>
	<option value="4">4</option>
	<option value="5">5</option>
	<option value="6">6</option>
	<option value="7">7</option>
	<option value="8">8</option>
	<option value="9">9</option>
    <option value="10">10</option>
</select>
```
I just changed the last one to :
```plaintext
<option value="500">Testing</option>
```
And obtained the flag.

## Solution 
