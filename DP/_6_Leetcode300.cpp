// -------------------------------------------------------------
// Approach-1: Top Down DP (Recursion + Memoization)
//
// Time Complexity: O(n * n)
// Space Complexity: O(n * n) + recursion stack
//
// Idea:
// Har index par 2 choices hote hain:
//   1) Current element ko LIS me INCLUDE karo
//   2) Current element ko SKIP karo
//
// Memoization use karke repeated subproblems avoid karte hain
// -------------------------------------------------------------
class Solution {
public:

    // n = size of input array
    int n;

    // ---------------------------------------------------------
    // t[prev_idx][curr_idx] = LIS length
    //
    // Meaning:
    // prev_idx  → last element ka index jo LIS me include hua
    // curr_idx  → current index jahan se decision lena hai
    //
    // NOTE:
    // prev_idx = -1 ka matlab:
    //   abhi tak koi element select nahi hua
    //   is case ko DP table me store nahi kar sakte
    // ---------------------------------------------------------
    int t[2501][2501];

    int lis(vector<int>& nums, int prev_idx, int curr_idx) {

        // -----------------------------------------------------
        // BASE CASE:
        // Agar curr_idx array ke end tak pahunch gaya
        // toh aur elements nahi bache
        // → LIS length = 0
        // -----------------------------------------------------
        if (curr_idx == n)
            return 0;

        // -----------------------------------------------------
        // MEMOIZATION CHECK:
        // Agar prev_idx valid hai (≠ -1)
        // aur state already computed hai
        // toh directly answer return kar do
        // -----------------------------------------------------
        if (prev_idx != -1 && t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];

        // -----------------------------------------------------
        // OPTION 1: TAKE current element nums[curr_idx]
        //
        // Condition:
        //   - ya toh abhi tak koi element pick nahi hua (prev_idx == -1)
        //   - ya current element last picked element se bada ho
        //
        // Agar valid hai:
        //   LIS length = 1 + aage ka LIS
        // -----------------------------------------------------
        int taken = 0;
        if (prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
            taken = 1 + lis(nums, curr_idx, curr_idx + 1);

        // -----------------------------------------------------
        // OPTION 2: NOT TAKE current element
        //
        // Simply curr_idx ko skip kar do
        // prev_idx same rahega
        // -----------------------------------------------------
        int not_taken = lis(nums, prev_idx, curr_idx + 1);

        // -----------------------------------------------------
        // DP STORE:
        // sirf tab store karte hain jab prev_idx valid ho
        // (prev_idx = -1 ko store nahi kar sakte)
        // -----------------------------------------------------
        if (prev_idx != -1)
            t[prev_idx][curr_idx] = max(taken, not_taken);

        // -----------------------------------------------------
        // Return best of both choices
        // -----------------------------------------------------
        return max(taken, not_taken);
    }

    int lengthOfLIS(vector<int>& nums) {

        // -----------------------------------------------------
        // DP table ko -1 se initialize
        // matlab koi state abhi compute nahi hui
        // -----------------------------------------------------
        memset(t, -1, sizeof(t));

        // -----------------------------------------------------
        // Store size of array
        // -----------------------------------------------------
        n = nums.size();

        // -----------------------------------------------------
        // Start recursion:
        // prev_idx = -1 → koi element select nahi hua
        // curr_idx = 0  → array ka start
        // -----------------------------------------------------
        return lis(nums, -1, 0);
    }
};




// -------------------------------------------------------------
// Approach-2: Bottom-Up Dynamic Programming
//
// Time Complexity: O(n * n)
// Space Complexity: O(n)
//
// Idea:
// Har index i ke liye hum calculate karte hain ki
// LIS (Longest Increasing Subsequence) ka length
// jo index i par END ho raha hai, wo kya hai.
//
// Har element akela khud me ek LIS ho sakta hai
// isliye initial value = 1
// -------------------------------------------------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // ---------------------------------------------------------
        // n = size of input array
        // ---------------------------------------------------------
        int n = nums.size();

        // ---------------------------------------------------------
        // DP array t:
        // t[i] = LIS length ending exactly at index i
        //
        // Initially:
        // Har element khud ek subsequence bana sakta hai
        // isliye sabko 1 se initialize kiya
        // ---------------------------------------------------------
        vector<int> t(n, 1);

        // ---------------------------------------------------------
        // maxL will store the maximum LIS length found so far
        // At least 1 hoga agar array empty nahi hai
        // ---------------------------------------------------------
        int maxL = 1;

