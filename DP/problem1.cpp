class Solution {
public:
    int fib(int n) {
        // Base cases (interviewer expects you to handle this cleanly)
        if (n == 0) return 0;
        if (n == 1) return 1;

        // prev2 holds F(n-2), prev1 holds F(n-1)
        int prev2 = 0;
        int prev1 = 1;

        // Loop from 2 to n computing the Fibonacci sequence iteratively
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;  // F(n) = F(n-1) + F(n-2)

            // Move the window forward:
            prev2 = prev1;  // Now prev2 becomes old prev1
            prev1 = curr;   // prev1 becomes the new Fibonacci number
        }

        // prev1 now stores F(n)
        return prev1;
    }
};




1. Problem Title + Short Summary

## Fibonacci Number ##

Given an integer n, return the n-th Fibonacci number where:

F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)


A classic DP problem testing recursion, memoization, and iterative DP thinking.

2. How to Explain This in an Interview (Step-by-Step, Structured)

Start with intuition:

“Fibonacci is a sequence where each number depends on the two before it.
This is a classic example used to test whether the candidate understands recursion vs dynamic programming.”

Explain the evolution of approaches:

Start naive:
Try to compute recursively from the definition.

Realize inefficiency:
Each call recomputes subproblems again and again (exponential time).

Introduce DP thinking:
→ Store results (memoization)
→ Or iteratively build from bottom (tabulation)

Choose optimal:
Since we only need the last two numbers, we use O(1) space iterative DP.

Key takeaway:
“We reduce computation by eliminating redundant work.”

3. Brute Force Approach
Brute Force = Pure Recursion
F(n) = F(n-1) + F(n-2)

Why it’s bad?

Recomputes the same values many times

Exponential time

Time Complexity:

O(2^n)

Space Complexity:

Recursion stack → O(n)

4. Optimized Approach
Iterative Dynamic Programming (O(1) Space)

Instead of computing top-down, compute bottom-up:

f(0) = 0
f(1) = 1
Use two variables:
prev2 = 0
prev1 = 1

Loop from 2 → n
current = prev1 + prev2
Shift:
prev2 = prev1
prev1 = current

Why it works?

Because Fibonacci only depends on the last 2 values, we don’t need a full DP array.

Benefits

O(n) time

O(1) space

No recursion → avoids stack overflow.

5. Final Time & Space Complexity
Time Complexity:

✅ O(n) — single loop from 2 to n

Space Complexity:

✅ O(1) — only uses 2–3 variables

6. Extra: Common Pitfalls + Edge Cases + Impress Interviewer Tips
Pitfalls:

Forgetting base cases: n = 0, n = 1

Using recursion directly → will TLE on larger inputs

Overflow (not in LC constraints, but worth mentioning)

Edge Cases:

n = 0 → return 0

n = 1 → return 1

How to Impress the Interviewer

Mention three methods: Recursion → Memoization → Iterative DP

Explain why iterative DP is optimal

Mention time/space improvements clearly

State that Fibonacci is a classic example to teach optimization techniques