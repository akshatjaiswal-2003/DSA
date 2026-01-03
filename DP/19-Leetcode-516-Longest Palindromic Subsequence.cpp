//======================================================
// 🔹 APPROACH-1: Recursion + Memoization (Top-Down DP)
//======================================================
//
// Problem:
// Find the length of the Longest Palindromic Subsequence
// (characters need NOT be contiguous)
//
// Example:
// s = "bbbab"
// Output = 4 ("bbbb")
//
//======================================================
// Time Complexity  : O(m * m)
// Space Complexity : O(m * m)  (DP table + recursion stack)
//======================================================

class Solution {
public:

    // ------------------------------------------------------
    // DP table:
    // t[i][j] = Length of Longest Palindromic Subsequence
    //           in substring s[i ... j]
    // ------------------------------------------------------
    int t[1001][1001];

    // ------------------------------------------------------
    // 🔹 LPS(s, i, j)
    // ------------------------------------------------------
    // Returns:
    // → Length of longest palindromic subsequence
    //   in s from index i to j
    // ------------------------------------------------------
    int LPS(string& s, int i, int j) 
    {

        // ===============================
        // 🔹 BASE CASES
        // ===============================

        // If left index crosses right index
        // → empty string
        if(i > j) return 0;

        // If only one character remains
        // → single character is a palindrome of length 1
        if(i == j) return 1;

        // ===============================
        // 🔹 MEMOIZATION CHECK
        // ===============================

        // If already computed, reuse result
        if(t[i][j] != -1) return t[i][j];

        // ===============================
        // 🔹 RECURSIVE TRANSITIONS
        // ===============================

        // Case-1:
        // Characters at both ends are equal

        // Example:
        // s = "aba"
        //      ^ ^
        // These two characters can be part of palindrome

        // So:
        // LPS = 2 + LPS(i+1, j-1)
        if(s[i] == s[j]) return t[i][j] = 2 + LPS(s, i+1, j-1);

        // Case-2:
        // Characters are NOT equal

        // Example:
        // s = "abcda"
        //      ^   ^
        // Options:
        // 1) Ignore left character → LPS(i+1, j)
        // 2) Ignore right character → LPS(i, j-1)

        // Take maximum of both
        else return t[i][j] = max(LPS(s, i+1, j), LPS(s, i, j-1));
    }

    // ------------------------------------------------------
    // 🔹 MAIN FUNCTION
    // ------------------------------------------------------
    int longestPalindromeSubseq(string s) {

        int m = s.length();

        // Initialize DP table with -1 (uncomputed)
        memset(t, -1, sizeof(t));

        // Start recursion for full string
        // i = 0, j = m-1
        return LPS(s, 0, m-1);
    }
};

🎯 INTERVIEW ONE-LINER

“We use top-down dynamic programming where t[i][j] stores the length of the 
longest palindromic subsequence in substring s[i..j], reducing exponential recursion to O(n²).”


---------------------------------------------------------------------------------------------------------------------------------------------------------------------


//======================================================
// 🔹 APPROACH-2 : Bottom-Up Dynamic Programming
//======================================================
//
// Problem:
// Find the length of the Longest Palindromic Subsequence
// (characters do NOT need to be contiguous)
//
// Example:
// s = "bbbab"
// Output = 4 ("bbbb")
//
//======================================================
// Time Complexity  : O(n * n)
// Space Complexity : O(n * n)
//======================================================
//
// WHY Bottom-Up?
// - Avoid recursion overhead
// - Clear DP table filling order
// - Very stable and interview-friendly
//======================================================

class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {

        int n = s.length();

        // --------------------------------------------------
        // 🔹 DP TABLE
        // --------------------------------------------------
        // t[i][j] = Length of Longest Palindromic Subsequence
        //           in substring s[i ... j]
        // --------------------------------------------------

        vector<vector<int>> t(n, vector<int>(n, 0));

        // --------------------------------------------------
        // 🔹 BASE CASE: Length = 1
        // --------------------------------------------------
        // Any single character is always a palindrome
        // Example:
        // "a", "b", "z" → LPS length = 1
        // --------------------------------------------------
        for(int i = 0; i < n; i++) t[i][i] = 1;

        // --------------------------------------------------
        // 🔹 FILL DP TABLE BY SUBSTRING LENGTH
        // --------------------------------------------------
        // L = current substring length
        // We start from length = 2 and go till n

