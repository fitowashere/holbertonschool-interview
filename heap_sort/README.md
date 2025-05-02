# Heap Sort Implementation

## Description
This project implements the heap sort algorithm using the sift-down technique. Heap sort is an efficient comparison-based sorting algorithm that uses a binary heap data structure to sort elements in ascending order.

## Files
- `0-heap_sort.c`: Contains the implementation of the heap sort algorithm
- `0-O`: Contains the big O notations of the time complexity of the Heap sort algorithm
- `sort.h`: Header file containing function prototypes
- `print_array.c`: Utility function to print arrays (provided)

## Heap Sort Algorithm
Heap sort works by:
1. Building a max heap from the input array
2. Repeatedly extracting the maximum element from the heap and placing it at the end of the array
3. Reducing the heap size by one and sifting down the root element

The implementation follows these steps:
- First, build a max heap (where parent nodes are greater than or equal to their children)
- Then, extract elements one by one by swapping the root with the last element and sifting down

## Time Complexity
- Best case: O(nlog(n))
- Average case: O(nlog(n))
- Worst case: O(nlog(n))

## Usage
To compile and run the program:
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
./0-heap