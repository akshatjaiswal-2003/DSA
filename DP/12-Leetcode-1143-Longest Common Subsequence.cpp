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


🔥 INTERVIEW ME AISE EXPLAIN KARNA

"Ye Top-Down DP approach hai jisme recursion ke saath memoization use ki hai.
Har state (m, n) represent karti hai LCS length of first m chars of text1 and first n chars of text2.
Agar last characters same hote hain toh 1 add karke diagonal call karte hain, warna dono options try karke max lete hain.
Memoization ki wajah se har state sirf ek baar compute hoti hai, isliye time complexity O(m*n) ho jaati hai."









// Approach-2 : Bottom-Up Dynamic Programming (Tabulation)
// Time Complexity  : O(m * n)
// Space Complexity : O(m * n)

/*
   🔹 Problem: Longest Common Subsequence (LCS)

   Bottom-Up ka matlab:
   - Recursion use nahi karte
   - DP table ko chhote subproblems se fill karte hain
   - Pehle base cases, phir gradually bigger answers

   t[i][j] ka meaning:
   - LCS length of
     first i characters of text1
     first j characters of text2
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();   // length of first string
        int n = text2.length();   // length of second string

        // 🔹 DP Table create kar rahe hain
        // Size (m+1) x (n+1) because:
        // i = 0 ya j = 0 → empty string cases
        vector<vector<int>> t(m+1, vector<int>(n+1));

        // 🔄 DP Table Fill karna
        for(int i = 0; i < m+1; i++) {
            for(int j = 0; j < n+1; j++) {

                // 🛑 BASE CASE
                // Agar kisi bhi string ka size 0 hai
                // toh LCS = 0
                if(i == 0 || j == 0)
                    t[i][j] = 0;

                // ✅ CASE-1 : Characters MATCH kar gaye
                // text1 ka (i-1)th char
                // text2 ke (j-1)th char ke barabar hai
                // toh:
                // 1 add karo aur diagonal value lo
                else if(text1[i-1] == text2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];

                // ❌ CASE-2 : Characters MATCH nahi hue
                // Toh 2 choices:
                // 1️⃣ text1 ka char ignore (i-1, j)
                // 2️⃣ text2 ka char ignore (i, j-1)
                // Jo maximum de → wahi answer
                else
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }

        // 🔥 Last cell me final answer hota hai
        // t[m][n] = LCS length of full strings
        return t[m][n];
    }
};


🔥 INTERVIEW ME AISE BOLNA (BEST EXPLANATION)

"Ye Bottom-Up DP approach hai jisme hum DP table t[i][j] fill karte hain.
t[i][j] represent karta hai LCS length of first i characters of text1 and first j characters of text2.
Agar characters match karte hain toh diagonal se 1 add karte hain, warna left aur top me se maximum lete hain.
Final answer t[m][n] me hota hai."













// Approach-3 : Bottom-Up DP (Space Optimized)
// Time Complexity  : O(m * n)
// Space Complexity : O(n)

/*
   🔹 OBSERVATION (KEY IDEA):
   Bottom-Up DP me:
   t[i][j] sirf 3 values pe depend karta hai:
   1️⃣ t[i-1][j]   (upar wali row)
   2️⃣ t[i][j-1]   (current row ka left)
   3️⃣ t[i-1][j-1] (diagonal)

   👉 Iska matlab:
   Hume poori m x n table rakhne ki zarurat nahi
   Sirf 2 rows kaafi hain:
   - current row (i)
   - previous row (i-1)

   Isliye space reduce ho jaata hai:
   O(m*n) → O(n)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();   // length of first string
        int n = text2.length();   // length of second string

        // 🔹 Sirf 2 rows ka DP table
        // Row 0 → previous row
        // Row 1 → current row
        vector<vector<int>> t(2, vector<int>(n+1));

        // 🔄 DP table fill kar rahe hain row by row
        for(int i = 0; i < m+1; i++) {
            for(int j = 0; j < n+1; j++) {

                // 🛑 BASE CASE
                // Agar koi string empty hai
                // toh LCS = 0
                if(i == 0 || j == 0)
                    t[i % 2][j] = 0;

                // ✅ CASE-1 : Characters MATCH
                // text1[i-1] == text2[j-1]
                // Toh diagonal value + 1
                // Diagonal hamesha previous row me hoti hai
                else if(text1[i-1] == text2[j-1])
                    t[i % 2][j] = 1 + t[(i + 1) % 2][j-1];

                // ❌ CASE-2 : Characters MATCH nahi hue
                // 2 options:
                // 1️⃣ left value (same row)
                // 2️⃣ top value  (previous row)
                // Maximum choose karo
                else
                    t[i % 2][j] = max(
                                        t[i % 2][j-1],      // left
                                        t[(i + 1) % 2][j]  // top
                                      );
            }
        }

        // 🔥 Final answer:
        // last processed row ka nth column
        return t[m % 2][n];
    }
};



🧠 MOD (%) TRICK SAMJHO (VERY IMPORTANT)
| Expression    | Meaning      |
| ------------- | ------------ |
|  i % 2        | Current row  |
|  (i + 1) % 2  | Previous row |

👉 Kyunki sirf 2 rows hain, hum unko alternately reuse kar rahe hain.




🔥 INTERVIEW ME AISE EXPLAIN KARNA

"Bottom-Up LCS me har state sirf previous row aur current row pe depend karti hai.
Isliye poori DP table store karne ke bajaye sirf 2 rows use ki.
Modulo operator se current aur previous row manage ki.
Time complexity O(m*n) hi rehti hai, par space complexity O(n) ho jaati hai."