# Semester End Project - Design and Analysis of Algorithms (CS-2009)

## Project Title: Algorithmic Problem Solving with Time Complexity Analysis

### Authors:
- **Inam Ullah Shaikh (22I-0857 H)**
- **Abdul Munhim Hussain (22I-1021 H)**

## Overview
This project is submitted as part of the **Design and Analysis of Algorithms (CS-2009)** course. It focuses on solving algorithmic problems using dynamic programming, recursion, and other algorithmic strategies. The project includes pseudocode implementations and time complexity analysis for multiple problems.

## Table of Contents
1. [Problem 1: Structure Calculation](#problem-1-structure-calculation)
2. [Problem 2: Optimal Strategy Computation](#problem-2-optimal-strategy-computation)
3. [Problem 3: Algorithmic Problem](#problem-3-algorithmic-problem)
4. [Problem 4: Computational Optimization](#problem-4-computational-optimization)

---

## Problem 1: Structure Calculation
### Description:
This problem involves using dynamic programming to calculate structures efficiently.

### Pseudocode:
```pseudo
FUNCTION calculateStructures(n):
    for i = 0 to n:
        for j = 0 to n:
            if i = 0:
                dp[i][j] = 1
            else:
                dp[i][j] = 0
    
    for i = 1 to n:
        for j = 1 to n:
            if j <= i:
                dp[i][j] = dp[i][j - 1] + dp[i - j][j - 1]
            else:
                dp[i][j] = dp[i][j - 1]

    return dp[n][n - 1]
```
### Time Complexity Analysis:
- **Initialization**: O(n²)
- **DP Computation**: O(n²)
- **Overall Complexity**: O(n²)

---

## Problem 2: Optimal Strategy Computation
### Description:
This problem focuses on optimizing attack strategies using a dynamic programming approach.

### Pseudocode:
```pseudo
FUNCTION BestStrategy(DP, start, end, noofattacks):
    if end - start <= noofattacks:
        return 0
    if noofattacks == 0:
        return DP[start][end]
    if memo[start][noofattacks] != -1:
        return memo[start][noofattacks]
    
    result = INT_MAX
    for split = 0 to end - 1:
        right = BestStrategy(DP, split + 1, end, noofattacks - 1)
        left = DP[start][split]
        result = min(result, left + right)
    
    memo[start][noofattacks] = result
    return result
```
### Complexity Analysis:
- **Time Complexity**: O(n³)
- **Space Complexity**: O(n²)

---

## Problem 3: Algorithmic Problem
### Description:
This section presents another problem with a dynamic programming-based solution.

### Pseudocode:
```pseudo
FUNCTION computeValues(arr, size):
    dp = allocate 2D array of size [size][size]
    for i = 0 to size - 1:
        for j = i to size - 1:
            dp[i][j] = dp[i][j-1] + arr[j] * factor
    return dp[0][size-1]
```
### Complexity Analysis:
- **Time Complexity**: O(n²)

---

## Problem 4: Computational Optimization
### Description:
This section includes an optimization-based computational problem.

### Pseudocode:
```pseudo
FUNCTION optimizePath(graph, nodes):
    dp = initialize 2D array of size [nodes][nodes]
    for k = 0 to nodes - 1:
        for i = 0 to nodes - 1:
            for j = 0 to nodes - 1:
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
    return dp
```
### Complexity Analysis:
- **Time Complexity**: O(n³)

---

## Conclusion
This project implements and analyzes multiple algorithmic problems using **dynamic programming** and **recursion**. The solutions are evaluated based on their **time complexity** and **efficiency** in different scenarios. The findings provide a deeper understanding of the **design and analysis of algorithms**.

## How to Run
1. Clone this repository:
   ```sh
   git clone https://github.com/munhim/Algorithms-Project.git
   ```
2. Compile and run the programs in a suitable compiler.
3. Modify input values to test different cases.

---

## License
This project is for educational purposes only.

---

## Contact
For any queries, contact:
- **inamullahshaikh01@gmail.com**
- **munhim2002@gmail.com**

