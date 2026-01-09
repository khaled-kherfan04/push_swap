# Push Swap

*This activity has been created as part of the 42 curriculum by kkharfan.*

## Description

Push Swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The project involves two stacks (A and B) and a set of specific operations to manipulate them.

The goal is to sort stack A in ascending order using the most efficient algorithm possible. The program must output the sequence of operations needed to sort the stack, and the solution is evaluated based on the number of operations used.

This project teaches fundamental concepts in algorithm complexity, optimization, and data structure manipulation.

## Instructions

### Compilation

The project uses a Makefile with the following rules:

```bash
# Compile the project
make

# Clean object files
make clean

# Remove all compiled files
make fclean

# Recompile everything
make re
```

### Requirements

- GCC compiler
- `ft_printf` library (included in the `printf/` directory)
- Unix-based system (Linux/macOS)

### Execution

```bash
# Basic usage
./push_swap <numbers>

# Examples
./push_swap 3 2 1
./push_swap 5 4 3 2 1
./push_swap 42 17 8 23 91 -5

# With quoted arguments
./push_swap "3 2 1 5 4"
```

### Available Operations

- **sa** (swap a): Swap the first 2 elements at the top of stack A
- **sb** (swap b): Swap the first 2 elements at the top of stack B
- **ss**: sa and sb at the same time
- **pa** (push a): Take the first element at the top of B and put it at the top of A
- **pb** (push b): Take the first element at the top of A and put it at the top of B
- **ra** (rotate a): Shift up all elements of stack A by 1
- **rb** (rotate b): Shift up all elements of stack B by 1
- **rr**: ra and rb at the same time
- **rra** (reverse rotate a): Shift down all elements of stack A by 1
- **rrb** (reverse rotate b): Shift down all elements of stack B by 1
- **rrr**: rra and rrb at the same time

## Project Structure

```
push_swap/
├── Makefile
├── README.md
├── push_swap.h
├── main.c
├── parse_args.c
├── parse_strategy.c
├── error.c
├── stack_*.c           # Stack manipulation functions
├── op_*.c              # Operation functions (sa, pb, ra, etc.)
├── sort_*.c            # Sorting algorithm implementations
├── disorder.c          # Disorder metric calculation
├── benchmark.c         # Performance analysis
└── printf/             # ft_printf library
```

## Algorithm Explanation and Justification

### Overview of Implemented Algorithms

This project implements four different sorting strategies, each optimized for different input sizes and disorder levels:

#### 1. Simple Sort (O(n²))

**Used for:** 3-5 elements

**Justification:** For very small sets, simple algorithms are more efficient due to low overhead. The implementation includes:
- **sort_three()**: Hardcoded optimal solutions for 3 elements (max 2 operations)
- **sort_five()**: Pushes smallest elements to B, sorts remaining 3 in A, then pushes back

**Why it works:** With only 3-5 elements, the number of comparisons is minimal, and the overhead of complex algorithms would actually slow down the process.

#### 2. Medium Sort - Chunk-Based Algorithm (O(n√n))

**Used for:** 6-100 elements

**Algorithm:**
1. Divide the stack into √n chunks based on indices
2. Push elements to stack B in chunks (smallest to largest)
3. Push back from B to A in descending order (largest first)

**Justification:** 
- Reduces the problem into smaller, manageable subproblems
- Balances between simplicity and efficiency
- Chunk size of √n is mathematically optimal for this approach
- Significantly better than O(n²) for medium-sized inputs

**Example with 25 elements:**
- Creates 5 chunks (√25 = 5)
- Each chunk contains ~5 elements
- Processes chunks sequentially for O(n√n) complexity

#### 3. Complex Sort - Radix Sort (O(n log n))

**Used for:** 100+ elements

**Algorithm:**
1. Count the number of bits needed to represent the maximum value
2. For each bit position (LSB to MSB):
   - If bit is 0: push to B
   - If bit is 1: rotate in A
3. After processing each bit, push all from B back to A

