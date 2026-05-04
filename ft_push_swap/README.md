# push_swap

*This project has been created as part
of the 42 curriculum by okahrama and okahrama.*

---

## Description

Push_swap is a project that involves sorting a stack of integers using a limited set of operations and two stacks (stack A and stack B). The goal is to sort the stack in ascending order with the fewest possible operations.

This project demonstrates efficient algorithm selection and implementation in C, focusing on optimization for different input sizes and disorder levels. The program takes a list of integers as input and outputs a sequence of operations that, when applied to the initial stack, result in a sorted stack in ascending order.

---

## Instructions

### Compilation

```bash
make              # Create push_swap executable
make clean        # Remove .o files
make fclean       # Remove .o and executable
make re           # Clean and recompile
```

### Execution

```bash
./push_swap 3 1 4 1 5              # Basic usage
./push_swap --simple 5 2 8 1 9     # Force selection sort
./push_swap --medium 10 9 8 7 6    # Force chunk sort
./push_swap --complex 100 50 25    # Force radix sort
./push_swap --adaptive 4 3 2 1     # Auto-select algorithm
./push_swap --bench 5 3 1 4 2      # Run with benchmarking
```

### Requirements

- Input must be a list of unique integers
- Integers must be within the range of a signed 32-bit integer
- Invalid input (duplicates, non-integers, overflow) results in "Error"

---

## Algorithms

### Part I - Selection Sort (Simple)

**Description:** Repeatedly finds the minimum element from the unsorted portion and moves it to stack B, then pushes everything back to A.

**Time Complexity:** O(n²)

**Justification:** Suitable for very small lists (≤5 elements). Minimizes overhead with straightforward operations; efficiency loss is negligible at tiny scales.

**Operations Used:** `sa`, `pa`, `pb`, `ra`, `rb`

---

### Part II - Chunk Sort (Medium)

**Description:** Divides the input into chunks based on computed indices, pushes elements to B in chunk order, then sorts back by finding and rotating the maximum index in B.

**Time Complexity:** O(n√n)

**Justification:** Optimal for medium-sized lists (100-500 elements). Balances operation count and efficiency by reducing unnecessary rotations while staying within practical push_swap constraints.

**Operations Used:** `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`

---

### Part III - Radix Sort (Complex)

**Description:** Sorts by binary representation of indices, processing one bit at a time. Elements are pushed to B based on the current bit value, then pushed back to A.

**Time Complexity:** O(n log n)

**Justification:** Optimal for large lists (500+ elements). Leverages the stable nature of radix sort with push_swap operations, minimizing total moves for highly disordered inputs.

**Operations Used:** `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`

---

## Features

- **Error Handling:** Validates input for duplicates, invalid characters, and integer overflow
- **Multiple Algorithms:** Selection, Chunk, and Radix sort implementations
- **Adaptive Mode:** Automatically selects the best algorithm based on input disorder
- **Benchmarking:** Displays disorder percentage, chosen strategy, and operation counts
- **Modular Design:** Separate files for parsing, algorithms, operations, and utilities
- **Linked List Stack:** Custom implementation with all push_swap operations

---

## Stack Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first two elements of stack A |
| `sb` | Swap first two elements of stack B |
| `ss` | Execute `sa` and `sb` |
| `pa` | Push top of B to A |
| `pb` | Push top of A to B |
| `ra` | Rotate stack A upwards |
| `rb` | Rotate stack B upwards |
| `rr` | Execute `ra` and `rb` |
| `rra` | Reverse rotate stack A |
| `rrb` | Reverse rotate stack B |
| `rrr` | Execute `rra` and `rrb` |

---

## Resources

- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm) - Overview and complexity analysis
- [Introduction to Algorithms](https://mitpress.mit.edu/9780262033848/introduction-to-algorithms/) - Cormen et al.
- [Radix Sort](https://www.geeksforgeeks.org/radix-sort/) - Implementation and explanation
- [C Linked Lists](https://www.geeksforgeeks.org/linked-list-in-c/) - Data structure fundamentals
- [Push_swap 42 Project](https://github.com/42School/push_swap) - Official project

---

## AI Usage

AI tools were used for:
- **Code review and optimization suggestions** for radix sort bit manipulation
- **Identifying edge cases** in input parsing and operation counting
- **Algorithm explanation** and complexity analysis validation
- **Benchmarking output formatting**

All core algorithm implementations, logic design, and debugging were completed by the developers.

---

**Authors:** okahrama, okahrama  
**School:** 42 Istanbul  
**Language:** C
