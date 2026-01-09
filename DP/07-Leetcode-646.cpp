// -------------------------------------------------------------
// Approach-1: Simple LIS style Recursion + Memoization
//
// Problem:
// Aapko pairs diye gaye hain [a, b]
// Ek chain banaani hai jisme:
//   next_pair.start > prev_pair.end
//
// Since question bolta hai "pairs kisi bhi order me le sakte ho",
// isliye hum pehle pairs ko sort kar dete hain.
//
// Time Complexity: O(n * n)
// Space Complexity: O(n * n)
// -------------------------------------------------------------
class Solution {
public:

    int n;                      // Total number of pairs
    int t[1001][1001];          // DP table for memoization

    // ---------------------------------------------------------
    // lis() function:
    //
    // prev_idx  -> index of previously selected pair
    // curr_idx  -> index of current pair under consideration
    //
    // Goal:
    // curr_idx se start karke maximum chain length nikaalna
    // ---------------------------------------------------------
    int lis(vector<vector<int>>& nums, int prev_idx, int curr_idx) {

        // -----------------------------------------------------
        // Base Case:
        // Agar curr_idx end tak pahunch gaya
        // matlab koi pair left nahi
        // -----------------------------------------------------
        if (curr_idx == n)
            return 0;

        // -----------------------------------------------------
        // Memoization check:
        // prev_idx == -1 ka case store nahi kar rahe
        // kyunki -1 index DP me store nahi ho sakta
        // -----------------------------------------------------
        if (prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];

        // -----------------------------------------------------
        // Option-1: Current pair ko chain me include karo
        // -----------------------------------------------------
        int taken = 0;

        // -----------------------------------------------------
        // Pair tabhi le sakte hain agar:
        //   1) Pehla pair hai (prev_idx == -1)
        //   2) Ya current.start > previous.end
        // -----------------------------------------------------
        if (prev_idx == -1 || nums[curr_idx][0] > nums[prev_idx][1])
            taken = 1 + lis(nums, curr_idx, curr_idx + 1);

        // -----------------------------------------------------
        // Option-2: Current pair ko skip karo
        // -----------------------------------------------------
        int not_taken = lis(nums, prev_idx, curr_idx + 1);

        // -----------------------------------------------------
        // Memo table update (sirf valid prev_idx ke liye)
        // -----------------------------------------------------
        if (prev_idx != -1)
            t[prev_idx][curr_idx] = max(taken, not_taken);

        // -----------------------------------------------------
        // Best of take / not take return karo
        // -----------------------------------------------------
        return max(taken, not_taken);
    }

    // ---------------------------------------------------------
    // Main function
    // ---------------------------------------------------------
    int findLongestChain(vector<vector<int>>& pairs) {

        // DP table initialize with -1
        memset(t, -1, sizeof(t));

        n = pairs.size();

        // -----------------------------------------------------
        // Sorting is VERY IMPORTANT
        //
        // Kyunki question allow karta hai
        // "pairs kisi bhi order me le sakte ho"
        //
        // Sorting ke baad problem LIS jaisi ban jaati hai
        // -----------------------------------------------------
        sort(begin(pairs), end(pairs));

        // Start recursion:
        // prev_idx = -1 (koi pair select nahi hua)
        // curr_idx = 0 (first pair se start)
        return lis(pairs, -1, 0);
    }
};





// -------------------------------------------------------------
// Approach-2: Bottom-Up Dynamic Programming (LIS style)
//
// Problem Recap:
// Aapko pairs diye gaye hain [a, b]
// Ek chain banana hai jisme:
//   next_pair.start > previous_pair.end
//
// Question allow karta hai:
// "pairs kisi bhi order me le sakte ho"
// Isliye sabse pehle pairs ko sort karna zaroori hai.
//
// Time Complexity: O(n * n)
// Space Complexity: O(n)
// -------------------------------------------------------------
class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {

        int n = pairs.size();

        // -----------------------------------------------------
        // Step-1: Sorting pairs
        //
        // Kyunki pairs kisi bhi order me choose ho sakte hain,
        // sorting se problem LIS jaisi ban jaati hai.
        //
        // Sorting default:
        // pehle start ke basis par,
        // agar start same ho toh end ke basis par
        // -----------------------------------------------------
        sort(begin(pairs), end(pairs));

        // -----------------------------------------------------
        // DP array:
        // t[i] = maximum chain length ending at i-th pair
        //
        // Initially:
        // Har pair akela khud ek chain bana sakta hai
        // isliye sabko 1 se initialize karte hain
        // -----------------------------------------------------
        vector<int> t(n, 1);

        int maxL = 1; // overall longest chain

        // -----------------------------------------------------
        // Step-2: Bottom-Up DP computation
        // -----------------------------------------------------
        for (int i = 0; i < n; i++) {

            // -------------------------------------------------
            // i se pehle ke saare pairs check karo
            // -------------------------------------------------
            for (int j = 0; j < i; j++) {

                // -------------------------------------------------
                // Chain banane ki condition:
                // previous.end < current.start
                //
                // i.e.
                // pairs[j][1] < pairs[i][0]
                // -------------------------------------------------
                if (pairs[j][1] < pairs[i][0]) {

                    // -------------------------------------------------
                    // Agar j-th pair ke baad i-th pair lag sakta hai,
                    // toh chain length update karo
                    // -------------------------------------------------
                    t[i] = max(t[i], t[j] + 1);

                    // -------------------------------------------------
                    // Overall maximum update
                    // -------------------------------------------------
                    maxL = max(maxL, t[i]);
                }
            }
        }

        // -----------------------------------------------------
        // Final answer = longest chain found
        // -----------------------------------------------------
        return maxL;
    }
};
