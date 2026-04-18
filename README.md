*This project has been created as part of the 42 curriculum by fulkaya.*

# Get_Next_Line 

## Description
Get_next_line is a project that involves creating a function in C that returns a line read from a file descriptor. The goal is to understand the behavior of static variables, memory management, and file manipulation in C.

The function handles repeated calls to read a text file one line at a time until the end of the file is reached. It is designed to be memory-efficient and handle different BUFFER_SIZE values.

### Bonus Part of the project
The bonus version supports simultaneous reading from multiple file descriptors by using a single static array of pointers, ensuring a seamless transition where the 'read offset' and state of each file are independently preserved.

## Instructions

1. Compilation

You can compile the mandatory part using cc with the following flags:

```bash
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

2. Compilation for Bonus Part

You can compile the bonus part (multiple file descriptors) using: 

```bash
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

### Algorithm & Technical Choices 

The algorithm is based on a "Read-Check-Store" logic:

1. **Buffer Management:** A temporary buffer of `BUFFER_SIZE` is used to read data from the file descriptor.

2. **Static Stash:** A static variable (`stash`) is used to store the data that has been read but not yet returned as part of a line.

3. **Line Extraction:** The stash is scanned for a newline character (`\n`). If found, the line is extracted, and the remaining data is saved back into the stash for the next call.

4. **Bonus Logic:** To manage multiple file descriptors, the static variable is declared as an array `static char *stash[MAX_FD]`, where each index corresponds to a unique file descriptor.

## Resources

[educative.io](https://www.educative.io/answers/read-data-from-a-file-using-read-in-c) to learn the read() function.

#### AI Usage Disclosure

Gemini (AI Assistant) was used for:

**Logic & Architecture:** Discussing how a static array handles multiple file descriptors independently and the lifecycle of static variables.

**Debugging:** Analyzing memory issues like `double free` and segmentation faults.

**Performance & Edge Cases:** Understanding why small `BUFFER_SIZE` values can lead to "timeout" issues and how the OS manages the file offset during `read()` calls.