        // ---------------------------------------------------------
        // Outer loop:
        // i → current element jahan LIS end karna hai
        // ---------------------------------------------------------
        for (int i = 0; i < n; i++) {

            // -----------------------------------------------------
            // Inner loop:
            // j → saare previous elements (0 to i-1)
            //
            // Hum check karte hain:
            // kya nums[j] < nums[i] ?
            // agar haan, toh nums[i] ko
            // subsequence ke end me add kar sakte hain
            // -----------------------------------------------------
            for (int j = 0; j < i; j++) {

                // -------------------------------------------------
                // Agar increasing condition satisfy hoti hai
                // -------------------------------------------------
                if (nums[j] < nums[i]) {

                    // -------------------------------------------------
                    // t[i] ko update karte hain:
                    // either:
                    //   - purani value t[i]
                    //   - ya t[j] + 1 (nums[i] ko j ke baad add karke)
                    // -------------------------------------------------
                    t[i] = max(t[i], t[j] + 1);

                    // -------------------------------------------------
                    // Har update ke baad global maximum LIS update
                    // -------------------------------------------------
                    maxL = max(maxL, t[i]);
                }
            }
        }

        // ---------------------------------------------------------
        // maxL hi final LIS length hai
        // ---------------------------------------------------------
        return maxL;
    }
};




// -------------------------------------------------------------
// Approach-3: Converting LIS problem into LCS problem
//
// Time Complexity: O(n * n)
// Space Complexity: O(n * n)
//
// Core Idea:
// Longest Increasing Subsequence (LIS) ko hum
// Longest Common Subsequence (LCS) me convert kar sakte hain.
//
// Kaise?
// 1) Original array = nums
// 2) nums ka ek sorted + unique version bana lo
// 3) In dono arrays ka LCS nikaal lo
//
// Reason:
// Sorted unique array strictly increasing hota hai.
// Jo sequence dono me common hoga, wahi LIS hoga.
// -------------------------------------------------------------
class Solution {
public:

    // ---------------------------------------------------------
    // Function to calculate Longest Common Subsequence (LCS)
    // between two integer arrays
    // ---------------------------------------------------------
    int LCS(vector<int>& nums1, vector<int>& nums2) {

        // Length of both arrays
        int m = nums1.size();
        int n = nums2.size();

        // -----------------------------------------------------
        // DP table:
        // t[i][j] = LCS length between
        // first i elements of nums1
        // first j elements of nums2
        // -----------------------------------------------------
        vector<vector<int>> t(m + 1, vector<int>(n + 1));

        // -----------------------------------------------------
        // Base Case:
        // Agar koi ek array empty hai
        // toh LCS length = 0
        // -----------------------------------------------------
        for (int j = 0; j <= n; j++)
            t[0][j] = 0;

        for (int i = 0; i <= m; i++)
            t[i][0] = 0;

        // -----------------------------------------------------
        // Filling the DP table bottom-up
        // -----------------------------------------------------
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // -------------------------------------------------
                // Case 1:
                // Agar current elements equal hain
                // toh LCS length +1 ho jayegi
                // -------------------------------------------------
                if (nums1[i - 1] == nums2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];

                // -------------------------------------------------
                // Case 2:
                // Agar match nahi hua
                // toh max lete hain:
                //   - nums1 ka element skip karo
                //   - nums2 ka element skip karo
                // -------------------------------------------------
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }

        // -----------------------------------------------------
        // Last cell me final LCS length hoti hai
        // -----------------------------------------------------
        return t[m][n];
    }

    // ---------------------------------------------------------
    // Main LIS function
    // ---------------------------------------------------------
    int lengthOfLIS(vector<int>& nums) {

        // -----------------------------------------------------
        // Step 1:
        // Set ka use karke duplicate elements hata rahe hain
        // kyunki LIS strictly increasing hota hai
        // -----------------------------------------------------
        set<int> st(begin(nums), end(nums));

        // -----------------------------------------------------
        // Step 2:
        // Set se vector bana liya
        // Ye automatically sorted hota hai
        // -----------------------------------------------------
        vector<int> nums2(begin(st), end(st));

        // -----------------------------------------------------
        // Step 3:
        // Original array & sorted-unique array ka LCS nikaal lo
        // Wahi answer hoga LIS ka
        // -----------------------------------------------------
        return LCS(nums, nums2);
    }
};




