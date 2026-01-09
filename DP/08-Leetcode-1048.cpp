// -------------------------------------------------------------
// Approach-1: Simple LIS-style Recursion + Memoization
//
// Problem:
// Aapko words ka array diya gaya hai.
// Ek "string chain" banana hai jisme:
//
//   word2 is predecessor of word1
//   agar word1 me sirf 1 extra character add karke
//   word2 ban sakta ho (order same rehna chahiye)
//
// Example:
// "a" -> "ba" -> "bda" -> "bdca"
//
// Since question allow karta hai
// "words kisi bhi order me choose ho sakte hain",
// hum words ko pehle length ke basis par sort karte hain.
//
// Time Complexity: O(n * n * L)
// (n^2 DP states + L length predecessor check)
// -------------------------------------------------------------
class Solution {
public:

    int n;                      // Total number of words
    int t[1001][1001];          // DP memo table

    // ---------------------------------------------------------
    // predecessor(prev, curr)
    //
    // Check karta hai:
    // kya 'prev' string, 'curr' ka predecessor ho sakta hai?
    //
    // Condition:
    // 1) curr.length = prev.length + 1
    // 2) prev ke saare characters curr me same order me mil jaayein
    // ---------------------------------------------------------
    bool predecessor(string& prev, string& curr) {

        int M = prev.length();
        int N = curr.length();

        // -----------------------------------------------------
        // Agar length condition satisfy nahi karti
        // toh predecessor possible hi nahi
        // -----------------------------------------------------
        if (M >= N || N - M != 1)
            return false;

        int i = 0, j = 0;

        // -----------------------------------------------------
        // Two pointer technique:
        // prev aur curr ko compare karte hain
        // curr me ek extra character allowed hai
        // -----------------------------------------------------
        while (i < M && j < N) {

            if (prev[i] == curr[j]) {
                i++;   // match mil gaya
            }
            j++;       // curr pointer hamesha aage badhta hai
        }

        // -----------------------------------------------------
        // Agar prev ke saare characters match ho gaye
        // toh prev predecessor hai
        // -----------------------------------------------------
        return i == M;
    }

    // ---------------------------------------------------------
    // lis() function (LIS-style recursion)
    //
    // prev_idx  -> last selected word index
    // curr_idx  -> current word under consideration
    //
    // Goal:
    // curr_idx se start karke
    // maximum string chain length nikaalna
    // ---------------------------------------------------------
    int lis(vector<string>& words, int prev_idx, int curr_idx) {

        // -----------------------------------------------------
        // Base Case:
        // Agar saare words check ho gaye
        // -----------------------------------------------------
        if (curr_idx == n)
            return 0;

        // -----------------------------------------------------
        // Memoization:
        // prev_idx == -1 store nahi kar rahe
        // kyunki -1 DP index nahi ho sakta
        // -----------------------------------------------------
        if (prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];

        // -----------------------------------------------------
        // Option-1: Current word ko chain me include karo
        // -----------------------------------------------------
        int taken = 0;

        // -----------------------------------------------------
        // Include tabhi kar sakte hain agar:
        // 1) Koi previous word nahi hai (first word)
        // 2) Ya previous word current ka predecessor ho
        // -----------------------------------------------------
        if (prev_idx == -1 || predecessor(words[prev_idx], words[curr_idx]))
            taken = 1 + lis(words, curr_idx, curr_idx + 1);

        // -----------------------------------------------------
        // Option-2: Current word ko skip karo
        // -----------------------------------------------------
        int not_taken = lis(words, prev_idx, curr_idx + 1);

        // -----------------------------------------------------
        // Memo table update
        // -----------------------------------------------------
        if (prev_idx != -1)
            t[prev_idx][curr_idx] = max(taken, not_taken);

        // -----------------------------------------------------
        // Best answer return
        // -----------------------------------------------------
        return max(taken, not_taken);
    }

