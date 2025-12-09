// LeetCode 509 — Fibonacci Number

--------------------------------- Best Approach ------------------------------------------------------------


class Solution {
public:
    int fib(int n) {
        // Agar n 0 ya 1 hai, to directly return kar do
        // Kyunki F(0) = 0 aur F(1) = 1
        if(n <= 1) return n;

        // Do variables banaye, a aur b
        // a -> F(i-2), b -> F(i-1)
        int a = 0; // F(0)
        int b = 1; // F(1)
        int c;     // c me F(i) store karenge

        // Loop 1 se n-1 tak chalega
        // Kyunki hume already F(0) aur F(1) pata hai
        for(int i = 1; i < n; i++)
        {
            // Current Fibonacci number calculate karte hain
            // F(i) = F(i-1) + F(i-2)
            c = a + b;

            // Shift karte hain variables a aur b ko aage
            // Taaki next iteration me F(i-1) aur F(i-2) ready ho
            a = b; // a ko b ke value de di (old F(i-1))
            b = c; // b ko c ke value de di (new F(i))
        }

        // Loop ke baad c me F(n) stored hai
        return c;
    }
};


----------------------------------- Buttom Up approach -----------------------------------------------------

class Solution {
public:
    int fib(int n) {
        // Agar n 0 ya 1 hai, to seedha return kar do
        if(n == 0) return 0;
        if(n == 1) return 1;

        // DP array banate hain, jisme dp[i] store karega i-th Fibonacci number
        vector<int> dp(n + 1, 0); // Initially saare elements 0 hai
        dp[0] = 0; // Base case: F(0) = 0
        dp[1] = 1; // Base case: F(1) = 1

        // Loop lagate hain 2 se n tak, kyunki 0 aur 1 already fill kar diye
        for(int i = 2; i <= n; i++){
            // Recurrence relation: F(n) = F(n-1) + F(n-2)
            dp[i] = dp[i - 1] + dp[i - 2];
            // Yaha pe dp[i-1] aur dp[i-2] already calculate ho chuke hain
        }

        // Finally, dp[n] return kar do, jo ki n-th Fibonacci number hai
        return dp[n];
    }
};


--------------------------------- Recursion + DP (memoization) approach ---------------------------------------

class Solution {
public:
    // Memoization ke liye ek helper function banayenge
    int fibHelper(int n, vector<int>& dp) {
        // Base cases: agar n 0 ya 1 hai, directly return kar do
        if(n == 0) return 0;
        if(n == 1) return 1;

        // Agar dp[n] pehle se calculate ho chuka hai, to use return karo
        if(dp[n] != -1) return dp[n];

        // Recursion: F(n) = F(n-1) + F(n-2)
        dp[n] = fibHelper(n - 1, dp) + fibHelper(n - 2, dp);

        // Calculated value return karo
        return dp[n];
    }

    int fib(int n) {
        // DP array banate hain -1 se initialize kiya kyunki abhi calculate kuch nahi hua
        vector<int> dp(n + 1, -1);

        // Helper function call karo aur result return karo
        return fibHelper(n, dp);
    }
};


