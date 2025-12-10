# 🧠 Intuition — LeetCode 198 (House Robber)

Is problem ka simple idea ye hai:

Aap houses ko lootna chahte ho, but **side-by-side (adjacent) do houses ko loot nahi sakte**, warna alarm baj jayega.

Har house ke paas do choices hoti hain:

### ✔️ Rob the house  
Is house ka paisa lo **+ (i-2) wale house ka best answer**.

### ✔️ Skip the house  
Simply **(i-1) wale house ka best answer** le lo.

---

Isliye har step pe hum bas yeh decide karte hain:

---

# 🚀 Approach — LeetCode 198 (House Robber)

1. Hum DP (Dynamic Programming) use karte hain kyunki har house ka decision  
   **pichle 1 ya 2 houses** par depend karta hai.

2. Har step par hum decide karte hain:
   - **Rob karu?**  
     → `nums[i] + dp[i-2]`
   - **Skip karu?**  
     → `dp[i-1]`

3. Isliye formula ban jata hai:  
    - dp[i] = max(nums[i] + dp[i-2], dp[i-1])


4. DP array ki zarurat nahi — hum bas **previous two values (`prev1`, `prev2`)** se kaam chala sakte hain.

5. Last me `prev1` hi humara final answer hota hai.

---

# ⏱️ Complexity Analysis

### **Time Complexity:**  
`O(n)`  
Har house ko sirf **ek baar** process karte hain.

### **Space Complexity:**  
`O(1)`  
Hum sirf **do variables** use karte hain (`prev1` aur `prev2`), koi extra array nahi.

--- 

