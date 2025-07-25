# 0x08. C - Recursion

This project focuses on implementing recursive algorithms in C, specifically a wildcard string comparison function.

## Description

The main task is to create a function that compares two strings where one can contain wildcard characters. The wildcard `*` can match any sequence of characters, including an empty string.

## Requirements

### General
* Allowed editors: `vi`, `vim`, `emacs`
* All files will be compiled on Ubuntu 14.04 LTS
* Programs and functions compiled with `gcc 4.8.4` using flags `-Wall` `-Werror` `-Wextra` `-pedantic`
* All files should end with a new line
* Code should use the Betty style (checked with `betty-style.pl` and `betty-doc.pl`)
* No global or static variables allowed
* Maximum of 5 functions per file
* Standard library is not allowed
* **No loops of any kind are allowed**
* All function prototypes should be included in `holberton.h`

## Files

| File | Description |
|------|-------------|
| `holberton.h` | Header file containing function prototypes |
| `0-wildcmp.c` | Implementation of wildcard string comparison function |
| `0-main.c` | Test file (provided for testing, not required to submit) |

## Function Prototype

```c
int wildcmp(char *s1, char *s2);
```

## Function Description

**wildcmp** - Compares two strings with wildcard support

* **Parameters:**
  * `s1`: First string to compare
  * `s2`: Second string (can contain '*' wildcards)

* **Return Value:**
  * `1` if strings can be considered identical
  * `0` otherwise

* **Wildcard Rules:**
  * The `*` character in `s2` can replace any string (including empty string)
  * Multiple consecutive `*` characters are treated as a single `*`

## Usage Example

```c
#include "holberton.h"
#include <stdio.h>

int main(void)
{
    int result;
    
    result = wildcmp("main.c", "*.c");
    printf("%d\n", result); /* Output: 1 */
    
    result = wildcmp("main.c", "m*c");
    printf("%d\n", result); /* Output: 1 */
    
    result = wildcmp("main.c", "m.*c");
    printf("%d\n", result); /* Output: 0 */
    
    return (0);
}
```

## Test Cases

The function handles various scenarios:

* `"main.c"` vs `"*.c"` → `1` (matches)
* `"main.c"` vs `"m*a*i*n*.*c*"` → `1` (matches)
* `"main.c"` vs `"main.c"` → `1` (exact match)
* `"main.c"` vs `"m*c"` → `1` (matches)
* `"main.c"` vs `"ma********************************c"` → `1` (matches)
* `"main.c"` vs `"*"` → `1` (matches everything)
* `"main.c"` vs `"***"` → `1` (matches everything)
* `"main.c"` vs `"m.*c"` → `0` (literal dot doesn't match)
* `"main.c"` vs `"**.*c"` → `1` (matches)
* `"main-main.c"` vs `"ma*in.c"` → `1` (matches)
* `"main"` vs `"main*d"` → `0` (doesn't end with 'd')
* `"abc"` vs `"*b"` → `0` (doesn't end with 'b')

## Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
```

## Implementation Notes

The function uses pure recursion without any loops to comply with project requirements. The algorithm:

1. Handles base cases (end of pattern/string)
2. Processes wildcard characters recursively
3. Matches regular characters exactly
4. Uses backtracking to try different wildcard interpretations

## Author

This project is part of the Holberton School curriculum focusing on recursive algorithms and advanced C programming concepts.
