# Simple Shell

A basic command-line shell implemented in C that supports command execution, argument parsing, and built-in commands like `cd` and `exit`.

---

## Features

- Read user input commands from the terminal
- Parse commands and arguments
- Execute system commands using `fork()` and `execvp()`
- Built-in commands:
  - `cd` to change directories
  - `exit` to quit the shell
- Handles empty input gracefully

---

## How to Run

1. Clone or download the repository containing `simple_shell.c`.

2. Compile the program using GCC:

   ```bash
   gcc -o simple_shell simple_shell.c
