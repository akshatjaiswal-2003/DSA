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


 // Approach-3 : Bottom-Up Dynamic Programming
// (🔥 My Favourite Blueprint for Palindromic Questions 🔥)

// Time Complexity  : O(n^2)
// Space Complexity : O(n^2)

/*
    🔹 Problem:
    Count all palindromic substrings in a given string.

    🔹 Key Idea (Bottom-Up DP):
    - Ek DP table banaate hain jahan:
        t[i][j] = true  → substring s[i...j] palindrome hai
        t[i][j] = false → palindrome nahi hai

    - DP ko substring LENGTH ke increasing order me fill karte hain
      taaki jab hume t[i+1][j-1] chahiye,
      wo pehle se calculated ho
*/

class Solution {
public:
    int countSubstrings(string s) {

        int n = s.length();

        /*
            🔹 DP Table
            t[i][j] = true  → s[i...j] palindrome hai
            i aur j dono inclusive indices hain
        */
        vector<vector<bool>> t(n, vector<bool>(n, false));

        int count = 0; // Total palindromic substrings

        /*
            🔹 L = Length of substring
            Hum 1 length se n length tak sab substrings check karenge

            Why length-based loop?
            - Palindrome of length L depends on length L-2
            - Bottom-Up DP ka proper flow banta hai
        */
        for(int L = 1; L <= n; L++) {

            /*
                🔹 i = starting index of substring
                Condition: i + L <= n
                (taaki substring boundary ke bahar na jaye)
            */
            for(int i = 0; i + L <= n; i++) {

                // 🔹 Ending index of substring
                int j = i + L - 1;

                /*
                    🔹 CASE-1: Single character substring
                    Example: "a"
                    Har single character palindrome hota hai
                */
                if(i == j) {
                    t[i][i] = true;
                }

                /*
                    🔹 CASE-2: Substring of length 2
                    Example: "aa" or "ab"
                    Palindrome tabhi hoga jab dono characters equal ho
                */
                else if(i + 1 == j) {
                    t[i][j] = (s[i] == s[j]);
                }

                /*
                    🔹 CASE-3: Substring of length >= 3
                    Example: "aba", "abba"

                    Conditions:
                    1️⃣ First and last character equal ho
                    2️⃣ Beech ka substring palindrome ho
                       → t[i+1][j-1] == true
                */
                else {
                    t[i][j] = ( (s[i] == s[j]) && t[i+1][j-1] == true );
                }

                /*
                    🔹 Count update
                    - bool true → 1
                    - bool false → 0
                */
                count += t[i][j];
            }
        }

        // 🔥 Final count of palindromic substrings
        return count;
    }
};


🎯 INTERVIEW ONE-LINE EXPLANATION

"We use a bottom-up DP approach where dp[i][j] tells whether substring s[i…j] is a palindrome.
We fill the table by increasing substring length so smaller substrings are solved before larger ones.
Total palindromes are counted while building the DP table."


---------------------------------------------------------------------------------------------------------------



// Approach-4 : Smart Approach (Expand Around Center)

// Time Complexity  : O(n^2)
// Space Complexity : O(1)

/*
    🔹 Problem:
    Count all palindromic substrings in a given string.

    🔹 Key Observation:
    Har palindrome ka ek CENTER hota hai.

    🔹 Types of Palindromes:
    1️⃣ Odd length palindrome
        Example: "aba", "racecar"
        → Center ek single character hota hai

    2️⃣ Even length palindrome
        Example: "aa", "abba"
        → Center do characters ke beech hota hai

    🔹 Strategy:
    Har index ko center maan kar
    - left aur right side me expand karte jao
    - jab tak characters match karte rahein
*/

class Solution {
public:
    int count = 0; // Global counter to store total palindromic substrings

    /*
        🔹 check() function
        i  → left pointer
        j  → right pointer
        n  → length of string

        Ye function "center se bahar ki taraf expand" karta hai
        aur har valid palindrome ko count karta hai
    */
    void check(string& s, int i, int j, int n) {

        /*
            🔹 Jab tak:
            - left pointer valid ho
            - right pointer valid ho
            - dono characters equal ho

            Tab tak substring s[i...j] palindrome rahega
        */
        while(i >= 0 && j < n && s[i] == s[j]) {

            // 🔥 Ek valid palindrome mil gaya
            count++;

            // 🔹 Expand from center
            i--; // left side expand
            j++; // right side expand
        }
    }

