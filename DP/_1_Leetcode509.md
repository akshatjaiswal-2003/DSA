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

1.  
   “Fibonacci is a classic sequence where each number depends on the previous two.”  

2.  
   “The most intuitive way is recursion — but that repeats a lot of work.”  

3.  
   “So first, I’ll explain the brute force recursion to show I understand the mathematical definition.”

4.  
   “Then I will optimize it using DP / iterative approach so the time complexity becomes linear.”

5.  
   “Finally, I will deliver clean, interview-level code.”

---

## 3. 🔹 Brute Force Approach  
### **Idea**  
Use the direct recursive definition.

### ❗ Problem  
This calculates the same values repeatedly → exponential blow-up.

### **Time Complexity:** `O(2^n)`  
### **Space Complexity:** `O(n)` (recursion stack)

---

## 4. 🔹 Optimized Approach (Best for Interviews)
### Approach: **Bottom-Up Iteration (Dynamic Programming)**  
This is the most commonly accepted optimal method.

### **Why it Works**
- Fibonacci only depends on **last two numbers**  
- So maintain only **two variables** → save memory  
- Compute iteratively from `0 → n`  

### **Time Complexity:** `O(n)`  
### **Space Complexity:** `O(1)` (only two variables)

---

## 5. 🔹 Interview-Level Optimized C++ Code (with heavy comments)

```cpp
class Solution {
public:
    int fib(int n) {
        // Base cases directly returned
        if (n == 0) return 0;
        if (n == 1) return 1;

        // prev2 -> F(n-2)
        // prev1 -> F(n-1)
        int prev2 = 0;
        int prev1 = 1;

        // curr -> F(i)
        int curr = 0;

        // Build the Fibonacci sequence from 2 to n
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;   // F(i) = F(i-1) + F(i-2)

            // Shift the variables for the next iteration
            prev2 = prev1;          // move F(i-1) to F(i-2)
            prev1 = curr;           // move F(i)   to F(i-1)
        }

        // Final value is our answer
        return curr;
    }
};
6. 🔹 Final Time & Space Complexity
Approach	Time Complexity	Space Complexity
Optimized Iterative	O(n)	O(1)

7. 🔹 Extra: Pitfalls, Edge Cases & Tips to Impress the Interviewer
✅ Common Edge Cases
n = 0 → output 0

n = 1 → output 1

❗ Common Pitfalls
Using recursion without memoization → TLE

Overflow in languages without long long (C++ OK for small n)

Not considering base cases

🌟 How to Impress the Interviewer
Mention that Fibonacci also has:

Memoization → O(n) time, O(n) space

Matrix exponentiation → O(log n)

Closed-form (Binet’s Formula) → inaccurate due to floating decimal errors

State why you choose iterative DP:

Fast

Clean

No large memory usage

Ideal for interviews