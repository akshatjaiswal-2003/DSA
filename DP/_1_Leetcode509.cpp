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