# CPP Module 09 - Study Guide

## Prerequisites

- Code compiles with `c++` and flags `-Wall -Wextra -Werror`
- Must follow C++98 standard (no C++11 or later)
- STL containers are authorized
- No function implementations in header files (except templates)
- No C functions (`*alloc`, `*printf`, `free`)
- No external libraries
- Orthodox Canonical Form for all classes (default constructor, copy constructor, copy assignment operator, destructor)
- No segfault, no unexpected termination during defense
- No memory leaks

---

## Exercise 00: Bitcoin Exchange

### Container Used
- `std::map<std::string, float>` — stores date-rate pairs from the CSV database
- Why `std::map`: ordered by key (date string), allows `lower_bound()` lookup to find the nearest lower date in O(log n)

### What the Program Does
- Takes an input file as argument
- Reads a CSV database (`data.csv`) with historical bitcoin exchange rates
- For each line in the input file, multiplies the value by the exchange rate on that date
- Output format: `date => value = result`

### Key Concepts to Explain
- **std::map::lower_bound()**: returns an iterator to the first element with key >= given key. If the exact date is not found, decrement the iterator to get the nearest lower date
- **File parsing**: the database uses `,` as separator, the input uses ` | ` as separator
- **Date validation**: check format YYYY-MM-DD, valid month (1-12), valid day (1-31 considering month), leap year handling (divisible by 4, except centuries unless divisible by 400)
- **Value validation**: must be between 0 and 1000 inclusive, must be a valid number (float or int)

### Error Cases You Must Handle
| Input | Expected Output |
|-------|-----------------|
| No arguments | `Error: could not open file.` |
| Nonexistent file | `Error: could not open file.` |
| Empty file | No output (no crash) |
| Missing ` \| ` separator | `Error: bad input => <line>` |
| Invalid date (`2001-42-42`) | `Error: bad input => <line>` |
| Negative value | `Error: not a positive number.` |
| Value > 1000 | `Error: too large a number.` |
| Date before earliest in DB | Error message (program continues) |

### Important Rules
- The program must NOT stop execution when it encounters an error — it prints the error and continues processing the rest of the file
- If the date does not exist in the database, use the nearest lower (earlier) date

---

## Exercise 01: Reverse Polish Notation (RPN)

### Container Used
- `std::stack<int>` — LIFO structure for evaluating postfix expressions
- Why `std::stack`: RPN evaluation naturally follows a stack-based algorithm — push operands, pop two when an operator is found, push result
- **Must be a different container from ex00** (map vs stack)

### What the Program Does
- Takes a single string argument containing an RPN expression
- Evaluates the expression and prints the result
- Numbers are single digits only (0-9)
- Operators: `+`, `-`, `*`, `/`

### Key Concepts to Explain
- **Reverse Polish Notation**: operands come before operators. `3 4 +` means `3 + 4`
- **Stack-based evaluation algorithm**:
  1. Read tokens left to right
  2. If token is a number, push onto stack
  3. If token is an operator, pop two operands (b first, then a), compute `a op b`, push result
  4. At the end, the stack must contain exactly one element (the result)
- **Integer arithmetic**: all operations use integer division (truncation)

### Evaluation Test Cases
| Expression | Result |
|------------|--------|
| `8 9 * 9 - 9 - 9 - 4 - 1 +` | 42 |
| `9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -` | 42 |
| `1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /` | 15 |

### Error Cases
| Input | Expected |
|-------|----------|
| No arguments | `Error` |
| Empty string | `Error` |
| Parentheses `(1 + 1)` | `Error` |
| Decimal numbers `1.5 2 +` | `Error` |
| Numbers > 9 `42 2 +` | `Error` |
| Division by zero `5 0 /` | `Error` |
| Too many operators `1 + +` | `Error` |
| Too many numbers `1 2 3 +` | `Error` |

