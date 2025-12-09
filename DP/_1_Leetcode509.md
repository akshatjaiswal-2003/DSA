# ✅ LeetCode 509 — **Fibonacci Number (Hinglish)**  
**Difficulty: Easy**

---

## 1. 🔹 Problem Title + Short Summary  
**Fibonacci Number**  
Aapko ek integer `n` diya gaya hai. Aapko **n-th Fibonacci number** return karna hai.

- F(0) = 0  
- F(1) = 1  
- F(n) = F(n-1) + F(n-2)

---

## 2. 🔹 Interview Me Kaise Explain Karein (Story Style)

**Interviewer:** "Explain how you would compute the n-th Fibonacci number."

**Aap (step-by-step):**

1. “Fibonacci ek classic sequence hai jahan har number pichle do numbers par depend karta hai.”  
2. “Sabse simple तरीका recursion hai — lekin woh same values baar-baar compute karta hai.”  
3. “Main pehle brute-force recursion explain karunga taaki mathematical definition clear ho.”  
4. “Fir main isko optimize karunga Dynamic Programming ka iterative tareeka use karke, jisse time linear ho jaata hai.”  
5. “Aur end me main optimized, clean, interview-level code dunga.”

---

## 3. 🔹 Brute Force Approach  
### **Idea**  
Directly mathematical formula follow karke recursion lagana.

### ❗ Problem  
Same subproblems baar-baar compute hote hain → **exponential time** lagta hai.

### **Time Complexity:** `O(2^n)`  
### **Space Complexity:** `O(n)` (recursion depth ki wajah se)

---

## 4. 🔹 Optimized Approach (Interview Me Best)  
### **Approach: Bottom-Up Iterative DP**
- Fibonacci sirf **last 2 values** par depend karta hai.  
- Isliye poora DP array ki zarurat nahi.  
- Bas do variables se kaam ho jaata hai.  
- `0` se `n` tak answer build karte hain.

### **Why It Works**
- Repetition remove ho jaati hai  
- Constant memory use hoti hai  
- Clean, fast, readable code — interviews ke liye perfect  

### **Time Complexity:** `O(n)`  
### **Space Complexity:** `O(1)`

---

## 6. 🔹 Time & Space Complexity Summary

| Approach            | Time Complexity | Space Complexity |
|--------------------|----------------|-----------------|
| Optimized Iterative | O(n)           | O(1)            |

---


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



