// Time Complexity  : O(m * n)
// Space Complexity : O(m * n)
// Approach-1 : Recursion + Memoization (Top-Down DP)

/*
   🔹 Problem: Longest Common Subsequence (LCS)

   LCS ka matlab:
   - Do strings given hain
   - Hume longest sequence find karni hai
   - Jo dono strings me SAME order me aaye
   - Characters contiguous hona zaroori nahi hai

   Example:
   s1 = "abcde"
   s2 = "ace"
   LCS = "ace" → length = 3
*/

class Solution {
public:

    // DP table
    // t[m][n] = LCS length of
    // first m characters of s1
    // first n characters of s2
    int t[1001][1001];

    /*
        🔹 LCS Recursive Function
        s1, s2 → input strings
        m → current length considered from s1
        n → current length considered from s2
    */
    int LCS(string& s1, string& s2, int m, int n) {

        // 🛑 BASE CASE
        // Agar kisi bhi string ki length 0 ho gayi
        // toh common subsequence possible hi nahi
        if(m == 0 || n == 0)
            return t[m][n] = 0;

        // 🔁 MEMOIZATION CHECK
        // Agar pehle se answer calculate ho chuka hai
        // toh directly wahi return kar do
        if(t[m][n] != -1)
            return t[m][n];

        // ✅ CASE-1 : Last characters MATCH kar gaye
        // Dono strings ke last characters same hain
        // toh:
        // - 1 add karo
        // - baki ke characters ke liye recursion call
        if(s1[m-1] == s2[n-1])
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);

        // ❌ CASE-2 : Last characters MATCH nahi hue
        // Toh 2 options:
        // 1️⃣ s1 ka last character ignore karo
        // 2️⃣ s2 ka last character ignore karo
        // Dono me se jo maximum LCS de → wahi answer
        return t[m][n] = max(
                            LCS(s1, s2, m, n-1),
                            LCS(s1, s2, m-1, n)
                          );
    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();
        int n = text2.length();

        // 🔄 DP table initialize with -1
        // Matlab: "abhi tak koi state solve nahi hui"
        memset(t, -1, sizeof(t));

        // 🔥 Final answer recursion se milega
        return LCS(text1, text2, m, n);
    }
};
