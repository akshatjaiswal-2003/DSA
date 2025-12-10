✅ LeetCode 213 — House Robber II

Difficulty: Medium

-----------------------------------------------------------------------------------

1. 🔹 Problem Title + Short Summary

House Robber II
Iss problem me houses circle me arranged hain.
Agar aap first house loot lete ho, toh last house nahi loot sakte (adjacent ho gaye).

Aapko maximum paisa batana hai bina adjacent houses ko loot kiye.

Example:
nums = [2, 3, 2] → Answer = 3
nums = [1, 2, 3, 1] → Answer = 4

-----------------------------------------------------------------------------------

2. 🔹 Interview Me Kaise Explain Karein (Story Style)

Interviewer: “How will you rob houses arranged in a circle?”

Aap (step-by-step):

“Normal House Robber (198) me hum line me houses deal karte hain, but yaha circle hai.”

“Iska matlab first aur last house adjacent ho jate hain.”

“Agar main first house lootun → last house nahi loot sakta.”

“Agar main last house lootun → first house nahi loot sakta.”

“Toh problem ko do linear cases me break karte hain:”

Case 1: House 0 include → last house skip → rob(0 to n-2)

Case 2: House 0 skip → last include → rob(1 to n-1)

“Dono cases ka max hi answer ban jaata hai.”

“Yeh approach fastest + cleanest hai — interviewers love it.”

-----------------------------------------------------------------------------------

3. 🔹 Brute Force Approach
Idea

Recursion se har possible combination try karna (first include ya exclude).

❗ Problem

Exponential time, overlapping subproblems, TLE.

Time Complexity: O(2^n)
Space Complexity: O(n)

-----------------------------------------------------------------------------------

4. 🔹 Optimized Approach (Interview Me Best)
Approach: Break Circle → Use House Robber I DP

We solve 2 linear DP problems:

Rob 0 to n−2

Rob 1 to n−1

Final answer = max(case1, case2)

Isme hum House Robber 198 wala O(1) space DP use karte hain.

Why It Works

Circle breaking removes adjacency conflict

Dono linear arrays fast solve hote hain

Time = O(n), Space = O(1)

Time Complexity: O(n)
Space Complexity: O(1)

--
