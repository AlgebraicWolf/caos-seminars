theme: Ostrich, 3
slidenumbers: true

# [fit] Seminar 2
## [fit] **bash** scripts

---

# [fit] Recap: running the interpreter

# [fit] **#!/usr/bin/env bash**

---

# [fit] **/usr/bin/sh**
# [fit] symlink to **Bourne Shell**
# [fit] compatible shell

---
# Types of quotes

- Plain text: `'i love CAOS'`
- Execute command: `` `uname -o` ``
- Substitute variables: `"echo $my_var"`

---

# Variable syntax
```bash
var1=123
var2=
var_class = 'CAOS'
var3="i love $var_class!"

echo '$var1' "$var2" "$var3" "$another_var"
```
## **lack of spaces** IS important!
```bash
os_name = `uname -o` # Wrong, won't work
```

---

# Command output

```bash
os_name=$(uname -o)
arch=`uname -m`

echo "Running $os_name on $arch"
```

---

# Magic variables
- **$?** Return code of last command
- **$0**...**$9** Arguments
- **$#** Number of argumentrs
- **$@** Argument list
- **$\*** String with list of arguments

---

# Function definitions

Three ways of declaring functions:

```bash
very_important_function() {
  # function definition
}

function very_important_function() {
  # function definition
}

function very_important_function {
  # function definition
}
```

---

**Only first** is compatible with **sh**
Function arguments are accessible through **magic variables**

---

# Calling functions

Calling syntax:

```bash
value=$(very_important_function hello world)
very_important_function hello world
```

Variables inside functions are **global**
**bash** and **zsh** support **local** keyword

---

# [fit] Just like with **commands**
# [fit] function output
# [fit] can be **piped**

---

# [fit] Return value **0**
# [fit] means **success**
# [fit] or **truth**

---

# Conditional execution

- **cmd1 && cmd2** executes **cmd2** after **cmd1** finished **successfully**
- **cmd1 || cmd2** executes **cmd2** if **cmd1** has **failed**

**true** and **false** are **magic** programs

- **true** returns **0**
- **false** returns **1**

---

# **If** statements

```bash
if cmd
then
  # executed if cmd exited with zero
else
  # executed otherwise
fi
```

---

# **[** command (aka **test**)

```bash
if [ $x -eq $y ]
then
  # Do something when $x is equal to $y
elif [ $x -lt $y ]
then
  # Do something when $x is less than $y
fi
```

---

# **while** loop

```bash
while cmd
do
  # do something while return code is 0
done
```

---

# **for** loop

```bash
for item in <list>
do
  # Do something with an item
done
```

In **bash** and **zsh** we can use familiar syntax:

```bash
for (( i=0; i<10; i++ ))
do
  echo $i
done
```

---

# String as list

```bash
for item in $(echo "i love     CAOS")
do
  echo "$item"
done
```

---

# **IFS** specifies separator
```bash
IFS=':'
for item in $(echo 'i:love:CAOS')
do
  echo $item
done
```

---

# [fit] **sh** can execute arithmetic expressions inside **$(( ))**
# [fit] however
# [fit] only integers are supported

---

# [fit] For floating-point arithmetic
# [fit] use **bc -l**

---

# Text processing utilities

- **grep** for search/filtration
- **sed** and **awk** for editing

---

# [fit] **Demo**
# [fit] Searching for functions
# [fit] in **MANPATH**