    int countSubstrings(string s) {

        int n = s.length();
        count = 0; // Reset count for each test case

        /*
            🔹 Main Idea:
            Har index i ko palindrome ka center maano

            For each i:
            1️⃣ Odd length palindrome:
                Center at s[i]
                check(s, i, i)

            2️⃣ Even length palindrome:
                Center between s[i] and s[i+1]
                check(s, i, i+1)
        */
        for(int i = 0; i < n; i++) {

            // 🔹 Odd length palindromes
            // Example: "aba"
            check(s, i, i, n);

            // 🔹 Even length palindromes
            // Example: "aa", "abba"
            check(s, i, i+1, n);
        }

        // 🔥 Total palindromic substrings
        return count;
    }
};



🎯 INTERVIEW ONE-LINER

"Every palindrome expands from a center.
We consider each index as a center for odd-length palindromes and 
each adjacent pair as a center for even-length palindromes, expanding 
outward while characters match."


----------------------------------------------------------------------------------------------------------------


🔥 Manacher’s Algorithm – HEAVY & DETAILED COMMENTS (Hinglish) 🔥


class Solution {
public:
    string longestPalindrome(string s) {

        /*
        =====================================================
        🔹 STEP 1: STRING TRANSFORMATION
        =====================================================

        Original string me:
        - Odd length palindrome: "aba"
        - Even length palindrome: "abba"

        Dono ko uniformly handle karna mushkil hota hai

        👉 Trick:
        Har character ke beech '#' daal do
        Start me '^' aur end me '$' add karo
        (ye boundaries ke liye hote hain, out of bound avoid)

        Example:
        s = "abba"

        Transformed string t:
        "^#a#b#b#a#$"

        Ab:
        ✔ Har palindrome odd length ka ho gaya
        ✔ Center-based expansion easy ho gayi
        */

        string t = "^";
        for(char c : s) {
            t += "#";   // separator
            t += c;     // original character
        }
        t += "#$";      // ending boundary

        /*
        =====================================================
        🔹 STEP 2: PALINDROME RADIUS ARRAY
        =====================================================

        P[i] = length of palindrome centered at index i in transformed string

        Agar P[i] = 3
        ⇒ means i ke left aur right 3 characters tak palindrome hai
        */

        int n = t.length();
        vector<int> P(n, 0);

        /*
        =====================================================
        🔹 STEP 3: CENTER & RIGHT POINTERS
        =====================================================

        center → center of the current right-most palindrome
        right  → right boundary (end) of that palindrome

        Ye dono help karte hain:
        ✔ previous palindromes ka use karne me
        ✔ repeated comparisons avoid karne me
        */

        int center = 0, right = 0;

        /*
        =====================================================
        🔹 STEP 4: MAIN MANACHER LOOP
        =====================================================
        i = current center jaha palindrome check karna hai
        */

        for(int i = 1; i < n-1; i++) {

            /*
            🔹 Mirror index calculation

            mirror = 2*center - i

            Idea:
            Agar i right boundary ke andar hai,
            toh uska mirror bhi pehle compute ho chuka hoga
            */

            int mirror = 2*center - i;

            /*
            🔹 Case 1: i < right
            Matlab:
            i kisi pehle se known palindrome ke andar hai

            Toh hum direct mirror ka result reuse kar sakte hain
            */

            if(i < right)
                P[i] = min(right - i, P[mirror]);

            /*
            🔹 Case 2: Expand around i

            Ab manually check karte hain
            ki i ke left aur right characters equal hain ya nahi

            Jab tak equal hain:
            palindrome expand hota rahega
            */

            while(t[i + 1 + P[i]] == t[i - 1 - P[i]])
                P[i]++;

            /*
            🔹 Agar naya palindrome right boundary se aage nikal gaya
            toh:
            - center update
            - right update
            */

            if(i + P[i] > right) {
                center = i;
                right  = i + P[i];
            }
        }

        /*
        =====================================================
        🔹 STEP 5: LONGEST PALINDROME FIND KARNA
        =====================================================
        P array me maximum value dhundo
        */

        int maxLen = 0;
        int centerIndex = 0;

        for(int i = 1; i < n-1; i++) {
            if(P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        /*
        =====================================================
        🔹 STEP 6: ORIGINAL STRING ME CONVERT KARNA
        =====================================================

        Formula:
        start index in original string =
        (centerIndex - maxLen) / 2

        Kyunki:
        - '#' characters add hue the
        - Har original character ke pehle ek '#'

        Example:
        Transformed index → Original index mapping
        */

        int start = (centerIndex - maxLen) / 2;

        // Final answer
        return s.substr(start, maxLen);
    }
};


🧠 KEY INTUITION (YAAD RAKHNE KE LIYE)

✔ # lagane se even/odd ka problem khatam
✔ mirror repeated work bachata hai
✔ center + right ensure O(n) time
✔ Har character max 1 baar expand hota hai




🎯 INTERVIEW ME KAISE BOLOGE?

“Manacher’s Algorithm uses symmetry of palindromes.
It avoids re-expansion by using previously computed palindromic spans through mirror positions, 
achieving linear time complexity.”