# Simple Shell
![sharpiesh_logo](https://raw.githubusercontent.com/wescottsharples/simple_shell/master/img/sharpieshlogo.png)
## About
Modeled after the first [Unix shell](https://en.wikipedia.org/wiki/Thompson_shell) by Ken Thompson, the `sharpie shell` (hereinafter referred to as `sharpiesh`) handles commands located in the [$PATH](https://en.wikipedia.org/wiki/PATH_%28variable%29) and supports a number of additional, built-in features listed below.

### Built-In Commands
| Built-in | Use |
|--|--|
| `exit` | exits the shell |
| `env` | prints the current environment |

### Additional Features
- Handles file as piped input
- Handles multiple commands seperated by ';' delimeter
- Contains no memory leaks

## Getting Started
A starter's guide to setting up `sharpiesh`.

### 1. Install
To download a copy of the source code locally, please run the following command in your terminal:
```
$ git clone https://github.com/wescottsharples/simple_shell.git
```

### 2. Compile
After downloading the source code, you can use the following command to compile a working version of the shell:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o 'sharpiesh'
```

### 3. Use
`sharpiesh` should now be ready to use. To start the shell in interactive mode, please use the following command:
```
./sharpiesh
```
You should now see a `$`, which means `sharpiesh` is awaiting input. 
## Executing Commands
There are many commands you can execute from within `sharpiesh`. A comprehensive list of available Unix commands can be found [here](https://courses.cs.washington.edu/courses/cse391/16sp/bash.html). Below are some examples of things you can try.

---------
### `ls -l`

`ls` lists the contents of your current directory. The `-l` flag specifies the listing should be in long format.

```
$ ls -l
total 28
-rwxrwxr-x 1 vagrant vagrant 18533 Nov 18 21:50 a.out
-rw-rw-r-- 1 vagrant vagrant   746 Nov 18 21:50 shell.c
drwxrwxr-x 2 vagrant vagrant  4096 Nov 18 21:50 simple_shell
-rw-rw-r-- 1 vagrant vagrant     0 Nov 18 21:49 words.txt
```
---------
### `echo anything`
`echo` displays a line of text. It takes a string of characters to be displayed as an argument.
```
$ echo anything
anything
```
---------
### `touch file.txt`
`touch` creates a new file in the current directory. It takes a file name, such as `file.txt` as an argument.
```
$ touch file.txt
$ ls
a.out  file.txt  shell.c  simple_shell	stuff.txt
```
---------
### `rm file.txt`
`rm` deletes a file. It takes a file name, such as `file.txt` as an argument.
```
$ rm file.txt
$ ls
a.out  shell.c  simple_shell	stuff.txt
```
---------
### `exit`
`exit` exits the shell.
```
$ exit
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$
```
---------
### `man`
To view documentation on each command, you can use `man` followed by the command you would like to know more about. For example, `man ls` will display information about the command `ls`. 

## Interactive vs. Non-Interactive Mode
You can use the shell in both interactive and non-interactive mode. The examples above are done in interactive mode. You can tell because the shell runs continuously, awaiting and executing commands, until you explicitly `exit`.

Non-interactive mode, however, is when you indirectly feed commands into the executable `hsh` file from outside the shell. For example, we can list files by indirectly piping `ls` into `hsh` using `echo`:
```
$ echo "ls" | ./hsh
a.out  shell.c  simple_shell	stuff.txt
```

## Environment Information
This shell was built and tested in the following environment by [Samie Azad](https://github.com/sazad44) and [Wescott Sharples](https://github.com/wescottsharples) as a project for [Holberton School](https://www.holbertonschool.com/).

| Feature | Version |
|--|--|
| **Language** | C |
| **Operating System** | Ubuntu 14.04 LTS |
| **Compiler** | `gcc 4.8.4` |
| **Style Guidelines** | [`Betty`](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") |

To test `sharpiesh`, or any other Unix shell, you can use this [test suite](https://github.com/stefansilverio/test_suite) developed by our classmates for this project.
