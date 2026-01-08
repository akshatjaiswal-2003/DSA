// // Approach-1 : Recursion + Memoization (Top-Down DP)
// // Time Complexity  : O(m * n)
// // Space Complexity : O(m * n)

// /*
//     🔹 Problem: Edit Distance (Minimum Operations)

//     Allowed operations:
//     1️⃣ Insert a character
//     2️⃣ Delete a character
//     3️⃣ Replace a character

//     Goal:
//     - Convert string s1 into string s2
//     - Using minimum number of operations

//     Example:
//     s1 = "horse"
//     s2 = "ros"
//     Output = 3
//     (horse → rorse → rose → ros)
// */

// class Solution {
// public:

//     /*
//         🔹 DP Table
//         t[m][n] = minimum operations required to
//                   convert first m characters of s1
//                   into first n characters of s2
//     */
//     int t[501][501];

//     /*
//         🔹 Recursive Function: solve
//         s1, s2 → input strings
//         m → length considered from s1
//         n → length considered from s2
//     */
//     int solve(string& s1, string& s2, int m, int n) {

//         // 🛑 BASE CASE
//         // Agar s1 empty ho gaya
//         // toh s2 ke n characters INSERT karne padenge
//         // Agar s2 empty ho gaya
//         // toh s1 ke m characters DELETE karne padenge
//         if(m == 0 || n == 0)
//             return m + n;

//         // 🔁 MEMOIZATION CHECK
//         // Agar state pehle se calculate ho chuki hai
//         // toh directly return kar do
//         if(t[m][n] != -1)
//             return t[m][n];

//         // ✅ CASE-1 : Last characters SAME hain
//         // Koi operation ki zarurat nahi
//         // Simply previous characters ke liye solve karo
//         if(s1[m-1] == s2[n-1])
//             return t[m][n] = solve(s1, s2, m-1, n-1);

//         // ❌ CASE-2 : Last characters DIFFERENT hain
//         else {

//             // 🔹 OPTION-1 : INSERT
//             // s2 ka last character insert kar do s1 me
//             // n-1 reduce hoga
//             int insertC  = 1 + solve(s1, s2, m, n-1);

//             // 🔹 OPTION-2 : DELETE
//             // s1 ka last character delete kar do
//             // m-1 reduce hoga
//             int deleteC  = 1 + solve(s1, s2, m-1, n);

//             // 🔹 OPTION-3 : REPLACE
//             // s1 ka last character replace kar do s2 ke last se
//             // dono m-1, n-1 reduce honge
//             int replaceC = 1 + solve(s1, s2, m-1, n-1);

//             // 🔥 Minimum cost operation choose karo
//             return t[m][n] = min({insertC, deleteC, replaceC});
//         }
//     }

//     /*
//         🔹 Driver Function
//         - DP table initialize karta hai
//         - Final answer return karta hai
//     */
//     int minDistance(string s1, string s2) {

//         int m = s1.length();
//         int n = s2.length();

//         // 🔄 DP table ko -1 se initialize
//         memset(t, -1, sizeof(t));

//         // 🔥 Final Edit Distance
//         return solve(s1, s2, m, n);
//     }
// };



// 🧠 INTERVIEW ME AISE EXPLAIN KARNA (BEST)

// "Ye Edit Distance ka Top-Down DP solution hai.
// solve(m, n) represent karta hai minimum operations required to convert first m characters of s1 into first n characters of s2.
// Agar last characters same hote hain toh koi operation nahi lagta, warna insert, delete aur replace teen options try karke minimum lete hain.
// Memoization ki wajah se har state sirf ek baar compute hoti hai, isliye time complexity O(m*n) ho jaati hai."



// ----------------------------------------------------------------------------------------------------------------------------------------------



// // Approach-2 : Recursion + Memoization (Top-Down DP)
// // Starting from i = 0, j = 0
// // Time Complexity  : O(m * n)
// // Space Complexity : O(m * n)

// /*
//     🔹 Problem: Edit Distance (Minimum Operations)

//     Allowed Operations:
//     1️⃣ Insert
//     2️⃣ Delete
//     3️⃣ Replace

//     Goal:
//     - s1 ko s2 me convert karna
//     - Minimum number of operations ke saath

//     Example:
//     s1 = "intention"
//     s2 = "execution"
//     Output = 5
// */

// class Solution {
// public:

//     /*
//         🔹 DP Table
//         t[i][j] = minimum operations required to
//                   convert substring s1[i ... m-1]
//                   into substring s2[j ... n-1]
//     */
//     int t[501][501];

//     int m, n;   // length of s1 and s2 (global for easy access)

//     /*
//         🔹 Recursive Function: solve
//         i → current index in s1
//         j → current index in s2
//     */
//     int solve(string& s1, string& s2, int i, int j) {

//         // 🛑 BASE CASE-1
//         // Agar s1 completely traverse ho gaya
//         // toh s2 ke remaining characters INSERT karne padenge
//         if(i == m)
//             return n - j;

//         // 🛑 BASE CASE-2
//         // Agar s2 completely traverse ho gaya
//         // toh s1 ke remaining characters DELETE karne padenge
//         else if(j == n)
//             return m - i;

//         // 🔁 MEMOIZATION CHECK
//         // Agar state already solved hai
//         // toh direct answer return karo
//         if(t[i][j] != -1)
//             return t[i][j];

//         // ✅ CASE-1 : Current characters MATCH
//         // Koi operation required nahi
//         // Simply next indices pe move karo
//         if(s1[i] == s2[j])
//             return t[i][j] = solve(s1, s2, i+1, j+1);

//         // ❌ CASE-2 : Current characters DIFFERENT
//         else {

//             // 🔹 OPTION-1 : INSERT
//             // s2[j] ko s1 me insert karo
//             // j aage badhega
//             int insertC  = 1 + solve(s1, s2, i, j+1);

