---
paginate: true
---


# Linux Basics
Ashish Thapa

![bg left fit](assets/linux.png)

---
<style scoped>
     ul * {
        font-size: 14px;
    }
</style>
# Topics Covered

- SSH
- Bandit overthewire
- Where to practice if there is no linux machine
- What is shell
- most common used commands in linux  
- linux filesystem  explained
- permissions
- Redirections and piping
- where are my configuration files
- Environment variables
- how to install packages
- building apps from scratch
- Multiplexing and editors
- Process management



---

# bandit over the wire 
https://overthewire.org/wargames/bandit/

## `ssh bandit0@bandit.labs.overthewire.org -p 2220`

password: `bandit0`

----

# SSH (Secure Shell Protocol)

- Network protocol that uses cryptographic means
- SSH is enabled on linux through `openssh-server`
- `private key` and `public key` generated with `ssh-keygen`

```
Further Resources
what are private and public keys: https://www.preveil.com/blog/public-and-private-key/

```

---
<style scoped>
    * {
        font-size : 25px;
    }
</style>

# How to connect to server that accepts SSH connection

- Head to your Terminal (cmd, powershell, fish, alacritty, iTerm etc)  

`ssh username@host -p 1234`
`ssh ashish@hpc.ku.edu.np -p 3434`

- useful flags 
    - for verbose(detailed) output
       `ssh -vvv username@host -p 1234`
    - Run one command and exit  
        `ssh username@host -p 2345 'command'`
        `ssh ashish@hpc.ku.edu.np -p 3434 'ls'`

```
further Resources
Connect to server without Typing password: https://linuxhint.com/ssh-using-private-key-linux/
ssh config file: https://linuxhint.com/ssh-config-file/
```

---

# To practice if you don't have a linux machine?

- Windows 
    - install Windows Subsystem for Linux
    - use virtualbox and install linux there
- Macintosh
    - already has a POSIX complaint shell like Zsh, bash etc 
<!-- - login to our hpc server -->

---

# Basics of Linux

### Shell
- interface between user and operating system tools. 
    - Example of CLI shells: `command prompt` , `powershell` , `bash` , `nushell`, `zsh`
    - Example of Graphical shells: `X Window manager`, `Finder`, `Windows shell (DE), startmenu , taskbar` 

-  Linux Shells
    - POSIX complaint : bash , zsh
    - Non POSIX complaint: fish, nushell

```
What is POSIX complaint shell : https://en.wikipedia.org/wiki/POSIX
```

----

# Commonly used commands on Linux Shells

- `pwd` : present working directory
- `ls` : list files 
- `mkdir`: make directory
- `cd` :  change directory
- `rm` : remove files and directory
- `man` : manual pages
- `help` : find help

> Install a tool `tldr` which gives examples for most use cases for that command . 
> Example: `tldr find`, `tldr youtube-dl`

```
Most used commands in linux: https://linuxjourney.com/lesson/the-shell
```


----

# Linux Directory Structure explained


|name|type|Description|
|-|-|-|
|bin|Symlink|Shortcut of /usr/bin/ that contains executables|
|boot|Dir|contains configuration of bootloader, tools to mount filesystem|
|dev|Dir|contains device files| 
|etc|Dir|contains systemwide configuration of linux tools|


```
https://askubuntu.com/questions/1103937/explain-in-linux-and-unix-everything-is-a-file
```


---

|name|type|Description|
|-|-|-|
|home|Dir|Contains User specific directories|
|lib|Symlink|Shortcut of /usr/lib/ which contains library files `*.so` similar to `.dll` in windows|
|opt|Dir|Generally used to store proprietary apps such as google chrome, clion etc |
|proc|Dir|contains information relating to process that is currently running|
|root|Dir|root specific directory|
|sbin|Symlink|system executables also might be symlink to /usr/bin|

----

|name|type|Description|
|-|-|-|
|home|Dir|Contains User specific directories|
|tmp|Dir|Temporary files|
|usr|Dir|contains utilities and applications + system executables|
|var|Dir|contains variable data, that changes during operation such as logs|

----

# Permissions



- Permissions on linux are on three levels
- user permissions, group permissions, and other permissions
- each level can either read, write or execute 

```
r -> read | w -> write | x -> execute | d -> directory
```

`> ls -la`
`wallpapers  drwxr-xr-x`


`drwxr-xr-x` can be divided into `d` | `rwx` | `r-x`| `r-x`

```
changing owner, group and permissions : https://www.oreilly.com/library/view/running-linux-third/156592469X/ch04s14.html

chown command explained: https://www.computerhope.com/unix/uchown.htm

```
----

# Piping / Redirecions

- Redirection of output to some other destination
- `|` , `>` , `<` , `&>` etc

```
Bash manual for Redirections : https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html#Redirections

```

--- 
# Where are my configuration files

- Home directory is represented by `~`  
- usually configuration files are stored as hidden files , files that start with `dot(.)` . `ls -a` shows hidden files too.
- usually inside `.config` folder.
- configuration has its own markup languages too such as yaml, json, toml or its own type.

---

# Environment variables

- `$HOME`, `$USER`, `$PATH` etc

```
https://www.geeksforgeeks.org/environment-variables-in-linux-unix/

https://linuxize.com/post/how-to-add-directory-to-path-in-linux/
```

---

# Installing packages 

- every popular distribution has one of the package manager for managing dependencies, installing software and removing them.
    - depends on Distribion of linux.

- Debian based: `apt`
- Arch based: `pacman`
- Fedora based: `dnf`

- .Appimage, .deb , .rpm  files can be installed appropriately.


---

# Building apps from scratch

Ubuntu : `sudo apt-get install build-essential`

- contains `make`, `g++`, `gcc` , `libc6-dev`, etc 

```
https://itsfoss.com/install-software-from-source-code/
```

---



# Multiplexing and Editing

### Multiplexing

- Multiple things might need to be run at a same time.    
- Multiplexing can help in that case `tmux`

### Editing configuration files 

- editors such as `Nano`, `vi` are present


```
https://linuxize.com/post/how-to-use-nano-text-editor/
https://www.hamvocke.com/blog/a-quick-and-easy-guide-to-tmux/
```

---
# Process management 

- `top`, `ps` 

```
https://www.geeksforgeeks.org/process-management-in-linux/
```
---

# other topics to explore

- cron jobs : https://phoenixnap.com/kb/set-up-cron-job-linux 
to write cron jobs view: https://crontab.guru/

- networking tools in linux  : https://www.geeksforgeeks.org/linux-networking-tools/ 
- sh scripting : https://ryanstutorials.net/bash-scripting-tutorial/
- system logs : https://stackify.com/linux-logs/

--- 





