// -------------------------------------------------------------
// Approach-4: Using Patience Sorting Concept
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)
//
// Ye LIS ka SABSE OPTIMAL approach hai.
//
// Core Idea:
// Ek array "sorted" maintain karte hain
// jisme:
// sorted[k] = length (k+1) ki LIS ka
//            sabse chhota possible ending element
//
// NOTE:
// Ye array actual LIS nahi hota,
// lekin iski length = LIS length hoti hai.
// -------------------------------------------------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // -----------------------------------------------------
        // 'sorted' array ka role:
        // Ye possible LIS endings ko store karta hai
        // In increasing order
        // -----------------------------------------------------
        vector<int> sorted;

        // -----------------------------------------------------
        // Har element ko process karte hain
        // -----------------------------------------------------
        for (int i = 0; i < n; i++) {

            /*
            --------------------------------------------------
            lower_bound ka use kyun?
            
            lower_bound(sorted.begin(), sorted.end(), nums[i])
            👉 Pehla element deta hai jo >= nums[i] ho

            Why needed?
            1) LIS strictly increasing hota hai
            2) Duplicates allowed nahi
            3) Hume chhota ending element chahiye
               taaki future me zyada chance ho
               sequence ko extend karne ka

            Example:
            sorted = [2, 5, 7]
            nums[i] = 4

            lower_bound → 5
            replace karke:
            sorted = [2, 4, 7]
            (better option than 5)
            --------------------------------------------------
            */
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);

            // -------------------------------------------------
            // Case 1:
            // Agar nums[i] sabse bada hai
            // matlab LIS extend ho sakti hai
            // -------------------------------------------------
            if (it == sorted.end()) {
                sorted.push_back(nums[i]);
            }
            // -------------------------------------------------
            // Case 2:
            // nums[i] kisi existing element ko replace karega
            // taaki ending element chhota rahe
            // -------------------------------------------------
            else {
                *it = nums[i];
            }
        }

        // -----------------------------------------------------
        // 'sorted' ki length hi LIS ki length hoti hai
        // -----------------------------------------------------
        return (int)sorted.size();
    }
};





// -------------------------------------------------------------
// Approach-5: Using same idea as LeetCode 2926
// (Maximum Balanced Subsequence Sum)
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)
//
// Core Idea:
// Hum ek ordered map maintain karte hain jisme:
//
//   key   = element value (nums[i])
//   value = LIS length ending at that element
//
// Map ko aise maintain karte hain ki:
// 1) Keys strictly increasing ho
// 2) Values (LIS length) bhi increasing trend follow karein
// 3) Useless states ko remove kar diya jaaye
//
// Ye approach Patience Sorting + DP ka hybrid hai.
// -------------------------------------------------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // -----------------------------------------------------
        // mp[key] = LIS length ending with element = key
        //
        // Example:
        // mp = {
        //   2 -> 1,
        //   3 -> 2,
        //   7 -> 3
        // }
        // -----------------------------------------------------
        map<int, int> mp;

        int ans = 0; // final LIS length

        // -----------------------------------------------------
        // Iterate over each element of array
        // -----------------------------------------------------
        for (int i = 0; i < n; i++) {

            // -------------------------------------------------
            // Har element minimum 1 length ka LIS bana sakta hai
            // (element khud)
            // -------------------------------------------------
            int len = 1;

            // -------------------------------------------------
            // upper_bound(nums[i]) :
            // Pehla element jo strictly greater ho nums[i] se
            //
            // Iska previous element (if exists) <= nums[i]
            // -------------------------------------------------
            auto it = mp.upper_bound(nums[i]);

            // -------------------------------------------------
            // Agar map empty nahi hai aur
            // nums[i] se chhota koi element exist karta hai
            // -------------------------------------------------
            if (it != mp.begin()) {

                it--; // pichhle element par jao

                // -------------------------------------------------
                // Strictly increasing condition check
                // -------------------------------------------------
                if (it->first < nums[i]) {
                    // Previous LIS length + 1
                    len += it->second;
                }
            }

            // -------------------------------------------------
            // nums[i] ke liye best LIS length store karo
            // Agar pehle se koi value ho toh max lo
            // -------------------------------------------------
            mp[nums[i]] = max(mp[nums[i]], len);

            // -------------------------------------------------
            // Ab map cleanup karna hai:
            //
            // Agar nums[i] ke baad koi aisa element hai
            // jiska LIS length <= current len hai
            // toh wo useless ho gaya
            //
            // Kyunki:
            // - uska value bada hai
            // - lekin LIS length better nahi
            // -------------------------------------------------
            it = mp.upper_bound(nums[i]);

            while (it != mp.end() && it->second <= len) {
                mp.erase(it++); // dominated states remove
            }

            // -------------------------------------------------
            // Answer update
            // -------------------------------------------------
            ans = max(ans, len);
        }

        return ans;
    }
};
