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
    int solve(int i, int j, string &s) 
    {
        // --------------------------------------------------
        // BASE CASE:
        // --------------------------------------------------
        // If i >= j:
        // - Empty string OR
        // - Single character

        // Already a palindrome
        // 👉 No insertion required
        // --------------------------------------------------
        if(i >= j) return 0;
        // --------------------------------------------------
        // MEMOIZATION CHECK:
        // --------------------------------------------------
        // If already computed, reuse result
        // --------------------------------------------------
        if(t[i][j] != -1) return t[i][j];

        // --------------------------------------------------
        // CASE-1: Characters MATCH
        // --------------------------------------------------
        // s[i] == s[j]

        // Example:
        // "a___a"

        // Ends already match → no insertion needed
        // Just solve for inner substring
        // --------------------------------------------------
        if(s[i] == s[j]) return t[i][j] = solve(i+1, j-1, s);

        // --------------------------------------------------
        // CASE-2: Characters DO NOT MATCH
        // --------------------------------------------------
        // We have TWO choices:

        // 1️⃣ Insert s[i] after position j
        //    → Now s[i] matches at both ends
        //    → Solve (i, j-1)

        // 2️⃣ Insert s[j] before position i
        //    → Now s[j] matches at both ends
        //    → Solve (i+1, j)

        // Since insertion cost = 1
        // We take minimum of both options
        // --------------------------------------------------
        return t[i][j] = 1 + min(solve(i, j-1, s),solve(i+1, j, s));
    }

    //==================================================
    // 🔹 Driver Function
    //==================================================
    int minInsertions(string s) 
    {
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
    int minInsertions(string s) 
    {

        int n = s.length();

        // --------------------------------------------------
        // 🔹 DP TABLE DEFINITION
        // --------------------------------------------------
        // dp[i][j] = Minimum insertions required to convert
        //            substring s[i..j] into a palindrome

        // Size: n x n
        // --------------------------------------------------
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // --------------------------------------------------
        // 🔹 BASE CASE
        // --------------------------------------------------
        // Substrings of length 1 (i == j) are already
        // palindromes, so:

        // dp[i][i] = 0  (No insertions needed)

        // 👉 Already handled because dp is initialized to 0
        // --------------------------------------------------

        // --------------------------------------------------
        // 🔹 LENGTH-BASED ITERATION (IMPORTANT)
        // --------------------------------------------------
        // We solve smaller substrings first, because
        // dp[i][j] depends on:
        //     - dp[i+1][j]
        //     - dp[i][j-1]
        //     - dp[i+1][j-1]

        // So we iterate by increasing substring length L
        // --------------------------------------------------
        for (int L = 2; L <= n; L++) 
        {

            // Starting index of substring
            for (int i = 0; i < n - L + 1; i++) 
            {

                // Ending index
                int j = i + L - 1;

                // ==========================================
                // CASE-1: Characters MATCH
                // ==========================================
                // If s[i] == s[j], then these two characters
                // can sit symmetrically in palindrome.

                // No extra insertion needed at ends.
                // Just solve for inner substring.
                // ==========================================
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];

                // ==========================================
                // CASE-2: Characters DO NOT MATCH
                // ==========================================
                // Two choices:
                // ------------------------------------------
                // 1️⃣ Insert s[i] at the end → solve dp[i+1][j]
                // 2️⃣ Insert s[j] at the beginning → solve dp[i][j-1]

                // Since insertion cost = 1
                // We take minimum of both choices
                // ==========================================
                else dp[i][j] = 1 + min(dp[i + 1][j],dp[i][j - 1]);
            }
        }

        // --------------------------------------------------
        // 🔹 FINAL ANSWER
        // --------------------------------------------------
        // dp[0][n-1] gives minimum insertions required
        // to make the entire string a palindrome
        // --------------------------------------------------
        return dp[0][n - 1];
    }
};


🎯 ONE-LINE EXPLANATION FOR EXAM

We use bottom-up dynamic programming where dp[i][j] represents the minimum insertions needed to make substring s[i..j] 
a palindrome, expanding the solution by substring length and handling matching and non-matching characters accordingly.


--------------------------------------------------------------------------------------------------------------------------------------------------



//======================================================
// 🔹 APPROACH-3 : USING LCS CONCEPT
//======================================================
//
// PROBLEM:
// -----------------------------------------------------
// Find the MINIMUM number of insertions required
// to make a string PALINDROME.
//
//------------------------------------------------------
// 💡 KEY OBSERVATION (MOST IMPORTANT):
// -----------------------------------------------------
// Minimum Insertions = Length of String - LPS
//
// Where,
// LPS = Longest Palindromic Subsequence
//
//------------------------------------------------------
// 💡 TRICK:
// -----------------------------------------------------
// LPS of a string =
// LCS(string, reverse(string))
//
// Because:
// A palindrome reads the same forward & backward
//------------------------------------------------------
//
// So the plan is:
// 1️⃣ Reverse the string
// 2️⃣ Find LCS(original, reversed)
// 3️⃣ Subtract LCS length from original length
//
//------------------------------------------------------
// Time Complexity  : O(n²)
// Space Complexity : O(n²)
//======================================================

class Solution {
public:
    
    // DP table for memoization
    // t[m][n] = LCS length for s1[0..m-1] and s2[0..n-1]
    int t[501][501];
    
    //==================================================
    // 🔹 LCS USING RECURSION + MEMOIZATION
    //==================================================
    int LCS(string& s1, string& s2, int m, int n) {

        // --------------------------------------------------
        // BASE CASE:
        // --------------------------------------------------
        // If either string length becomes 0,
        // LCS length = 0
        // --------------------------------------------------
        if(m == 0 || n == 0) return t[m][n] = 0;

        // --------------------------------------------------
        // MEMOIZATION CHECK
        // --------------------------------------------------
        // If already computed, reuse result
        // --------------------------------------------------
        if(t[m][n] != -1) return t[m][n];

        // --------------------------------------------------
        // CASE-1: Characters MATCH
        // --------------------------------------------------
        // If last characters match,
        // include this character in LCS
        // --------------------------------------------------
        if(s1[m-1] == s2[n-1]) return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);

        // --------------------------------------------------
        // CASE-2: Characters DO NOT MATCH
        // --------------------------------------------------
        // Take maximum of:
        // - Skipping last char of s1
        // - Skipping last char of s2
        // --------------------------------------------------
        return t[m][n] = max(LCS(s1, s2, m, n-1),LCS(s1, s2, m-1, n));
    }
    
    //==================================================
    // 🔹 DRIVER FUNCTION
    //==================================================
    int minInsertions(string s) {

        int m = s.length();

        // Initialize DP table
        memset(t, -1, sizeof(t));

        // --------------------------------------------------
        // Step-1: Reverse the string
        // --------------------------------------------------
        string temp = s;
        reverse(begin(temp), end(temp));

        // --------------------------------------------------
        // Step-2: Find LCS between s and reversed(s)
        // This gives Longest Palindromic Subsequence (LPS)
        // --------------------------------------------------
        int lcs_length = LCS(s, temp, m, m);

        // --------------------------------------------------
        // Step-3: Minimum Insertions Formula
        // --------------------------------------------------
        // min insertions = total length - LPS length
        // --------------------------------------------------
        return m - lcs_length;
    }
};



🎯 INTERVIEW ONE-LINER

Minimum insertions required to make a string palindrome equals the difference between string length and 
its longest palindromic subsequence, which can be computed using LCS with the reversed string.
