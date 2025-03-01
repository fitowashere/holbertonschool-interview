# Palindrome Integer

## Description
This project implements a function that checks whether a given unsigned integer is a palindrome. A palindrome is a number that reads the same backward as forward.

## Requirements
- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- No dynamic memory allocation is allowed (malloc, calloc, etc.)

## Files
- `palindrome.h` - Header file with function prototype
- `0-is_palindrome.c` - Implementation of the palindrome checking function

## Function Prototype
```c
int is_palindrome(unsigned long n);
```
Where:
- `n` is the number to be checked
- The function returns `1` if `n` is a palindrome, and `0` otherwise

## Algorithm
The algorithm works by:
1. Storing the original number
2. Reversing the digits of the number
3. Comparing the reversed number with the original number
4. If they are equal, the number is a palindrome

## Compilation and Usage
```bash
$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
$ ./palindrome 12321
12321 is a palindrome.
$ ./palindrome 12345
12345 is not a palindrome.
```

## Examples
```
$ ./palindrome 1
1 is a palindrome.

$ ./palindrome 11
11 is a palindrome.

$ ./palindrome 112
112 is not a palindrome.

$ ./palindrome 121
121 is a palindrome.

$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.

$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.

$ ./palindrome 1234567898654321
1234567898654321 is not a palindrome.
```

## Time Complexity
- O(log n) where n is the input number (since we're processing each digit of the number)

## Space Complexity
- O(1) as we're using a constant amount of memory regardless of the input size
