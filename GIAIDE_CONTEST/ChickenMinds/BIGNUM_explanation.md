# BIGNUM Algorithm Explanation

## Example Test Case
Input: `A79C3e8` and `k = 2`

## Step-by-Step Explanation

### 1. Initial Setup
- Input string: `A79C3e8`
- We need to keep `k = 2` digits
- Total length: 7 characters
- Need to delete: 7 - 2 = 5 characters

### 2. Remove Letters First
We scan the string and remove all letters:

| Index | Character | Action | String After | to_delete |
|-------|-----------|--------|--------------|-----------|
| 0     | 'A'       | Remove | `79C3e8`     | 4         |
| 0     | '7'       | Keep   | `79C3e8`     | 4         |
| 1     | '9'       | Keep   | `79C3e8`     | 4         |
| 2     | 'C'       | Remove | `793e8`      | 3         |
| 2     | '3'       | Keep   | `793e8`      | 3         |
| 3     | 'e'       | Remove | `7938`       | 2         |
| 3     | '8'       | Keep   | `7938`       | 2         |

After removing all letters, we have: `7938` and still need to delete 2 more characters.

### 3. Find Largest Number by Removing Digits
We use a greedy approach to keep the largest possible number:

| Character | Result Before | Action | Result After | to_delete |
|-----------|---------------|--------|--------------|-----------|
| '7'       | ""            | Add    | "7"          | 2         |
| '9'       | "7"           | 9>7, remove 7 | "9"   | 1         |
| '3'       | "9"           | 3<9, add | "93"       | 1         |
| '8'       | "93"          | 8>3, remove 3 | "98"  | 0         |

Final result: `98`

## Explanation of the Algorithm

1. **First Phase**: Remove all letters from the string
   - This is required by the problem since we want to form the largest number
   - Each letter removed decreases the `to_delete` count

2. **Second Phase**: Form the largest possible number with remaining digits
   - We use a stack-like approach (the `result` string)
   - For each digit:
     - If it's larger than the last digit in our result AND we still need to delete digits:
       - Remove the last digit (pop_back)
       - Decrease `to_delete`
     - Add the current digit to the result

3. **Final Phase**: If we still need to delete digits after processing all characters
   - Remove digits from the end of the result

This greedy approach works because:
- To maximize a number, we want larger digits in more significant positions
- When we encounter a larger digit, it's better to remove smaller digits that came before it