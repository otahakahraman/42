_This project has been created as part of the 42 curriculum by okahrama._

# Get Next Line (GNL)

> Read a line ending with a newline from a file descriptor.

---

## 📋 Description

### Project Overview

`get_next_line` (GNL) is a low-level C function project that implements a line reading utility from a file descriptor. The core function, `char *get_next_line(int fd)`, reads and returns lines from any valid file descriptor, one line at a time, efficiently managing memory with a configurable fixed buffer size.

### Project Goal

The primary goal of this project is to:
- **Implement efficient I/O operations**: Create a function that reads lines from files without loading entire files into memory
- **Master memory management**: Handle dynamic memory allocation and deallocation with precision
- **Understand static variables**: Learn how persistent state can be maintained across function calls using static storage
- **Handle edge cases robustly**: Correctly process files with/without trailing newlines, empty files, and multiple file descriptors (bonus)
- **Develop algorithmic thinking**: Implement a buffer management system that balances speed and memory efficiency

### Key Learning Outcomes

- Implement a function that reads and returns one line at a time from a file descriptor
- Learn to manage memory efficiently with a fixed, configurable buffer size
- Understand static variables and their persistence between function calls
- Handle edge cases (empty files, missing newlines, multiple FDs in bonus part)
- Work directly with system calls (`read`, `open`, `close`)
- Implement utility functions from scratch (`ft_strlen`, `ft_strjoin`, `ft_strdup`)

---

## 💻 Instructions

### Compilation & Installation

#### Mandatory Version
Compile the core implementation (single file descriptor support):
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 get_next_line.c get_next_line_utils.c -o gnl
```

#### Custom Buffer Size
You can adjust the `BUFFER_SIZE` at compilation time:
```bash
# Small buffer (use for testing edge cases)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4 get_next_line.c get_next_line_utils.c -o gnl

# Medium buffer (standard)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 get_next_line.c get_next_line_utils.c -o gnl

# Large buffer (better performance with large files)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=65536 get_next_line.c get_next_line_utils.c -o gnl
```

### Execution

#### Using the Function in Your Code
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Always free the returned line
    }
    close(fd);
    return (0);
}
```

#### Running with the Test Suite
```bash
# Navigate to the test directory
cd gnlTester

# Run mandatory tests
make test

# Run bonus tests (if implemented)
make bonus_test

# Clean test artifacts
make clean
```

### Requirements & Dependencies

- **C Compiler**: gcc, clang, or compatible
- **Standard Libraries**: `stdlib.h`, `unistd.h`, `fcntl.h`
- **System**: Unix-like OS (Linux, macOS, etc.)
- **Build Tool**: Makefile (included in gnlTester)

---

## ✨ Features

### Mandatory Part
- Reads from a single file descriptor at a time
- Returns complete lines (with newline character if present)
- Uses a static buffer to store unread content between calls
- Supports configurable `BUFFER_SIZE` via compilation flag


## 📚 Function Prototype

```c
char	*get_next_line(int fd);
```

### Parameters
- `fd`: File descriptor to read from (must be valid and opened for reading)

### Return Value
- **Success**: Returns a newly allocated string containing the next line (including `\n` if present)
- **EOF**: Returns `NULL` when end-of-file is reached
- **Error**: Returns `NULL` for invalid file descriptors or memory allocation failures

## 📁 Project Structure

```
├── get_next_line.h              # Header file (mandatory)
├── get_next_line.c              # Main function 
├── get_next_line_utils.c        # Utility functions
└── README.md                    # This file
```

## 🔧 Utility Functions

All of these are implemented by you:

- `ft_strlen()` - Calculate string length
- `ft_strjoin()` - Concatenate two strings with memory allocation
- `ft_strdup()` - Duplicate a string
- `have_next_line()` - Check if string contains newline

## 📋 Algorithm Overview

1. **Read Phase**: Read `BUFFER_SIZE` bytes into a temporary buffer
2. **Store Phase**: Join with existing stash (preserved content from previous calls)
3. **Extract Phase**: Extract the first line from stash
4. **Clean Phase**: Remove extracted line from stash and preserve remainder

## ⚠️ Important Notes

- The stash (static variable) persists between function calls
- Each call returns a newly allocated line that must be freed by caller
- Works with any file descriptor (not just regular files)
- Handles files without trailing newlines correctly
- Memory leaks occur if lines aren't freed

## ✅ Subject Compliance

- ✅ Follows 42 norm (coding standards)
- ✅ Uses only `malloc()`, `free()`, `read()`, `open()`, `close()`
- ✅ No global variables (only static inside function)
- ✅ Manages multiple FDs in bonus part
- ✅ Configurable buffer size

## 🐛 Common Issues

| Issue | Solution |
|-------|----------|
| Segmentation fault | Check FD validity, ensure `BUFFER_SIZE > 0` |
| Memory leaks | Always `free()` returned lines |
| Infinite loop | Ensure `BUFFER_SIZE` is positive |
| Non-blocking FD | Ensure file is opened for reading |

---

## 📚 Resources

### Official Documentation & References

1. **Man Pages**
   - `man read` - Read from file descriptor
   - `man open` - Open file or device
   - `man close` - Close a file descriptor
   - `man malloc` / `man free` - Memory management

2. **42 School References**
   - [42 Norminette Rules](https://github.com/42School/norminette) - C coding standards
   - [42 School Wiki](https://en.wikipedia.org/wiki/42_(school))
   - GNL Subject specification (available in 42 intranet)

3. **C Programming Tutorials**
   - [C Dynamic Memory](https://www.cprogramming.com/tutorial/memory_management.html)
   - [File I/O in C](https://www.cprogramming.com/tutorial/cfileio.html)
   - [Understanding Static Variables](https://www.geeksforgeeks.org/static-keyword-in-c/)

4. **Algorithm & Implementation Guides**
   - [Buffer Management Concepts](https://en.wikipedia.org/wiki/Data_buffer)
   - [Linked Lists in C](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)
   - GNL Testers on GitHub (e.g., gnl_tester, gnlTester)

### AI Usage

This project documentation and implementation was developed with assistance from **Claude (AI Assistant)**. Here's how AI was utilized:

#### Code Generation & Review
- **Initial Implementation**: Generated base implementations for `get_next_line()` function with proper state management using static variables
- **Bonus Version**: Created multi-FD version using linked list data structure for simultaneous file descriptor handling
- **Utility Functions**: Implemented `ft_strlen()`, `ft_strjoin()`, `ft_strdup()`, and `have_next_line()` helper functions
- **Code Review**: Ensured compliance with 42 School norm and subject requirements

#### Documentation
- **README Structure**: Designed comprehensive documentation following 42 School standards
- **Code Comments**: Added clear header comments following 42 Format standard
- **Usage Examples**: Created practical code examples demonstrating function usage
- **Testing Guide**: Documented test execution procedures and buffer size options

#### Problem Solving & Debugging
- **Memory Management**: Advised on proper allocation/deallocation patterns to prevent leaks
- **Edge Cases**: Identified and handled special cases (empty files, missing newlines, multiple FDs)
- **Static Variable Behavior**: Explained state persistence across function calls
- **Compilation Flags**: Guided proper use of BUFFER_SIZE parameter

#### Project Structure
- File organization following 42 conventions (mandatory + bonus)
- Makefile structure for test suite integration
- Header file organization and #ifndef guards

**Note**: This is educational documentation. All code should be reviewed, understood, and tested thoroughly before use. The AI assistance accelerated development while maintaining code quality and educational value.

---

## 📝 License

Made as part of 42 School curriculum.

---

**Author**: okahrama  
**42 School**: 42Istanbul