### Walkthrough Example: `8 9 * 9 - 9 - 9 - 4 - 1 +`
```
Token  Stack
8      [8]
9      [8, 9]
*      [72]        (8 * 9)
9      [72, 9]
-      [63]        (72 - 9)
9      [63, 9]
-      [54]        (63 - 9)
9      [54, 9]
-      [45]        (54 - 9)
4      [45, 4]
-      [41]        (45 - 4)
1      [41, 1]
+      [42]        (41 + 1)
Result: 42
```

---

## Exercise 02: PmergeMe (Ford-Johnson Merge-Insert Sort)

### Containers Used
- `std::vector<int>` — contiguous memory, fast random access
- `std::deque<int>` — double-ended queue, fast insertion at both ends
- **Both must be different from ex00 (map) and ex01 (stack)**

### What the Program Does
- Takes a sequence of positive integers as arguments
- Sorts them using the Ford-Johnson merge-insert sort algorithm
- Displays: `Before:` (unsorted), `After:` (sorted), and timing for each container in microseconds
- Must implement the algorithm separately for each container

### Output Format
```
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : X us
Time to process a range of 5 elements with std::deque  : Y us
```

### Ford-Johnson Algorithm Steps
1. **Pair elements**: group the array into pairs. If odd count, save the last element as a "straggler"
2. **Compare pairs**: within each pair, order them so (smaller, larger)
3. **Recursively sort**: take all the "larger" elements and recursively sort them
4. **Build main chain**: the sorted larger elements form the main chain. Insert the first smaller element (paired with the smallest larger) at the beginning
5. **Insert pending elements**: insert the remaining smaller elements into the main chain using binary search, following the **Jacobsthal number sequence** for insertion order
6. **Insert straggler**: if there was an odd element, insert it at the end using binary search

### Jacobsthal Numbers
The sequence determines the optimal insertion order to minimize comparisons:
```
J(0) = 0
J(1) = 1
J(n) = J(n-1) + 2 * J(n-2)

Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, ...
```
Insertion order processes elements in groups defined by Jacobsthal boundaries, going backwards within each group. This ensures binary search is performed on the smallest possible sub-range.

### Why Two Containers
- **std::vector**: contiguous memory layout provides better cache performance for random access and binary search. Insertions in the middle are O(n) due to shifting
- **std::deque**: segmented memory with fast insertion at both ends. Middle insertions are still O(n) but may perform differently due to memory layout
- Evaluators expect you to explain the performance difference in timing results

### Error Cases
| Input | Expected |
|-------|----------|
| No arguments | `Error` |
| Negative numbers `-1 5 3` | `Error` |
| Non-numeric input `abc 2 3` | `Error` |
| Mixed invalid `1 2a 3` | `Error` |

### Evaluation Commands
```bash
# Manual test with 5-10 integers
./PmergeMe 3 5 9 7 4

# Stress test with 3000 random integers (OSX)
./PmergeMe $(jot -r 3000 1 1000 | tr '\n' ' ')

# Stress test with 3000 random integers (Linux)
./PmergeMe $(shuf -i 1-1000 -n 3000 | tr "\n" " ")
```

### Walkthrough Example: Sorting `[3, 5, 9, 7, 4]`
```
Input: [3, 5, 9, 7, 4]

Step 1 - Pair: (3,5), (9,7), straggler=4
Step 2 - Order pairs: (3,5), (7,9)
Step 3 - Largers: [5, 9] → recursively sort → [5, 9]
Step 4 - Reorder pairs by sorted largers: (3,5), (7,9)
Step 5 - Main chain: [3, 5, 9] (first smaller + all largers)
         Pend: [7]
Step 6 - Insert 7: binary search in [3, 5, 9] up to bound 9 → [3, 5, 7, 9]
Step 7 - Insert straggler 4: binary search → [3, 4, 5, 7, 9]

Result: [3, 4, 5, 7, 9]
```

---

## Container Summary

| Exercise | Container | Reason |
|----------|-----------|--------|
| ex00 | `std::map` | Ordered key-value store, O(log n) lookup with `lower_bound` |
| ex01 | `std::stack` | LIFO structure matches RPN evaluation pattern |
| ex02 | `std::vector` + `std::deque` | Two different sequential containers for comparison |

All containers must be unique across exercises — no container type can repeat.
