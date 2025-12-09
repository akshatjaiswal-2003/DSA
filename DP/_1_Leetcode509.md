# ✅ LeetCode 509 — **Fibonacci Number**  
**Difficulty: Easy**

---

## 1. 🔹 Problem Title + Short Summary  
**Fibonacci Number**  
Given an integer `n`, return the **n-th Fibonacci number**:

- F(0) = 0  
- F(1) = 1  
- F(n) = F(n-1) + F(n-2)

---

## 2. 🔹 How to Explain in an Interview (Step-by-Step, Story Style)

**Interviewer:** "Explain how you would compute the n-th Fibonacci number."

**You (step-by-step):**

1. “Fibonacci is a classic sequence where each number depends on the previous two.”  
2. “The most direct way is recursion — but it recomputes the same values again and again.”  
3. “I will first explain the brute-force recursion to show understanding of the mathematical definition.”  
4. “Then I will optimize it using Dynamic Programming (iterative approach) to bring time complexity down to linear.”  
5. “Finally, I will provide clean, optimized, interview-level code.”

---

## 3. 🔹 Brute Force Approach  
### **Idea**  
Use the recursive mathematical definition directly.

### ❗ Problem  
The same subproblems are recalculated → **exponential time**.

### **Time Complexity:** `O(2^n)`  
### **Space Complexity:** `O(n)` (recursion depth)

---

## 4. 🔹 Optimized Approach (Best for Interviews)
### **Approach: Bottom-Up Iterative DP**
- Fibonacci depends only on the **previous 2 values**.  
- Instead of a DP array, keep **two variables**.  
- Build the answer from `0` to `n`.

### **Why It Works**
- Removes repeated calculations  
- Uses constant memory  
- Clean, efficient, interview-friendly code  

### **Time Complexity:** `O(n)`  
### **Space Complexity:** `O(1)`

---

## 6. 🔹 Time & Space Complexity Summary
- Approach	Time Complexity	Space Complexity
- Optimized Iterative	O(n)	O(1)

---

## 7. 🔹 Extra: Pitfalls, Edge Cases & Tips to Impress the Interviewer
### ✅ Common Edge Cases

- n = 0 → return 0

- n = 1 → return 1

    ❗ Common Pitfalls

Using recursive approach without memoization → very slow

Missing base cases

Using formulas → may give floating-point inaccuracies

🌟 How to Impress the Interviewer

Mention alternative methods:

Memoization (Top-Down DP) → O(n) time, O(n) space

Matrix Exponentiation → O(log n) time

Binet’s Formula → constant time but inaccurate

Explain why iterative DP is ideal:

Readable

Fast

Low memory usage

Best practical solution