**Justification:**
- Based on LSD (Least Significant Digit) radix sort
- Excellent for large datasets
- Predictable performance: always O(n log n)
- Works well with push_swap's limited operations
- No comparisons needed between elements

**Why Radix Sort for Push Swap:**
- Traditional comparison sorts (quicksort, mergesort) are difficult to implement efficiently with only stack operations
- Radix sort's bit-by-bit approach maps naturally to push/rotate operations
- Guarantees optimal complexity for large inputs

**Implementation Note:** The original implementation used bitwise operators (`>>`, `<<`, `&`) which were replaced with division and modulo operations to comply with norminette restrictions, maintaining the same algorithmic complexity.

#### 4. Adaptive Sort (Dynamic Selection)

**Used for:** Any size with intelligent selection

**Algorithm:**
1. Calculate disorder metric (0.0 = sorted, 1.0 = reversed)
2. Analyze stack size
3. Select the most appropriate algorithm:
   - size ≤ 3: sort_three()
   - size ≤ 5: sort_five()
   - size ≤ 100: sort_medium()
   - size > 100: sort_complex()

**Justification:**
- Adapts to input characteristics automatically
- Provides optimal performance across all input sizes
- Uses disorder metric to detect nearly-sorted inputs
- Most intelligent and versatile approach

### Disorder Metric

The disorder metric quantifies how "unsorted" a stack is by counting inversions (pairs of elements that are out of order):

```
disorder = number_of_inversions / total_possible_pairs
```

- **0.0**: Perfectly sorted
- **0.0-0.3**: Nearly sorted (low disorder)
- **0.3-0.7**: Moderate disorder
- **0.7-1.0**: Highly disordered (approaching reversed)

This metric helps the adaptive algorithm make intelligent decisions about which sorting strategy to use.

### Complexity Comparison

| Algorithm | Time Complexity | Space | Best For |
|-----------|----------------|-------|----------|
| Simple | O(n²) | O(1) | n ≤ 5 |
| Medium (Chunks) | O(n√n) | O(1) | 6 ≤ n ≤ 100 |
| Complex (Radix) | O(n log n) | O(1) | n > 100 |
| Adaptive | Varies | O(1) | All sizes |

### Performance Benchmarks

Expected operation counts for random inputs:

- **3 elements**: 0-2 operations
- **5 elements**: ≤12 operations
- **100 elements**: ~700 operations (chunk-based)
- **500 elements**: ~5500 operations (radix sort)

## Features

- ✅ Multiple sorting algorithms with automatic selection
- ✅ Error handling for invalid inputs
- ✅ Duplicate detection
- ✅ Support for negative numbers
- ✅ Disorder metric calculation
- ✅ Benchmark mode for performance analysis
- ✅ Memory leak free (valgrind tested)
- ✅ Norminette compliant

## Usage Examples

### Basic Sorting

```bash
# Sort 3 numbers
./push_swap 2 1 3
# Output: sa

# Sort 5 numbers
./push_swap 5 4 3 2 1
# Output: pb pb sa pa pa

# Large set
./push_swap 42 17 8 23 91 -5 67 34
```

### Error Cases

```bash
# Duplicate numbers
./push_swap 1 2 3 2
# Output: Error

# Non-numeric input
./push_swap 1 2 abc
# Output: Error

# Number overflow
./push_swap 2147483648
# Output: Error
```

## Resources

### Documentation & References

**Sorting Algorithms:**
- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [Big O Notation Cheat Sheet](https://www.bigocheatsheet.com/)
- [Sorting Algorithm Visualizations](https://visualgo.net/en/sorting)

**Push Swap Specific:**
- [42 Push Swap Subject](https://cdn.intra.42.fr/pdf/pdf/960/push_swap.en.pdf)
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Algorithm Complexity Analysis](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

**Data Structures:**
- [Linked Lists](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)

**42 Resources:**
- [Norminette Documentation](https://github.com/42School/norminette)
- [42 Coding Standards](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf)

### AI Usage
# push_swap
