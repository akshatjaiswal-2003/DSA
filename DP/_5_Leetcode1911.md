✅ Interview me kaise explain karunga — Hinglish Version

---
## 🔹 1. Problem ko Simple Tarike Se Samjhata Hoon

**Is problem me hume ek subsequence choose karna hai jisme:** 

- pehla number add hoga

- doosra number subtract hoga

- teesra add

- chautha subtract

- … aur aise alternate hota rahega

- Goal: alternating sum ko maximize karna.

- Subsequence ka matlab elements skip bhi kar sakte hain.

---

## 🔹 2. Main Observation

**Har index par mere paas sirf 2 choices hoti hain:**

- Agar next element add hoga

- Agar next element subtract hoga

- To main do states bana deta hoon:

- state = 0 → add
- state = 1 → subtract

---

## 🔹 3. DP State Definition

**Interview me aise bolna:**

“Maine DP ka use kiya jisme dp[i][0] represent karta hai ki index i se start karte hue
next operation add hoga, maximum alternating sum kitna ban sakta hai.
Aur dp[i][1] batata hai ki next operation subtract hoga to answer kya hoga.”

---

## 🔹 4. Transition (Pick / Skip)

**Agar next operation add hai:**

- pick    = nums[i] + dp[i+1][1]   // next subtract hoga
- skip    = dp[i+1][0]


- Agar next operation subtract hai:

- pick    = -nums[i] + dp[i+1][0]  // next add hoga
- skip    = dp[i+1][1]


- Final DP:

- dp[i][state] = max(pick, skip)


- Interview me confidently bolo:

“At every index main pick aur skip dono choices evaluate karta hoon,
aur dono states ka maximum store karta hoon.”


---


## 🔹 5. Final Answer

- Hum hamesha start karte hain add operation se.
- To answer = dp[0][0].

---

## 🔹 6. Complexity

- Time: O(n)

- Space: O(n), optimize karke O(1) bhi ho sakta hai

---

