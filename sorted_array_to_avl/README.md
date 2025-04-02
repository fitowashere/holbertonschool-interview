# AVL Tree from Sorted Array

## Description
This project implements a function that builds an AVL (Adelson-Velsky and Landis) tree from a sorted array. An AVL tree is a self-balancing binary search tree where the difference between heights of left and right subtrees cannot be more than one for all nodes.

## Task
Write a function that builds an AVL tree from an array:
* Prototype: `avl_t *sorted_array_to_avl(int *array, size_t size);`
* Where `array` is a pointer to the first element of the array to be converted
* And `size` is the number of elements in the array
* The function must return a pointer to the root node of the created AVL tree, or `NULL` on failure
* There will be no duplicate values in the array
* No rotations are allowed
* Only 3 functions are allowed in the file

## Algorithm
The algorithm used in this project follows these steps:
1. Find the middle element of the array (or subarray) and use it as the root of the current subtree
2. Recursively build the left subtree using elements before the middle
3. Recursively build the right subtree using elements after the middle
4. Properly set parent pointers for all nodes

By always selecting the middle element as the root, we naturally create a balanced tree without needing any rotations.

## Files
- `0-sorted_array_to_avl.c`: Contains the implementation of the function that builds an AVL tree from a sorted array
- `binary_trees.h`: Header file with structure definitions and function prototypes
- `binary_tree_print.c`: Utility function for printing the tree (provided)

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
```

## Usage
```bash
./0-sorted_array_to_avl
```

## Example
```
Input array: [1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87, 91, 95, 98]

Output:
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)--.
(001)     (020)     (022)     (034)     (062)     (079)     (087)     (095)--.
                                                                           (098)
```

## Time and Space Complexity
- Time Complexity: O(n) where n is the number of elements in the array
- Space Complexity: O(n) for storing the tree nodes

## Author
Holberton School Student