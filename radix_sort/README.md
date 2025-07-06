# Radix Sort Implementation

This project implements the **Radix Sort** algorithm using the **LSD (Least Significant Digit)** approach in C. Radix sort is a non-comparative sorting algorithm that sorts integers by processing individual digits.

## 📁 Project Structure

```
radix_sort/
├── README.md
├── sort.h
├── 0-radix_sort.c
├── print_array.c
└── 0-main.c
```

## 🔧 Files Description

### Core Implementation
- **`sort.h`** - Header file containing function prototypes
- **`0-radix_sort.c`** - Main radix sort implementation
- **`print_array.c`** - Utility function to print arrays (provided)
- **`0-main.c`** - Test file to demonstrate the algorithm

### Key Functions

#### `radix_sort(int *array, size_t size)`
- **Purpose**: Sorts an array of integers in ascending order using LSD radix sort
- **Parameters**: 
  - `array`: Pointer to the array to be sorted
  - `size`: Number of elements in the array
- **Assumptions**: Array contains only non-negative integers (`>= 0`)
- **Memory**: Uses `malloc` and `free` for temporary storage

#### `get_max(int *array, size_t size)`
- **Purpose**: Finds the maximum value in the array to determine digit count
- **Returns**: Maximum integer value

#### `counting_sort_radix(int *array, size_t size, int exp)`
- **Purpose**: Performs counting sort for a specific digit position
- **Parameters**:
  - `array`: Array to sort
  - `size`: Array size
  - `exp`: Current exponent (1 for units, 10 for tens, etc.)

## 🚀 How to Compile and Run

### Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

### Execution
```bash
./radix
```

### Expected Output
```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## 📊 Algorithm Analysis

### Time Complexity
- **Best Case**: O(d × (n + k))
- **Average Case**: O(d × (n + k))
- **Worst Case**: O(d × (n + k))

Where:
- `d` = number of digits in the maximum number
- `n` = number of elements
- `k` = range of digits (10 for decimal)

### Space Complexity
- **O(n + k)** for the output array and counting array

### Characteristics
- ✅ **Stable**: Maintains relative order of equal elements
- ✅ **Non-comparative**: Doesn't compare elements directly
- ✅ **Integer-specific**: Works with non-negative integers
- ⚠️ **Memory usage**: Requires additional space for sorting

## 🔍 Algorithm Steps

1. **Find Maximum**: Determine the number with the most digits
2. **Digit Processing**: For each digit position (starting from least significant):
   - Use counting sort to sort by current digit
   - Print the array after each pass
3. **Repeat**: Continue until all digit positions are processed

## 📝 Example Walkthrough

**Input**: `[19, 48, 99, 71, 13, 52, 96, 73, 86, 7]`

### Pass 1 - Sort by units digit (1s place):
- Original: `[19, 48, 99, 71, 13, 52, 96, 73, 86, 7]`
- Units: `[9, 8, 9, 1, 3, 2, 6, 3, 6, 7]`
- Result: `[71, 52, 13, 73, 96, 86, 7, 48, 19, 99]`

### Pass 2 - Sort by tens digit (10s place):
- Previous: `[71, 52, 13, 73, 96, 86, 7, 48, 19, 99]`
- Tens: `[7, 5, 1, 7, 9, 8, 0, 4, 1, 9]`
- Result: `[7, 13, 19, 48, 52, 71, 73, 86, 96, 99]`

**Final sorted array**: `[7, 13, 19, 48, 52, 71, 73, 86, 96, 99]`

## 🎯 Use Cases

Radix sort is particularly effective for:
- Sorting large datasets of integers
- When the range of input values is not significantly larger than the number of values
- Applications requiring stable sorting
- Systems with sufficient memory for the counting arrays

## ⚠️ Limitations

- **Integer-only**: Only works with non-negative integers
- **Memory overhead**: Requires additional space proportional to input size
- **Digit dependency**: Performance depends on the number of digits in the maximum value

## 🔧 Requirements

- **Compiler**: GCC with flags `-Wall -Wextra -Werror -pedantic`
- **C Standard**: C89/C90 compatible
- **Memory**: Dynamic allocation using `malloc` and `free`

## 📚 References

- [Radix Sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Introduction to Algorithms - CLRS](https://mitpress.mit.edu/books/introduction-algorithms)

---

