# AI Agent Instructions for DSA/CP Repository

## Project Overview
This repository is a personal collection of Data Structures and Algorithms (DSA) and Competitive Programming (CP) solutions implemented primarily in C++. The codebase includes solutions from various platforms like LeetCode, Codeforces, GeeksforGeeks, and InterviewBit.

## Repository Structure
```
/
├── TUF/                    # Take U Forward (Striver) sheet solutions
│   ├── Binary Trees/       # Tree problems & implementations
│   ├── Binary Search Trees/# BST-specific solutions
│   ├── dp/                # Dynamic programming by categories
│   │   ├── 1d/           # Linear DP problems
│   │   └── 2d/           # Grid/Matrix DP problems
│   └── graph/             # Graph algorithms & problems
├── stack/                 # Stack data structure problems
├── queue/                 # Queue data structure problems
├── codeforce/            # Codeforces contest solutions
└── revision/             # Practice problems by topic
```

## Code Conventions

### Common Patterns
1. Standard Template:
```cpp
#include <bits/stdc++.h>
using namespace std;
// Problem-specific code
void solve() {
    // Solution logic
}
int main() {
    // Input/test cases handling
}
```

2. Data Structure Templates:
- Trees: Use `struct TreeNode` with `data`, `left`, `right` pointers
- Standard implementation in `my_cp_style.cpp` for common utilities

### Competitive Programming Style
From `my_cp_style.cpp`:
- Use `#define int long long` for integer overflow prevention
- Common shortcuts: `pb` (push_back), `ff` (first), `ss` (second)
- Vector shortcuts: `vi` (vector<int>), `pii` (pair<int,int>)
- Input/Output optimization: Use `fastIO()` function

## Solution Organization
1. Problem solutions are organized by:
   - Platform (Codeforces, LeetCode)
   - Topic (dp, trees, graphs)
   - Difficulty level

2. Each solution typically includes:
   - Problem statement in comments
   - Time/Space complexity analysis
   - Test cases (where applicable)
   - Optimized implementation

## Working with the Codebase

### Best Practices
1. For new solutions:
   - Follow the existing directory structure
   - Use the template from `my_cp_style.cpp`
   - Include problem link/source in comments
   - Document complexity analysis

2. For optimizations:
   - Keep both brute force and optimized versions
   - Clearly mark improvements in comments
   - Maintain test cases for verification

### Common Utilities
1. Important functions in `my_cp_style.cpp`:
   - `fastIO()` for input/output optimization
   - `buildSparse()` for sparse table preprocessing
   - PBDS tree for order statistics

2. Data structure implementations:
   - BST operations in `TUF/Binary Search Trees/`
   - Graph algorithms in `TUF/graph/`
   - Standard DP patterns in `TUF/dp/`

## Testing and Debugging
1. For local testing:
   - Use provided test cases in the problem
   - Add edge cases manually
   - Test with both small and large inputs

2. For contest problems:
   - Check time limits (usually 2s)
   - Verify memory constraints
   - Test corner cases carefully

## Resources
- Problem sources are mentioned in README.md
- Follow directory structure in `TUF/` for systematic learning
- Reference implementations available by topic