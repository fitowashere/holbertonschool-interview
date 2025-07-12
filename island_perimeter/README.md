# Island Perimeter

This project implements a solution to calculate the perimeter of an island represented in a 2D grid.

## Problem Description

Given a 2D grid where:
- `0` represents water
- `1` represents land
- Each cell is a square with side length 1
- Cells are connected horizontally/vertically (not diagonally)
- The grid is completely surrounded by water
- There is only one island (or no island)
- The island has no "lakes" (internal water not connected to surrounding water)

Calculate and return the perimeter of the island.

## Solution Approach

The algorithm works by:
1. Iterating through each cell in the grid
2. For each land cell (`1`), checking all 4 adjacent directions (up, down, left, right)
3. Counting how many sides of each land cell are exposed to water or grid boundaries
4. Summing up all exposed sides to get the total perimeter

### Algorithm Details

For each land cell at position `(i, j)`, we check:
- **Top**: If `i == 0` (top boundary) or `grid[i-1][j] == 0` (water above)
- **Bottom**: If `i == rows-1` (bottom boundary) or `grid[i+1][j] == 0` (water below)
- **Left**: If `j == 0` (left boundary) or `grid[i][j-1] == 0` (water to the left)
- **Right**: If `j == cols-1` (right boundary) or `grid[i][j+1] == 0` (water to the right)

Each exposed side contributes 1 to the total perimeter.

## Files

- `0-island_perimeter.py`: Main implementation file containing the `island_perimeter` function
- `0-main.py`: Test file to validate the solution

## Usage

```python
#!/usr/bin/python3
island_perimeter = __import__('0-island_perimeter').island_perimeter

# Example usage
grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]

print(island_perimeter(grid))  # Output: 12
```

## Example Walkthrough

For the given grid:
```
[0, 0, 0, 0, 0, 0]
[0, 1, 0, 0, 0, 0]  ← Land cell contributes 4 sides
[0, 1, 0, 0, 0, 0]  ← Land cell contributes 3 sides (shares 1 with cell below)
[0, 1, 1, 1, 0, 0]  ← Three land cells contribute 5 sides total
[0, 0, 0, 0, 0, 0]
```

**Perimeter calculation:**
- Top land cell: 4 exposed sides
- Middle land cell: 3 exposed sides (top, left, right)
- Bottom row land cells: 5 exposed sides total
- **Total perimeter: 4 + 3 + 5 = 12**

## Complexity Analysis

- **Time Complexity**: O(rows × cols) - We visit each cell once
- **Space Complexity**: O(1) - Only using constant extra space

## Constraints

- Grid dimensions do not exceed 100×100
- Grid is rectangular
- Contains only 0s and 1s
- Grid is completely surrounded by water
- Contains at most one island with no internal lakes

## Testing

Run the test file to validate the implementation:

```bash
./0-main.py
```

Expected output: `12`

## Repository Information

- **GitHub repository**: `holbertonschool-interview`
- **Directory**: `island_perimeter`
- **File**: `0-island_perimeter.py`