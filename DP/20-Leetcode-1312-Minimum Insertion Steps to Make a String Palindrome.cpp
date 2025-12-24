//======================================================
// 🔹 APPROACH-1 : RECURSION + MEMOIZATION
// 🔹 Using Direct PALINDROME PROPERTY
//======================================================
//
// PROBLEM:
// -----------------------------------------------------
// Given a string s, return the MINIMUM number of
// insertions required to make s a PALINDROME.
//
// Allowed operation:
// 👉 Insert any character at any position
//
//------------------------------------------------------
// 💡 CORE OBSERVATION (VERY IMPORTANT):
// -----------------------------------------------------
// A string is a palindrome if:
//      s[i] == s[j]  (characters at both ends match)
//
// We try to make s[i..j] a palindrome with
// minimum insertions.
//------------------------------------------------------
//
// DP STATE:
// -----------------------------------------------------
// t[i][j] = minimum insertions needed to make
//           substring s[i..j] a palindrome
//
// i → left pointer
// j → right pointer
//------------------------------------------------------
//
// Time Complexity  : O(n²)
// Space Complexity : O(n²)  (DP table + recursion stack)
//======================================================

class Solution {
public:
    
    // Memo table
    // t[i][j] stores answer for substring s[i..j]
    int t[501][501];

    //==================================================
    // 🔹 Recursive function
    //==================================================
    int solve(int i, int j, string &s) {

        /*
        --------------------------------------------------
        BASE CASE:
        --------------------------------------------------
        If i >= j:
        - Empty string OR
        - Single character

        Already a palindrome
        👉 No insertion required
        --------------------------------------------------
        */
        if(i >= j)
            return 0;

        /*
        --------------------------------------------------
        MEMOIZATION CHECK:
        --------------------------------------------------
        If already computed, reuse result
        --------------------------------------------------
        */
        if(t[i][j] != -1)
            return t[i][j];

        /*
        --------------------------------------------------
        CASE-1: Characters MATCH
        --------------------------------------------------
        s[i] == s[j]

        Example:
        "a___a"

        Ends already match → no insertion needed
        Just solve for inner substring
        --------------------------------------------------
        */
        if(s[i] == s[j])
            return t[i][j] = solve(i+1, j-1, s);

        /*
        --------------------------------------------------
        CASE-2: Characters DO NOT MATCH
        --------------------------------------------------
        We have TWO choices:

        1️⃣ Insert s[i] after position j
           → Now s[i] matches at both ends
           → Solve (i, j-1)

        2️⃣ Insert s[j] before position i
           → Now s[j] matches at both ends
           → Solve (i+1, j)

        Since insertion cost = 1
        We take minimum of both options
        --------------------------------------------------
        */
        return t[i][j] = 1 + min(
                                    solve(i, j-1, s),
                                    solve(i+1, j, s)
                                  );
    }

    //==================================================
    // 🔹 Driver Function
    //==================================================
    int minInsertions(string s) {
        int n = s.length();

        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        // Solve for full string
        return solve(0, n-1, s);
    }
};


🎯 ONE-LINE EXPLANATION (EXAM READY)

We recursively compare characters from both ends and use memoization to store the minimum insertions required 
to make each substring palindromic, choosing the optimal insertion strategy when characters mismatch.


--------------------------------------------------------------------------------------------------------------------------------------------


//======================================================
// 🔹 APPROACH-2 : Bottom-Up DP (Palindrome Blueprint)
//======================================================
//
// PROBLEM:
// -----------------------------------------------------
// Given a string s, find the MINIMUM number of insertions
// required to make the string a PALINDROME.
//
// You are allowed to insert characters anywhere.
//
//------------------------------------------------------
// 💡 CORE IDEA:
// -----------------------------------------------------
// We solve this using classic PALINDROME DP.
//
// dp[i][j] = minimum insertions required to make
//            substring s[i...j] a palindrome
//
// We build the solution from smaller substrings
// to larger substrings (Bottom-Up).
//
//------------------------------------------------------
// Time Complexity  : O(n^2)
// Space Complexity : O(n^2)
//======================================================

class Solution {
public:
    int minInsertions(string s) {

        int n = s.length();

        /*
        --------------------------------------------------
        🔹 DP TABLE DEFINITION
        --------------------------------------------------
        dp[i][j] = Minimum insertions required to convert
                   substring s[i..j] into a palindrome

        Size: n x n
        --------------------------------------------------
        */
        vector<vector<int>> dp(n, vector<int>(n, 0));

        /*
        --------------------------------------------------
        🔹 BASE CASE
        --------------------------------------------------
        Substrings of length 1 (i == j) are already
        palindromes, so:

        dp[i][i] = 0  (No insertions needed)

        👉 Already handled because dp is initialized to 0
        --------------------------------------------------
        */

        /*
        --------------------------------------------------
        🔹 LENGTH-BASED ITERATION (IMPORTANT)
        --------------------------------------------------
        We solve smaller substrings first, because
        dp[i][j] depends on:
            - dp[i+1][j]
            - dp[i][j-1]
            - dp[i+1][j-1]

        So we iterate by increasing substring length L
        --------------------------------------------------
        */
        for (int L = 2; L <= n; L++) {

            // Starting index of substring
            for (int i = 0; i < n - L + 1; i++) {

                // Ending index
                int j = i + L - 1;

                /*
                ==========================================
                CASE-1: Characters MATCH
                ==========================================
                If s[i] == s[j], then these two characters
                can sit symmetrically in palindrome.

                No extra insertion needed at ends.
                Just solve for inner substring.
                ==========================================
                */
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }

                /*
                ==========================================
                CASE-2: Characters DO NOT MATCH
                ==========================================
                Two choices:
                ------------------------------------------
                1️⃣ Insert s[i] at the end → solve dp[i+1][j]
                2️⃣ Insert s[j] at the beginning → solve dp[i][j-1]

                Since insertion cost = 1
                We take minimum of both choices
                ==========================================
                */
                else {
                    dp[i][j] = 1 + min(
                                        dp[i + 1][j],
                                        dp[i][j - 1]
                                      );
                }
            }
        }

        /*
        --------------------------------------------------
        🔹 FINAL ANSWER
        --------------------------------------------------
        dp[0][n-1] gives minimum insertions required
        to make the entire string a palindrome
        --------------------------------------------------
        */
        return dp[0][n - 1];
    }
};


🎯 ONE-LINE EXPLANATION FOR EXAM

We use bottom-up dynamic programming where dp[i][j] represents the minimum insertions needed to make substring s[i..j] 
a palindrome, expanding the solution by substring length and handling matching and non-matching characters accordingly.


--------------------------------------------------------------------------------------------------------------------------------------------------



