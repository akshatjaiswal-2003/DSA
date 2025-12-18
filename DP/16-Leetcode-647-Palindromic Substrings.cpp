// Approach-1 : Brute Force (Check all possible substrings)
// Time Complexity  : O(n^3)
// Space Complexity : O(1)

/*
    🔹 Problem: Count Palindromic Substrings

    Palindrome ka matlab:
    - String jo aage se aur peeche se same ho

    Example:
    s = "aaa"
    Palindromic substrings:
    "a", "a", "a", "aa", "aa", "aaa"
    Answer = 6

    🔹 Idea:
    - Har possible substring generate karo
    - Har substring ko palindrome check karo
    - Agar palindrome hai toh count badhao
*/

class Solution {
public:

    /*
        🔹 Function: check
        Purpose:
        - s[i...j] substring palindrome hai ya nahi check karna

        Approach:
        - Two pointers / recursion
        - Characters ko start aur end se compare karte hain
    */
    bool check(string &s, int i, int j) {

        // 🛑 BASE CASE
        // Agar i >= j ho gaya
        // Matlab:
        // - single character
        // - ya empty substring
        // Dono palindrome hote hain
        if(i >= j) {
            return true;
        }

        // ✅ CASE-1 : Characters MATCH
        // Agar start aur end character same hain
        // Toh beech ka substring check karo
        if(s[i] == s[j]) {
            return check(s, i+1, j-1);
        }

        // ❌ CASE-2 : Characters MATCH nahi hue
        // Palindrome possible nahi
        return false;
    }

    /*
        🔹 Function: countSubstrings
        Purpose:
        - Total palindromic substrings count karna
    */
    int countSubstrings(string s) {

        int n = s.length();
        int count = 0;

        // 🔄 Step-1 : Har possible substring generate karo
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                // s[i...j] ek substring hai
                // 🔍 Check karo palindrome hai ya nahi
                if(check(s, i, j)) {
                    count++;   // agar palindrome hai toh count badhao
                }
            }
        }

        // 🔥 Total palindromic substrings
        return count;
    }
};




🔥 INTERVIEW ME AISE EXPLAIN KARNA

"Is approach me hum brute force use karte hain.
Hum har possible substring generate karte hain aur recursion se check karte hain ki palindrome hai ya nahi.
Time complexity O(n³) hoti hai, isliye ye sirf small input ke liye suitable hai."



------------------------------------------------------------------------------------------------------------------------


// Approach-2 : Memoization (Top-Down DP)
// Idea: Brute force me jo same substrings baar-baar check ho rahi thi,
//       unke result ko DP table me store kar lo

// Time Complexity  : O(n^2)
// Space Complexity : O(n^2)

/*
    🔹 Problem: Count Palindromic Substrings

    Palindromic substring:
    - Substring jo aage se aur peeche se same ho

    Example:
    s = "aaa"
    Palindromic substrings = 6

    🔹 Improvement over Approach-1:
    - Har (i, j) substring ko sirf ek baar check karenge
    - Result ko DP table me store kar lenge
*/

class Solution {
public:

    /*
        🔹 DP Table
        t[i][j] = 
            -  1  → substring s[i...j] palindrome hai
            -  0  → palindrome nahi hai
            - -1  → abhi check nahi hua
    */
    int t[1001][1001];

    /*
        🔹 Function: check
        Purpose:
        - Check karta hai ki substring s[i...j] palindrome hai ya nahi
        - Memoization use karta hai
    */
    bool check(string &s, int i, int j) {

        // 🛑 BASE CASE
        // Agar i >= j ho gaya:
        // - single character
        // - empty substring
        // Dono hamesha palindrome hote hain
        if(i >= j) {
            return true;
        }

        // 🔁 MEMOIZATION CHECK
        // Agar substring s[i...j] pehle check ho chuki hai
        // toh stored answer return kar do
        if(t[i][j] != -1) {
            return t[i][j];   // 1 → true, 0 → false
        }

        // ✅ CASE-1 : Characters MATCH
        // Start aur end character same hai
        // Toh beech ka substring check karo
        if(s[i] == s[j]) {
            return t[i][j] = check(s, i+1, j-1);
        }

        // ❌ CASE-2 : Characters MATCH nahi hue
        // Palindrome possible nahi
        return t[i][j] = false;
    }

    /*
        🔹 Function: countSubstrings
        Purpose:
        - Total palindromic substrings count karna
    */
    int countSubstrings(string s) {

        int n = s.length();

        // 🔄 DP table initialize with -1
        // Matlab: abhi koi substring check nahi hui
        memset(t, -1, sizeof(t));

        int count = 0;

        // 🔄 Har possible substring generate karo
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                // s[i...j] substring palindrome hai ya nahi
                if(check(s, i, j)) {
                    count++;   // Agar palindrome hai toh count badhao
                }
            }
        }

        // 🔥 Total palindromic substrings
        return count;
    }
};





🔥 INTERVIEW ME AISE EXPLAIN KARNA

"Is approach me hum brute force ko optimize karte hain using memoization.
check(i, j) function substring s[i…j] ke liye palindrome result store karta hai.
Agar same substring dobara aaye toh direct DP table se answer mil jata hai.
Is wajah se time complexity O(n²) ho jaati hai."


--------------------------------------------------------------------------------------------------------------------


 