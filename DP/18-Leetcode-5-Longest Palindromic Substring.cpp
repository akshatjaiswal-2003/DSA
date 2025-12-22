// Approach 1 - Recursion + Memoization
// Idea:
// 1) Har possible substring s[l..r] ko check karo palindrome hai ya nahi
// 2) solve(l, r) batata hai: "s[l..r] palindrome hai?"
// 3) Memoization se same substring baar-baar check nahi hota
//
// IMPORTANT NOTE:
// Agar string "aaaaaaaaa" jaisi ho,
// bina memoization ke recursion bahut slow ho jata
// Memoization se har (l, r) sirf ek baar compute hota hai

// Time Complexity:
// O(n^2)
// Kyunki total possible states = (l, r) = n*n
// Aur memoization ki wajah se har state sirf 1 baar solve hoti hai
//
// Space Complexity:
// O(n^2) → DP table
// + recursion stack (max O(n))

class Solution {
public:

    /*
    t[l][r] ka matlab:
    -1 → abhi compute nahi hua
     0 → s[l..r] palindrome nahi hai
     1 → s[l..r] palindrome hai
    */
    int t[1001][1001];
    
    /*
    =====================================================
    🔹 Recursive function: solve(l, r)
    =====================================================
    Ye function check karta hai:
    "kya substring s[l..r] palindrome hai?"
    */
    bool solve(string &s, int l, int r){

        /*
        🛑 BASE CASE
        Agar l >= r ho gaya:
        - Single character (l == r) → palindrome
        - Empty substring (l > r) → palindrome

        Example:
        "a" , ""  → always palindrome
        */
        if(l >= r) 
            return 1;

        /*
        🔹 MEMOIZATION CHECK
        Agar pehle se answer nikal chuke hain
        toh wahi return kar do
        */
        if(t[l][r] != -1){
            return t[l][r];
        }

        /*
        🔹 MAIN LOGIC
        Agar first aur last character same hain,
        tabhi beech ka substring palindrome hona chahiye
        */
        if(s[l] == s[r]) {

            // Characters match → check inside substring
            return t[l][r] = solve(s, l+1, r-1);
        }

        /*
        Agar first aur last character different hain,
        toh palindrome possible hi nahi
        */
        return t[l][r] = false;
    }
    
    /*
    =====================================================
    🔹 Main function: longestPalindrome
    =====================================================
    Har possible substring generate karo
    aur solve() se check karo
    */
    string longestPalindrome(string s) {

        int n = s.length();

        // maxlen → longest palindrome ki length
        int maxlen = INT_MIN;

        // startingIndex → longest palindrome ka start index
        int startingIndex = 0;

        // DP table ko initialize karo
        memset(t, -1, sizeof(t));

        /*
        =====================================================
        🔹 Generate all substrings
        =====================================================
        i → start index
        j → end index
        */
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                /*
                Check:
                s[i..j] palindrome hai ya nahi
                */
                if(solve(s, i, j)) {

                    /*
                    Agar palindrome hai
                    aur length maxlen se zyada hai
                    toh update karo
                    */
                    if(j - i + 1 > maxlen){
                        startingIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }

        /*
        Longest palindromic substring return karo
        */
        return s.substr(startingIndex, maxlen);
    }
};


🎯 INTERVIEW ONE-LINER

“This approach uses recursion with memoization to check palindromic substrings efficiently,
reducing repeated computations and achieving O(n²) time complexity.”


--------------------------------------------------------------------------------------------------------------------------------------------


// Approach 2 - Looping simply in solve()
// Idea:
// 1) Har possible substring s[l..r] generate karo
// 2) solve() function se check karo ki palindrome hai ya nahi
// 3) Agar palindrome hai, toh maximum length update karo
//
// ⚠️ Ye brute-force approach hai
// Isme optimization ya memoization use nahi hoti
//
// Time Complexity:
// - Substring generation → O(n^2)
// - Palindrome check (solve) → O(n)
// Total → O(n^3)
//
// Space Complexity:
// O(1) (No extra DP table, sirf few variables)

class Solution {
public:

