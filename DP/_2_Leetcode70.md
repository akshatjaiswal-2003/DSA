# ✅ LeetCode 70 — **Climbing Stairs**  
**Difficulty: Easy**

---

## 1. 🔹 Problem Title + Short Summary  
**Climbing Stairs**  
Aapko ek integer `n` diya gaya hai. Aap ek baar me **1 stair** ya **2 stairs** chadh sakte ho.  
Aapko batana hai ki total kitne **distinct ways** hain jinke through aap `n` stair tak pahunch sakte ho.

Example:  
- n = 2 → 2 ways  
- n = 3 → 3 ways  

---

## 2. 🔹 Interview Me Kaise Explain Karein (Story Style)

**Interviewer:** “How many ways can you climb n stairs if you can take 1 or 2 steps at a time?”

**Aap (step-by-step):**

1. “Har stair tak pahunchne ke liye main sirf last two positions se aa sakta hoon.”  
2. “Agar main `n` par hoon, toh main ya toh `n-1` se aaya hoon (1 step), ya `n-2` se (2 steps).”  
3. “Yeh relation Fibonacci jaisa ban jaata hai.”  
4. “Brute force recursion se exponential time lagta hai.”  
5. “Isliye main DP iterative approach use karta hoon — fastest, cleanest, and interview-ready.”

---

## 3. 🔹 Brute Force Approach  
### **Idea**  
Recursion se har possibility try karna.

### ❗ Problem  
Overlap hona, repeated subproblems → **exponential slow**.

### **Time Complexity:** `O(2^n)`  
### **Space Complexity:** `O(n)` (recursion depth)

---

## 4. 🔹 Optimized Approach (Interview Me Best)  
### **Approach: Bottom-Up DP**
- `ways[n] = ways[n-1] + ways[n-2]`  
- Yeh exactly Fibonacci jaise hi hai.  
- Aapko sirf **last 2 values** store karni hoti hain → optimized solution.

### **Why It Works**
- Avoids repetition  
- Constant memory  
- Fast + clean — interview ke liye perfect  

### **Time Complexity:** `O(n)`  
### **Space Complexity:** `O(1)`

---

## 5. 🔹 Time & Space Complexity Summary

| Approach            | Time Complexity | Space Complexity |
| ------------------- | --------------- | ---------------- |
| Optimized Iterative | O(n)            | O(1)             |
