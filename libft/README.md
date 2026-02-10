*This project has been created as part of the 42 curriculum by okahrama.*

---

## Description

Libft is a C library project where fundamental functions from the standard C library are re-implemented from scratch. The goal is to learn memory management, string manipulation, and understand how standard library functions work internally.

The project is divided into three parts:
- **Part I:** Character checking, string operations, and memory functions
- **Part II:** Dynamic string allocation and file descriptor output
- **Part III:** Linked list data structure implementation

---

## Instructions

### Compilation

```bash
make              # Create libft.a
make clean        # Remove .o files
make fclean       # Remove .o and libft.a
make re           # Clean and recompile
```

### Using the Library

```c
#include "libft.h"

int main(void)
{
    char *str = "Hello";
    
    int len = ft_strlen(str);
    char *dup = ft_strdup(str);
    
    ft_putstr_fd(dup, 1);
    free(dup);
    
    return (0);
}
```

Compile with: `gcc -o program program.c -L. -lft`

---

## Functions Overview

### Part I - Standard Functions

**Character Checking:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`

**String Operations:** `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strnstr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`

**Memory Operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`

**Conversion:** `ft_atoi`

### Part II - Advanced Functions

**Dynamic Strings:** `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`

**Transformations:** `ft_itoa`, `ft_strmapi`, `ft_striteri`

**Output:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Part III - Linked Lists

**Basic Operations:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstlast`, `ft_lstsize`

**Deletion:** `ft_lstdelone`, `ft_lstclear`

**Iteration:** `ft_lstiter`, `ft_lstmap`

---

## Resources

- [GNU C Library Manual](https://www.gnu.org/software/libc/manual/)
- [C String Functions](https://www.tutorialspoint.com/c_standard_library/string_h.htm)
- [Memory Management in C](https://www.cprogramming.com/tutorial/memory_management.html)
- [Linux man pages](https://man7.org/linux/man-pages/)

---

## AI Usage

AI tools were used only for high-level explanations, conceptual guidance,
and understanding edge cases. No function implementations or code snippets
were generated or copied from AI tools.

---

**Author:** Taha Kahraman  
**School:** 42 Istanbul  
**Status:** Complete