        // WHY?
        // Because t[i][j] depends on:
        // - t[i+1][j-1]
        // - t[i][j-1]
        // - t[i+1][j]
        // which must be already computed
        // --------------------------------------------------
        for(int L = 2; L <= n; L++) 
        {
            // Slide window of length L
            for(int i = 0; i < n - L + 1; i++) 
            {
                int j = i + L - 1;  // Ending index

                // ==========================================
                // CASE-1: Characters at both ends MATCH
                // ==========================================

                // Example:
                // s = "abca"
                //      ^   ^
                // These two characters can be part of LPS

                // So:
                // LPS = 2 + LPS of inner substring
                //      = 2 + t[i+1][j-1]
                // ==========================================
                if(s[i] == s[j]) t[i][j] = 2 + t[i+1][j-1];

                // ==========================================
                // CASE-2: Characters DO NOT MATCH
                // ==========================================

                // Example:
                // s = "abcde"
                //      ^   ^
                // Options:
                // 1️⃣ Skip left character  → t[i+1][j]
                // 2️⃣ Skip right character → t[i][j-1]

                // Take the maximum of both
                // ==========================================
                else t[i][j] = max(t[i][j-1],t[i+1][j]);
            }
        }

        // --------------------------------------------------
        // 🔹 FINAL ANSWER
        // --------------------------------------------------
        // LPS of the entire string s[0 ... n-1]
        // --------------------------------------------------
        return t[0][n-1];
    }
};


🎯 INTERVIEW ONE-LINER

“We use bottom-up DP where t[i][j] stores the length of the longest palindromic subsequence in substring s[i..j], 
building solutions from smaller substrings to larger ones in O(n²) time.”



-------------------------------------------------------------------------------------------------------------------------------------------------------



//======================================================
// 🔹 APPROACH-3 : Using LCS (Longest Common Subsequence)
//======================================================
//
// 💡 KEY IDEA:
// -----------------------------------------------------
// Longest Palindromic Subsequence (LPS) of a string
// = Longest Common Subsequence (LCS) between
//   the string and its REVERSE
//
// Why?
// -----------------------------------------------------
// A palindrome reads the same forwards & backwards.
// So if a sequence appears in both:
//   s  and  reverse(s)
// then that sequence must be palindromic.
//
// Example:
// s  = "bbbab"
// rev= "babbb"
//
// LCS(s, rev) = "bbbb"
// Length = 4  → LPS
//
//======================================================
// Time Complexity  : O(m * n)
// Space Complexity : O(m * n)
//======================================================

class Solution {
public:

    // --------------------------------------------------
    // 🔹 FUNCTION: LCS (Bottom-Up DP)
    // --------------------------------------------------
    // Calculates Longest Common Subsequence length
    // between strings s1 and s2
    // --------------------------------------------------
    int LCS(string s1, string s2, int m, int n) 
    {

        // --------------------------------------------------
        // DP TABLE
        // --------------------------------------------------
        // t[i][j] = Length of LCS between
        //           s1[0...i-1] and s2[0...j-1]

        // Size = (m+1) x (n+1)
        // Extra row & column are for base cases
        // --------------------------------------------------
        vector<vector<int>> t(m+1, vector<int>(n+1));

        // --------------------------------------------------
        // 🔹 BASE CASES
        // --------------------------------------------------
        // If one string is empty → LCS = 0
        // --------------------------------------------------
        for(int row = 0; row <= m; row++) t[row][0] = 0;

        for(int col = 0; col <= n; col++) t[0][col] = 0;

        // --------------------------------------------------
        // 🔹 FILL DP TABLE
        // --------------------------------------------------
        // Using classic LCS logic
        // --------------------------------------------------
        for(int i = 1; i <= m; i++) 
        {
            for(int j = 1; j <= n; j++) 
            {

                // ==========================================
                // CASE-1: Characters MATCH
                // ==========================================
                // s1[i-1] == s2[j-1]

                // Include this character in LCS
                // Move diagonally
                // ==========================================
                if(s1[i-1] == s2[j-1]) t[i][j] = 1 + t[i-1][j-1];

                // ==========================================
                // CASE-2: Characters DO NOT MATCH
                // ==========================================
                // Two choices:
                // 1️⃣ Skip character from s1
                // 2️⃣ Skip character from s2

                // Take maximum of both
                // ==========================================
                else t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        }

        // --------------------------------------------------
        // 🔹 FINAL ANSWER
        // --------------------------------------------------
        // LCS length of full strings
        // --------------------------------------------------
        return t[m][n];
    }

    // --------------------------------------------------
    // 🔹 MAIN FUNCTION: LPS
    // --------------------------------------------------
    int longestPalindromeSubseq(string s) 
    {

        // --------------------------------------------------
        // Step-1: Create reverse of string
        // --------------------------------------------------
        // string s1 = s;
        // reverse(s1.begin(), s1.end());

        // int m = s.length();

        // --------------------------------------------------
        // Step-2: LPS = LCS(s, reverse(s))
        // --------------------------------------------------
        return LCS(s, s1, m, m);
    }
};


🎯 INTERVIEW ONE-LINER

“The longest palindromic subsequence can be found by computing the LCS between the string and 
its reversed version, since any sequence common to both must read the same forwards and backwards.”