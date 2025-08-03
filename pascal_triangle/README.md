# Pascal's Triangle Generator

A Python implementation that generates Pascal's triangle with n rows.

## Description

Pascal's triangle is a triangular array of numbers where each number is the sum of the two numbers directly above it. The triangle starts with 1 at the top, and each row begins and ends with 1.

```
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
```

## Function

### `pascal_triangle(n)`

Returns a list of lists of integers representing Pascal's triangle of n rows.

**Parameters:**
- `n` (int): Number of rows in Pascal's triangle

**Returns:**
- `list`: List of lists representing Pascal's triangle
- Returns an empty list if `n <= 0`

**Time Complexity:** O(n²)  
**Space Complexity:** O(n²)

## Usage

```python
from pascal_triangle import pascal_triangle

# Generate Pascal's triangle with 5 rows
triangle = pascal_triangle(5)
print(triangle)
# Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]

# Edge cases
print(pascal_triangle(0))  # []
print(pascal_triangle(-1)) # []
print(pascal_triangle(1))  # [[1]]
```

## Example Output

Running the provided test file:

```bash
$ ./0-main.py
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
```

## Algorithm

1. Handle edge case: return empty list if `n <= 0`
2. Initialize empty triangle list
3. For each row `i` from 0 to `n-1`:
   - Start row with `[1]`
   - For interior positions, calculate value as sum of two elements above
   - Add ending `1` for rows with more than one element
4. Return completed triangle

## Mathematical Properties

Pascal's triangle has many interesting mathematical properties:

- **Binomial coefficients**: Each element at position (n,k) equals C(n,k)
- **Symmetry**: Each row is symmetric
- **Sum of row**: The sum of row n equals 2^n
- **Fibonacci sequence**: Sum of diagonals gives Fibonacci numbers
- **Powers of 11**: Small rows represent powers of 11 (11^0=1, 11^1=11, 11^2=121, etc.)

## File Structure

```
├── 0-pascal_triangle.py    # Main implementation
├── 0-main.py              # Test file
└── README.md              # This file
```

## Requirements

- Python 3.x
- No external dependencies

## Testing

The implementation includes comprehensive testing for:
- Normal cases (n = 1, 2, 5, etc.)
- Edge cases (n ≤ 0)
- Large values of n

Run the test file to verify functionality:

```bash
python3 0-main.py
```