    /*
    =====================================================
    🔹 Function: solve(s, l, r)
    =====================================================
    Purpose:
    Check whether substring s[l..r] is palindrome or not

    Technique:
    Two-pointer approach
    - l pointer start se
    - r pointer end se
    - Dono characters compare karte hue andar ki taraf move
    */
    bool solve(string &s, int l, int r){
        
        /*
        Jab tak l <= r:
        - characters compare karo
        - mismatch mila toh directly false
        */
        while(l <= r) {

            // Agar dono ends ke characters different hain
            // toh palindrome possible nahi
            if(s[l] != s[r])
                return false;

            // Move pointers towards center
            l++;
            r--;
        }
        
        /*
        Agar loop poora chal gaya
        aur koi mismatch nahi mila
        toh substring palindrome hai
        */
        return true;
    }
    
    /*
    =====================================================
    🔹 Function: longestPalindrome
    =====================================================
    Har possible substring check karke
    longest palindromic substring return karta hai
    */
    string longestPalindrome(string s) {

        int n = s.length();

        // maxlen → longest palindrome ki length
        int maxlen = INT_MIN;

        // startingIndex → longest palindrome ka start index
        int startingIndex = 0;

        /*
        =====================================================
        🔹 Generate all possible substrings
        =====================================================
        i → start index
        j → end index
        */
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                /*
                Check karo:
                kya s[i..j] palindrome hai?
                */
                if(solve(s, i, j)) {

                    /*
                    Agar palindrome hai
                    aur length ab tak ke max se zyada hai
                    toh update karo
                    */
                    if(j - i + 1 > maxlen){
                        startingIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }

        /*
        Longest palindromic substring return karo
        */
        return s.substr(startingIndex, maxlen);
    }
};

🎯 INTERVIEW ONE-LINER

“This is a brute-force approach where we check all possible substrings and 
verify palindromes using a two-pointer technique, resulting in O(n³) time complexity.”


---------------------------------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    string longestPalindrome(string s) {

        /*
        =====================================================
        🔹 STEP 1: Basic setup
        =====================================================
        */

        int n = s.length();

        /*
        DP Table:
        t[i][j] = true  → substring s[i..j] is palindrome
        t[i][j] = false → not a palindrome

        Size: n x n
        Initially sab false
        */
        vector<vector<bool>> t(n, vector<bool>(n, false));

        /*
        maxL  → length of longest palindrome found so far
        start → starting index of that palindrome
        */
        int maxL = 1;   // Minimum palindrome length is 1
        int start = 0;

        /*
        =====================================================
        🔹 STEP 2: Base Case (Length = 1)
        =====================================================
        */

        /*
        Har single character apne aap mein palindrome hota hai
        Example: "a", "b", "c"
        */
        for(int i = 0; i < n; i++)
            t[i][i] = true;

        /*
        =====================================================
        🔹 STEP 3: Build DP table for substrings of length ≥ 2
        =====================================================
        */

        /*
        L → current substring length
        L = 2 se n tak grow karte hain
        (Bottom-Up DP)
        */
        for(int L = 2; L <= n; L++) {

            /*
            i → starting index of substring
            j → ending index = i + L - 1
            */
            for(int i = 0; i < n - L + 1; i++) {

                int j = i + L - 1;

                /*
                =====================================================
                🔹 Palindrome Condition
                =====================================================

                A substring s[i..j] is palindrome if:
                1) s[i] == s[j]
                AND
                2) Inner substring s[i+1..j-1] is palindrome

                BUT special case:
                - If L == 2 (two characters)
                  Then sirf s[i] == s[j] check karna kaafi hai
                  (no inner substring exists)
                */

                if(s[i] == s[j] && (t[i+1][j-1] || L == 2)) {

                    // Mark substring s[i..j] as palindrome
                    t[i][j] = true;

                    /*
                    Agar current palindrome length
                    pehle se zyada hai
                    toh answer update karo
                    */
                    if(L > maxL) {
                        maxL = L;
                        start = i;
                    }
                }
            }
        }

        /*
        =====================================================
        🔹 STEP 4: Result
        =====================================================
        */

        /*
        start se maxL length ka substring
        longest palindromic substring hoga
        */
        return s.substr(start, maxL);
    }
};



🎯 INTERVIEW ONE-LINER

“This solution uses bottom-up dynamic programming where t[i][j] stores whether substring s[i..j] is palindrome, allowing us to build longer palindromes from shorter ones in O(n²) time.”