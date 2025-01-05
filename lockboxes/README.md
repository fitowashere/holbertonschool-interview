# Lockboxes

## Description
This project contains a Python function that determines if all the boxes in a set of locked boxes can be opened. Each box is numbered sequentially from 0 to n-1 and may contain keys to other boxes. The first box (boxes[0]) is unlocked by default.

## Task: Can Unlock All
Write a method that determines if all boxes can be opened.

### Function Prototype
```python
def canUnlockAll(boxes)
```

### Parameters
- `boxes`: A list of lists where each inner list contains keys (integers) to other boxes

### Return Value
- `True`: if all boxes can be opened
- `False`: if not all boxes can be opened

### Requirements and Constraints
- All keys are positive integers
- A key with the same number as a box opens that box
- There can be keys that do not have corresponding boxes
- The first box `boxes[0]` is unlocked by default
- Boxes may be empty (contain no keys)

## Examples

### Example 1: All boxes can be opened sequentially
```python
boxes = [[1], [2], [3], [4], []]
result = canUnlockAll(boxes)
# Returns: True
```

### Example 2: All boxes can be opened through various paths
```python
boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
result = canUnlockAll(boxes)
# Returns: True
```

### Example 3: Not all boxes can be opened
```python
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
result = canUnlockAll(boxes)
# Returns: False
```

## Algorithm Overview
1. Initialize tracking of unlocked boxes (first box is unlocked)
2. Keep track of available keys not yet used
3. For each available key:
   - If it opens a new box, mark it as unlocked
   - Add any new keys found to the set of available keys
4. Continue until no more keys are available or all boxes are unlocked
5. Return True if all boxes are unlocked, False otherwise

## Time Complexity
- Worst case: O(n + k) where n is the number of boxes and k is the total number of keys

## Space Complexity
- O(n) for tracking unlocked boxes and storing available keys

## Repository Information
- GitHub repository: `holbertonschool-interview`
- Directory: `lockboxes`
- File: `0-lockboxes.py`

## License
This project is part of the Holberton School curriculum.