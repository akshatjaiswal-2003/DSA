//T.C : O(m*n)
//S.C : O(m*n)


class Solution {
public:

    //     🔹 Problem: Shortest Common Supersequence (SCS)

    //     🔹 Definition:
    //     Shortest string jo:
    //     ✔ s1 ko subsequence ke form me contain kare
    //     ✔ s2 ko subsequence ke form me contain kare
    //     ✔ length minimum ho

    //     🔹 Example:
    //     s1 = "abac"
    //     s2 = "cab"
    //     SCS = "cabac"

    //     🔹 Key Relation:
    //     Length(SCS) = m + n - Length(LCS)

    string shortestCommonSupersequence(string s1, string s2) 
    {

        int m = s1.length();   // length of first string
        int n = s2.length();   // length of second string

        //     🔹 DP Table
        //     t[i][j] = length of SCS of
        //               first i characters of s1
        //               first j characters of s2
        vector<vector<int>> t(m+1, vector<int>(n+1));

        // 🔄 STEP-1 : DP table fill karna (Bottom-Up)
        for(int i = 0; i < m+1; i++) 
        {
            for(int j = 0; j < n+1; j++) 
            {

                // 🛑 BASE CASE
                // Agar s1 empty hai → s2 ke saare characters add karne padenge
                // Agar s2 empty hai → s1 ke saare characters add karne padenge
                if(i == 0 || j == 0) t[i][j] = i + j;

                // ✅ CASE-1 : Characters MATCH
                // Agar s1[i-1] == s2[j-1]
                // Toh ek hi character add hoga
                else if(s1[i-1] == s2[j-1]) t[i][j] = 1 + t[i-1][j-1];

                // ❌ CASE-2 : Characters MATCH nahi hue
                // Dono options try karo:
                // 1️⃣ s1 ka char lo → t[i-1][j]
                // 2️⃣ s2 ka char lo → t[i][j-1]
                // Jo minimum length de → wahi choose
                else t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
            }
        }

        //     🔹 STEP-2 : DP table se actual SCS string banana
        //     - Start from bottom-right (m, n)
        //     - Backtracking similar to LCS
        //     - Difference: yahan hume characters add karte rehna hai

        string scs = "";
        int i = m, j = n;

        while(i > 0 && j > 0) 
        {
            // ✅ CASE-1 : Characters MATCH
            // Ek hi character add hoga
            if(s1[i-1] == s2[j-1]) 
            {
                scs.push_back(s1[i-1]);

                // Diagonal move
                i--;
                j--;
            }
            // ❌ CASE-2 : Characters MATCH nahi hue
            else 
            {
                // Jis direction me SCS length chhoti ho
                // wahi character add karo
                if(t[i-1][j] < t[i][j-1]) 
                {
                    // s1 ka character add
                    scs.push_back(s1[i-1]);
                    i--;
                } 
                else 
                {
                    // s2 ka character add
                    scs.push_back(s2[j-1]);
                    j--;
                }
            }
        }

        // 🔄 STEP-3 : Agar koi string abhi bhi bachi ho
        // Toh uske saare characters add kar do

        while(i > 0) 
        {
            scs.push_back(s1[i-1]);
            i--;
        }

        while(j > 0) 
        {
            scs.push_back(s2[j-1]);
            j--;
        }

        // 🔄 Reverse because hum last se first build kar rahe the
        reverse(scs.begin(), scs.end());

        // 🔥 Final Shortest Common Supersequence
        return scs;
    }
};


🧠 INTERVIEW GOLD EXPLANATION

"Shortest Common Supersequence DP se solve hoti hai.
t[i][j] represent karta hai SCS length of first i characters of s1 and first j characters of s2.
Agar characters match karte hain toh ek hi character add hota hai, warna minimum wale path ko choose karte hain.
DP table banane ke baad backtracking karke actual SCS string construct karte hain."
