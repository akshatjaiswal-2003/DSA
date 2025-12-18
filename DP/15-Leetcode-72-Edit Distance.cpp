// Approach-1 : Recursion + Memoization (Top-Down DP)
// Time Complexity  : O(m * n)
// Space Complexity : O(m * n)

/*
    🔹 Problem: Edit Distance (Minimum Operations)

    Allowed operations:
    1️⃣ Insert a character
    2️⃣ Delete a character
    3️⃣ Replace a character

    Goal:
    - Convert string s1 into string s2
    - Using minimum number of operations

    Example:
    s1 = "horse"
    s2 = "ros"
    Output = 3
    (horse → rorse → rose → ros)
*/

class Solution {
public:

    /*
        🔹 DP Table
        t[m][n] = minimum operations required to
                  convert first m characters of s1
                  into first n characters of s2
    */
    int t[501][501];

    /*
        🔹 Recursive Function: solve
        s1, s2 → input strings
        m → length considered from s1
        n → length considered from s2
    */
    int solve(string& s1, string& s2, int m, int n) {

        // 🛑 BASE CASE
        // Agar s1 empty ho gaya
        // toh s2 ke n characters INSERT karne padenge
        // Agar s2 empty ho gaya
        // toh s1 ke m characters DELETE karne padenge
        if(m == 0 || n == 0)
            return m + n;

        // 🔁 MEMOIZATION CHECK
        // Agar state pehle se calculate ho chuki hai
        // toh directly return kar do
        if(t[m][n] != -1)
            return t[m][n];

        // ✅ CASE-1 : Last characters SAME hain
        // Koi operation ki zarurat nahi
        // Simply previous characters ke liye solve karo
        if(s1[m-1] == s2[n-1])
            return t[m][n] = solve(s1, s2, m-1, n-1);

        // ❌ CASE-2 : Last characters DIFFERENT hain
        else {

            // 🔹 OPTION-1 : INSERT
            // s2 ka last character insert kar do s1 me
            // n-1 reduce hoga
            int insertC  = 1 + solve(s1, s2, m, n-1);

            // 🔹 OPTION-2 : DELETE
            // s1 ka last character delete kar do
            // m-1 reduce hoga
            int deleteC  = 1 + solve(s1, s2, m-1, n);

            // 🔹 OPTION-3 : REPLACE
            // s1 ka last character replace kar do s2 ke last se
            // dono m-1, n-1 reduce honge
            int replaceC = 1 + solve(s1, s2, m-1, n-1);

            // 🔥 Minimum cost operation choose karo
            return t[m][n] = min({insertC, deleteC, replaceC});
        }
    }

    /*
        🔹 Driver Function
        - DP table initialize karta hai
        - Final answer return karta hai
    */
    int minDistance(string s1, string s2) {

        int m = s1.length();
        int n = s2.length();

        // 🔄 DP table ko -1 se initialize
        memset(t, -1, sizeof(t));

        // 🔥 Final Edit Distance
        return solve(s1, s2, m, n);
    }
};



🧠 INTERVIEW ME AISE EXPLAIN KARNA (BEST)

"Ye Edit Distance ka Top-Down DP solution hai.
solve(m, n) represent karta hai minimum operations required to convert first m characters of s1 into first n characters of s2.
Agar last characters same hote hain toh koi operation nahi lagta, warna insert, delete aur replace teen options try karke minimum lete hain.
Memoization ki wajah se har state sirf ek baar compute hoti hai, isliye time complexity O(m*n) ho jaati hai."