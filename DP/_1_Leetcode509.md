# ✅ LeetCode 509 — **Fibonacci Number**  
**Difficulty: Easy**

---

## 1. 🔹 Problem Title + Short Summary  
**Fibonacci Number**  
Given an integer `n`, return the **n-th Fibonacci number**:

F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)

yaml
Copy code

---

## 2. 🔹 How to Explain in an Interview (Step-by-Step, Story Style)

**Interviewer:** "Explain how you would compute the n-th Fibonacci number."

You (step-by-step):

1. “Fibonacci is a classic sequence where each number depends on the previous two.”

2. “The most direct way is recursion — but it recomputes the same values again and again.”

3. “I will first explain the brute-force recursion to show understanding of the mathematical definition.”

4. “Then I will optimize it using Dynamic Programming (iterative approach) to bring time complexity down to linear.”

5. “Finally, I will provide clean, optimized, interview-level code.”

---

## 3. 🔹 Brute Force Approach  
### **Idea**  
Use the recursive definition directly.

### ❗ Problem  
It recalculates the same subproblems → exponential time.

### **Time Complexity:** `O(2^n)`  
### **Space Complexity:** `O(n)` (recursion depth)

---

## 4. 🔹 Optimized Approach (Best for Interviews)
### Approach: **Bottom-Up Iterative DP**
- Fibonacci only depends on the **previous 2 values**.  
- So instead of storing an entire DP array, we maintain just **two variables**.  
- Build the answer from `0` to `n`.

### **Why it Works**
- Eliminates repeated computation  
- Maintains constant memory  
- Clean and efficient  

### **Time Complexity:** `O(n)`  
### **Space Complexity:** `O(1)`

---

## 5. 🔹 Optimized C++ Code (Interview-Level with Heavy Comments)

```cpp
class Solution {
public:
    int fib(int n) {
        // Direct base cases
        if (n == 0) return 0;
        if (n == 1) return 1;

        // prev2 = F(n-2), prev1 = F(n-1)
        int prev2 = 0;
        int prev1 = 1;

        int curr = 0;

        // Iteratively build the Fibonacci sequence
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;   // current Fibonacci number

            // Shift values for next iteration
            prev2 = prev1;
            prev1 = curr;
        }

        return curr; // The final computed Fibonacci number
    }
};
6. 🔹 Final Time & Space Complexity
Approach	Time Complexity	Space Complexity
Optimized Iterative	O(n)	O(1)

7. 🔹 Extra: Pitfalls, Edge Cases & Tips to Impress the Interviewer
✅ Common Edge Cases
n = 0 → return 0

n = 1 → return 1

❗ Common Pitfalls
Using recursion without memoization → extremely slow

Not handling base cases

Using formulas that may introduce floating-point errors

🌟 How to Impress the Interviewer
Mention alternate methods:

Memoization (Top-Down DP) → O(n) time, O(n) space

Matrix Exponentiation → O(log n) time

Binet’s Formula → constant time but inaccurate

Explain why iterative DP is preferred:

Most readable

Efficient

Minimal memory

Perfect for interview settings