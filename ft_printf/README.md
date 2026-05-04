*This project has been created as part of the 42 curriculum by okahrama.*

---

## Description

ft_printf is a C library project where the standard `printf()` function is re-implemented from scratch. The goal is to learn variadic functions, format specifiers, and understand how standard output functions work internally.

The project consists of multiple utility functions that handle different format specifiers and output operations.

---

## Instructions

### Compilation

```bash
gcc ft_printf.c ft_putchar.c ft_putint.c ft_putuint.c ft_putstr.c ft_puthex.c ft_puthexx.c ft_putaddr.c -o ft_printf
```

### Using the Library

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    count = ft_printf("Hello %s!\n", "World");
    ft_printf("Characters printed: %d\n", count);
    
    return (0);
}
```

---

## Functions Overview

### Core Function

**Main Function:**
- `ft_printf()` - Re-implementation of standard printf function with variadic arguments

### Format Specifier Handlers

**Character Output:**
- `ft_putchar()` - Outputs a single character and returns 1

**Integer Output:**
- `ft_putint()` - Outputs a signed integer (handles negative numbers and INT_MIN edge case)
- `ft_putuint()` - Outputs an unsigned integer

**String Output:**
- `ft_putstr()` - Outputs a null-terminated string

**Hexadecimal Output:**
- `ft_puthex()` - Outputs unsigned integer in lowercase hexadecimal (0-9, a-f)
- `ft_puthexx()` - Outputs unsigned integer in uppercase hexadecimal (0-9, A-F)

**Address Output:**
- `ft_putaddr()` - Outputs pointer address in hexadecimal format

### Control Function

- `ft_control()` - Routes format specifiers to appropriate handler functions

---

## Supported Format Specifiers

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Character | `ft_printf("%c", 'A')` → `A` |
| `%d` | Signed integer | `ft_printf("%d", -42)` → `-42` |
| `%i` | Signed integer (same as %d) | `ft_printf("%i", 123)` → `123` |
| `%u` | Unsigned integer | `ft_printf("%u", 42u)` → `42` |
| `%x` | Lowercase hexadecimal | `ft_printf("%x", 255)` → `ff` |
| `%X` | Uppercase hexadecimal | `ft_printf("%X", 255)` → `FF` |
| `%s` | String | `ft_printf("%s", "hello")` → `hello` |
| `%%` | Percent sign | `ft_printf("%%")` → `%` |

---

## How It Works

1. `ft_printf()` parses the format string character by character
2. When a `%` is encountered, it reads the next character as a format specifier
3. `ft_control()` handles the conversion and calls the appropriate function
4. Each function writes output using `write()` system call and returns character count
5. The total character count is accumulated and returned

### Key Implementation Details

- All functions return the number of characters printed
- Recursive functions used for recursive digit/hex conversion
- Handles edge cases like INT_MIN (-2147483648)
- Uses `write()` for low-level output
- Supports variadic arguments with `va_list`

---

## Compilation with Header

```bash
# To compile with header protection
gcc -c ft_printf.c -o ft_printf.o
gcc -c ft_putchar.c -o ft_putchar.o
gcc -c ft_putint.c -o ft_putint.o
gcc -c ft_putuint.c -o ft_putuint.o
gcc -c ft_putstr.c -o ft_putstr.o
gcc -c ft_puthex.c -o ft_puthex.o
gcc -c ft_puthexx.c -o ft_puthexx.o
gcc -c ft_putaddr.c -o ft_putaddr.o
gcc *.o -o ft_printf
```

---

## Resources

- [Standard Input/Output Library (stdio.h)](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic Functions in C](https://www.cprogramming.com/tutorial/c/lesson17.html)
- [Standard Write Function](https://man7.org/linux/man-pages/man2/write.2.html)
- [Hexadecimal Number System](https://www.tutorialspoint.com/computer_fundamentals/number_system_conversion.htm)
- [Linux man pages](https://man7.org/linux/man-pages/)

---

## Testing

To test the implementation:

```c
int main(void)
{
    ft_printf("char:%c\nint=%d\nint=%i\nuint=%u\nstring=%s\nhexvalue=%x\nhexxvalue=%X\n%%=%%\n", 
              'a', 1000, 1000, 1000, "aaa", 1000, 1000);
    return (0);
}
```

Compare output with standard `printf()` to verify correctness.

---


---

## Files

- `ft_printf.h` - Header file with function prototypes
- `ft_printf.c` - Main printf function and control router
- `ft_putchar.c` - Character output function
- `ft_putint.c` - Signed integer output function
- `ft_putuint.c` - Unsigned integer output function
- `ft_putstr.c` - String output function
- `ft_puthex.c` - Lowercase hexadecimal output function
- `ft_puthexx.c` - Uppercase hexadecimal output function
- `ft_putaddr.c` - Pointer address output function

---
## AI Usage

AI tools were used in this project only for understanding theoretical concepts and gaining guidance. No code implementations or code snippets were generated or copied from AI tools. The entire implementation was written manually from scratch.

AI assistance was sought to understand the following concepts: how variadic functions work using `va_list`, `va_start`, and `va_arg` macros for functions that accept a variable number of arguments like printf; how format specifier parsing and string processing mechanisms work when parsing format strings; how to implement recursive digit and hexadecimal conversion algorithms; how system-level output operations work through the `write()` system call; and considerations for proper memory and buffer management when counting printed characters. The theoretical guidance helped me understand these concepts deeply, but all the actual code was written independently through hands-on implementation and problem-solving.

**Author:** Omer Kahraman  
**School:** 42 Istanbul  

