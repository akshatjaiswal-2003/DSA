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

    /*
    ------------------------------------------------------
    DP table:
    t[i][j] = Length of Longest Palindromic Subsequence
              in substring s[i ... j]
    ------------------------------------------------------
    */
    int t[1001][1001];

    /*
    ------------------------------------------------------
    🔹 LPS(s, i, j)
    ------------------------------------------------------
    Returns:
    → Length of longest palindromic subsequence
      in s from index i to j
    ------------------------------------------------------
    */
    int LPS(string& s, int i, int j) {

        /*
        ===============================
        🔹 BASE CASES
        ===============================
        */

        // If left index crosses right index
        // → empty string
        if(i > j)
            return 0;

        // If only one character remains
        // → single character is a palindrome of length 1
        if(i == j)
            return 1;

        /*
        ===============================
        🔹 MEMOIZATION CHECK
        ===============================
        */

        // If already computed, reuse result
        if(t[i][j] != -1)
            return t[i][j];

        /*
        ===============================
        🔹 RECURSIVE TRANSITIONS
        ===============================
        */

        /*
        Case-1:
        Characters at both ends are equal

        Example:
        s = "aba"
             ^ ^
        These two characters can be part of palindrome

        So:
        LPS = 2 + LPS(i+1, j-1)
        */
        if(s[i] == s[j])
            return t[i][j] = 2 + LPS(s, i+1, j-1);

        /*
        Case-2:
        Characters are NOT equal

        Example:
        s = "abcda"
             ^   ^
        Options:
        1) Ignore left character → LPS(i+1, j)
        2) Ignore right character → LPS(i, j-1)

        Take maximum of both
        */
        else
            return t[i][j] = max(
                                LPS(s, i+1, j),
                                LPS(s, i, j-1)
                              );
    }

    /*
    ------------------------------------------------------
    🔹 MAIN FUNCTION
    ------------------------------------------------------
    */
    int longestPalindromeSubseq(string s) {

        int m = s.length();

        // Initialize DP table with -1 (uncomputed)
        memset(t, -1, sizeof(t));

        /*
        Start recursion for full string
        i = 0, j = m-1
        */
        return LPS(s, 0, m-1);
    }
};

🎯 INTERVIEW ONE-LINER

“We use top-down dynamic programming where t[i][j] stores the length of the 
longest palindromic subsequence in substring s[i..j], reducing exponential recursion to O(n²).”


---------------------------------------------------------------------------------------------------------------------------------------------------------------------


