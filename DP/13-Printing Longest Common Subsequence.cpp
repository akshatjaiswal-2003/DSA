//Using LCS code
//T.C : O(m*n)
//S.C : O(m*n)


class Solution {
public:

    /*
        🔹 Function: printLongestCommonSubsequence
        - Ye function sirf LCS length nahi
        - Balki actual LCS STRING print karta hai

        🔹 Approach:
        1️⃣ Pehle Bottom-Up DP table banao (length ke liye)
        2️⃣ Phir table ko backtrack karke LCS string banao
    */
    void printLongestCommonSubsequence(string s1, string s2) {

        int m = s1.length();   // length of first string
        int n = s2.length();   // length of second string

        /*
            🔹 DP table
            t[i][j] = LCS length of
                      first i characters of s1
                      first j characters of s2
        */
        vector<vector<int>> t(m+1, vector<int>(n+1));

        // 🛑 BASE CASE INITIALIZATION
        // Jab s2 empty ho (j = 0), LCS = 0
        for(int row = 0; row < m+1; row++) {
            t[row][0] = 0;
        }

        // Jab s1 empty ho (i = 0), LCS = 0
        for(int col = 0; col < n+1; col++) {
            t[0][col] = 0;
        }

        // 🔄 STEP-1 : DP table fill karna
        for(int i = 1; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {

                // ✅ CASE-1 : Characters MATCH
                // Agar s1 ka (i-1)th character
                // s2 ke (j-1)th character ke barabar hai
                if(s1[i-1] == s2[j-1]) {

                    // Diagonal value + 1
                    t[i][j] = 1 + t[i-1][j-1];

                } 
                // ❌ CASE-2 : Characters MATCH nahi hue
                else {

                    // Upar (i-1, j) aur
                    // Left (i, j-1) me se maximum
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        /*
            🔹 STEP-2 : DP table se LCS string banana
            - Start bottom-right cell se (m, n)
            - Jab tak i > 0 aur j > 0
            - Moves:
                ↖ (diagonal) → character match
                ↑ (up)       → i--
                ← (left)     → j--
        */

        string lcs = "";   // LCS store karne ke liye

        int i = m, j = n;  // Start from last cell

        while(i > 0 && j > 0) {

            // ✅ CASE-1 : Characters MATCH
            if(s1[i-1] == s2[j-1]) {

                // Ye character LCS ka part hai
                lcs.push_back(s1[i-1]);

                // Diagonal move
                i--;
                j--;
            }
            // ❌ CASE-2 : Characters MATCH nahi hue
            else {

                // DP table me jahan value zyada ho
                // us direction me move karte hain
                if(t[i-1][j] > t[i][j-1]) {
                    i--;    // move UP
                } else {
                    j--;    // move LEFT
                }
            }
        }

        // 🔄 Reverse because hum LCS ko
        // last se first build kar rahe the
        reverse(begin(lcs), end(lcs));

        // 🔥 Print final LCS string
        cout << lcs << endl;
    }
};


🔥 INTERVIEW ME AISE EXPLAIN KARNA

"Pehle maine Bottom-Up DP table banayi jo LCS length store karti hai.
Uske baad last cell se backtracking ki.
Jab characters match hue, maine diagonal move karke character LCS me add kiya.
Jab match nahi hue, tab DP table ke maximum wale direction me move kiya.
End me string reverse karke actual LCS mil gaya."