//             // 🔹 OPTION-2 : DELETE
//             // s1[i] ko delete karo
//             // i aage badhega
//             int deleteC  = 1 + solve(s1, s2, i+1, j);

//             // 🔹 OPTION-3 : REPLACE
//             // s1[i] ko s2[j] se replace karo
//             // dono i aur j aage badhenge
//             int replaceC = 1 + solve(s1, s2, i+1, j+1);

//             // 🔥 Minimum cost operation choose karo
//             return t[i][j] = min({insertC, deleteC, replaceC});
//         }
//     }

//     /*
//         🔹 Driver Function
//         - Length initialize karta hai
//         - DP table reset karta hai
//         - Final edit distance return karta hai
//     */
//     int minDistance(string s1, string s2) {

//         m = s1.length();
//         n = s2.length();

//         // 🔄 DP table initialize with -1
//         memset(t, -1, sizeof(t));

//         // 🔥 Start recursion from beginning (0,0)
//         return solve(s1, s2, 0, 0);
//     }
// };


// 🔥 INTERVIEW ME AISE EXPLAIN KARNA

// "Is approach me solve(i, j) represent karta hai minimum operations needed to convert substring s1[i…] into s2[j…].
// Agar characters same hain toh bina cost ke next indices pe move karte hain.
// Agar different hain toh insert, delete aur replace ke teen options try karke minimum lete hain.
// Memoization ki wajah se har state sirf ek baar compute hoti hai, isliye time complexity O(m*n) ho jaati hai."


// --------------------------------------------------------------------------------------------------------------------------

// 🧠 APPROACH-1 vs APPROACH-2 (INTERVIEW FAVORITE)

// | Feature     | Approach-1   | Approach-2   |
// | ----------- | ------------ | ------------ |
// | Start point | End (m, n)   | Start (0, 0) |
// | State       | Prefix       | Suffix       |
// | Base case   | m==0 or n==0 | i==m or j==n |
// | Logic       | Same         | Same         |


// -----------------------------------------------------------------------------------------------------------



// // Approach-3 : Bottom-Up Dynamic Programming (Derived from Approach-1)
// // Time Complexity  : O(m * n)
// // Space Complexity : O(m * n)

// /*
//     🔹 Problem: Edit Distance (Levenshtein Distance)

//     Allowed operations:
//     1️⃣ Insert
//     2️⃣ Delete
//     3️⃣ Replace

//     Goal:
//     - Convert string s1 into string s2
//     - Minimum number of operations ke saath

//     🔹 Key Idea:
//     Ye approach recursion + memoization ko
//     iterative (tabulation) form me convert karti hai.
// */

// class Solution {
// public:

//     /*
//         🔹 Function: editDistance

//         t[i][j] = minimum number of operations required to
//                   convert first i characters of s1
//                   into first j characters of s2
//     */
//     int editDistance(string s1, string s2, int m, int n) {

//         // 🔹 DP table of size (m+1) x (n+1)
//         // Extra row & column empty string cases ke liye
//         vector<vector<int>> t(m+1, vector<int>(n+1));

//         // 🔄 STEP-1 : DP table fill karna (Bottom-Up)
//         for(int i = 0; i < m+1; i++) {
//             for(int j = 0; j < n+1; j++) {

//                 // 🛑 BASE CASE
//                 // Agar s1 empty hai (i == 0)
//                 // toh s2 ke j characters INSERT karne padenge
//                 // Agar s2 empty hai (j == 0)
//                 // toh s1 ke i characters DELETE karne padenge
//                 if(i == 0 || j == 0)
//                     t[i][j] = i + j;

//                 // ✅ CASE-1 : Last characters MATCH
//                 // Koi operation required nahi
//                 // Diagonal value copy kar lo
//                 else if(s1[i-1] == s2[j-1])
//                     t[i][j] = t[i-1][j-1];

//                 // ❌ CASE-2 : Last characters DIFFERENT
//                 else
//                     /*
//                         Teen operations possible:
//                         1️⃣ Insert  → t[i][j-1]
//                         2️⃣ Delete  → t[i-1][j]
//                         3️⃣ Replace → t[i-1][j-1]

//                         +1 current operation ke liye
//                         Minimum choose karo
//                     */
//                     t[i][j] = 1 + min({
//                                         t[i][j-1],     // insert
//                                         t[i-1][j],     // delete
//                                         t[i-1][j-1]    // replace
//                                       });
//             }
//         }

//         // 🔥 Final answer bottom-right cell me hota hai
//         return t[m][n];
//     }

//     /*
//         🔹 Driver Function
//         - Strings ki length nikalta hai
//         - editDistance function call karta hai
//     */
//     int minDistance(string s1, string s2) {

//         int m = s1.length();
//         int n = s2.length();

//         return editDistance(s1, s2, m, n);
//     }
// };




// 🔥 INTERVIEW ME AISE EXPLAIN KARNA

// "Ye Edit Distance ka Bottom-Up DP solution hai.
// t[i][j] represent karta hai minimum operations required to convert first i characters of s1 into first j characters of s2.
// Agar characters same hain toh diagonal value copy hoti hai, warna insert, delete aur replace ke minimum ko choose karte hain.
// Final answer t[m][n] me hota hai."


// -----------------------------------------------------------------------------------------------------------------------------


// ⚖️ COMPARISON (ALL 3 EDIT DISTANCE APPROACHES)

// | Approach   | Type                     | Space  |
// | ---------- | ------------------------ | ------ |
// | Approach-1 | Recursion + Memo         | O(m*n) |
// | Approach-2 | Recursion + Memo (start) | O(m*n) |
// | Approach-3 | Bottom-Up DP             | O(m*n) |




 