    // ---------------------------------------------------------
    // Custom sort function:
    // Words ko unki length ke basis par sort karne ke liye
    // ---------------------------------------------------------
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }

    // ---------------------------------------------------------
    // Main function
    // ---------------------------------------------------------
    int longestStrChain(vector<string>& words) {

        // DP table initialize
        memset(t, -1, sizeof(t));

        n = words.size();

        // -----------------------------------------------------
        // Sorting is VERY IMPORTANT
        //
        // Kyunki predecessor hamesha
        // chhoti length -> badi length hota hai
        // -----------------------------------------------------
        sort(begin(words), end(words), myFunction);

        // Start recursion:
        // prev_idx = -1 (koi word select nahi hua)
        // curr_idx = 0
        return lis(words, -1, 0);
    }
};



// -------------------------------------------------------------
// Approach-2: Bottom-Up Dynamic Programming (LIS Style)
//
// Problem Recap:
// Aapko words ka array diya gaya hai.
// Ek longest string chain banana hai jisme:
//
//   word2 predecessor hoga word1 ka
//   agar:
//     1) word1 ki length = word2 ki length + 1
//     2) word2 ke saare characters word1 me
//        same order me mil jaayein
//
// Question allow karta hai:
// "words kisi bhi order me choose ho sakte hain"
// Isliye hum pehle words ko length ke basis par sort karte hain.
//
// Time Complexity: O(n * n * L)
//   n^2 DP transitions
//   L predecessor check
//
// Space Complexity: O(n)
// -------------------------------------------------------------
class Solution {
public:

    // ---------------------------------------------------------
    // predecessor(prev, curr)
    //
    // Check karta hai:
    // kya 'prev' string, 'curr' ka predecessor ho sakta hai?
    //
    // Condition:
    // 1) curr.length = prev.length + 1
    // 2) prev ke characters curr me
    //    same order me hone chahiye
    // ---------------------------------------------------------
    bool predecessor(string& prev, string& curr) {

        int m = prev.length();
        int n = curr.length();

        // -----------------------------------------------------
        // Length condition fail hui toh predecessor possible nahi
        // -----------------------------------------------------
        if (m >= n || n - m != 1)
            return false;

        int i = 0, j = 0;

        // -----------------------------------------------------
        // Two Pointer Technique:
        // prev aur curr ko left se compare karte hain
        // curr me ek extra character allowed hai
        // -----------------------------------------------------
        while (i < m && j < n) {

            if (prev[i] == curr[j]) {
                i++;    // match hua
            }
            j++;        // curr hamesha aage badhta hai
        }

        // -----------------------------------------------------
        // Agar prev ke saare characters match ho gaye
        // toh predecessor valid hai
        // -----------------------------------------------------
        return i == m;
    }

    // ---------------------------------------------------------
    // Custom sort function
    // Words ko length ke basis par sort karne ke liye
    // ---------------------------------------------------------
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }

    // ---------------------------------------------------------
    // Main function
    // ---------------------------------------------------------
    int longestStrChain(vector<string>& words) {

        int n = words.size();

        // -----------------------------------------------------
        // Step-1: Sort words by length
        //
        // Kyunki predecessor hamesha
        // chhoti length → badi length hota hai
        // -----------------------------------------------------
        sort(begin(words), end(words), myFunction);

        // -----------------------------------------------------
        // DP array:
        // t[i] = longest string chain ending at i-th word
        //
        // Initially:
        // Har word khud ek chain bana sakta hai
        // isliye t[i] = 1
        // -----------------------------------------------------
        vector<int> t(n, 1);

        int maxL = 1; // final answer

        // -----------------------------------------------------
        // Step-2: Bottom-Up DP
        // -----------------------------------------------------
        for (int i = 0; i < n; i++) {

            // -------------------------------------------------
            // i se pehle ke saare words check karo
            // -------------------------------------------------
            for (int j = 0; j < i; j++) {

                // -------------------------------------------------
                // Agar words[j], words[i] ka predecessor hai
                // toh chain extend ho sakti hai
                // -------------------------------------------------
                if (predecessor(words[j], words[i])) {

                    // -------------------------------------------------
                    // DP transition:
                    // j-th chain + current word
                    // -------------------------------------------------
                    t[i] = max(t[i], t[j] + 1);

                    // -------------------------------------------------
                    // Global maximum update
                    // -------------------------------------------------
                    maxL = max(maxL, t[i]);
                }
            }
        }

        // -----------------------------------------------------
        // Final longest chain length
        // -----------------------------------------------------
        return maxL;
    }
};
