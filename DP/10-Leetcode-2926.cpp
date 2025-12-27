// ------------------------------------------------------------
// Approach-1 : LIS style Recursion + Memoization (TLE)
// ------------------------------------------------------------
// Problem Idea:
// Hume ek subsequence choose karni hai jisme
// condition satisfy ho:
//      nums[i] - i >= nums[prev] - prev
//
// Aur hume maximum possible SUM nikalna hai
//
// Ye exactly LIS jaisa hai, bas comparison thoda modified hai
// ------------------------------------------------------------
class Solution {
public:

    // Memoization map
    // key = "i_prev"
    // value = maximum sum possible from index i with previous index = prev
    unordered_map<string, long long> mp;
    
    /*
        solve(i, prev):
        ----------------
        i     -> current index jahan se decision lena hai
        prev  -> last chosen index (subsequence ka last element)
                 -1 ka matlab abhi kuch choose nahi kiya
    */
    long long solve(int i, int prev, vector<int>& nums) {

        // ---------------- BASE CASE ----------------
        // Agar array ke end tak pahunch gaye
        // toh koi aur element add nahi ho sakta
        if(i >= nums.size()) {
            return 0;
        }

        // ---------------- MEMO KEY ----------------
        // Har state uniquely defined hai (i, prev) se
        // Isliye hum string key bana rahe hain
        string key = to_string(i) + "_" + to_string(prev);

        // Agar pehle se calculate ho chuka hai
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        // ---------------- TAKE CASE ----------------
        // "taken" ka matlab:
        // nums[i] ko subsequence me include karte hain
        long long taken = INT_MIN;

        // Condition check (Balanced condition):
        // nums[i] - i >= nums[prev] - prev
        //
        // prev == -1 -> pehla element hai, toh allowed hai
        if(prev == -1 || nums[i] - i >= nums[prev] - prev) {

            // nums[i] ko include karte hain
            // aur next decision i+1 se lete hain
            taken = nums[i] + solve(i+1, i, nums);
        }
        
        // ---------------- NOT TAKE CASE ----------------
        // nums[i] ko skip kar dete hain
        // prev same rehta hai
        long long not_taken = solve(i+1, prev, nums);

        // ---------------- STORE & RETURN ----------------
        // Dono options me se maximum sum store karte hain
        return mp[key] = max<long long>(taken, not_taken);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {

        // Edge Case:
        // Agar saare elements <= 0 hain
        // toh best answer wahi single maximum element hoga
        int maxEl = *max_element(begin(nums), end(nums));
        if(maxEl <= 0) {
            return maxEl;
        }

        // Starting point:
        // i = 0 (start index)
        // prev = -1 (abhi kuch choose nahi kiya)
        return solve(0, -1, nums);
    }
};



// ------------------------------------------------------------
// Approach-2 : Using LIS Bottom Up DP
// Time Complexity : O(n^2)
// Space Complexity : O(n)
// Status : TLE (341 / 345 testcases passed)
// ------------------------------------------------------------
// Idea:
// Ye problem ko hum LIS (Longest Increasing Subsequence) jaisa treat kar rahe hain
// Bas difference ye hai ki comparison normal nums[i] > nums[j] ka nahi hai
// Balki:
//      nums[i] - i >= nums[j] - j
//
// Aur LIS ki length nahi, balki LIS ka MAXIMUM SUM nikalna hai
// ------------------------------------------------------------
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        
        // --------------------------------------------------------
        // Edge Case:
        // Agar array ke saare elements <= 0 hain
        // toh best balanced subsequence sirf ek element hogi
        // jo maximum element hai
        // --------------------------------------------------------
        int maxEl = *max_element(begin(nums), end(nums));
        if(maxEl <= 0) {
            return maxEl;
        }

        // --------------------------------------------------------
        // DP array:
        // t[i] = maximum balanced subsequence SUM
        //        jo index i par END hoti hai
        //
        // Initially:
        // Har element khud me ek subsequence hai
        // toh t[i] = nums[i]
        // --------------------------------------------------------
        vector<long long> t(n);
        for(int i = 0; i < n; i++) {
            t[i] = nums[i];
        }

        // Ye overall answer track karega
        long long maxSum = INT_MIN;

        // --------------------------------------------------------
        // Bottom-Up LIS DP
        //
        // i = current element (end of subsequence)
        // j = previous elements (0 ... i-1)
        // --------------------------------------------------------
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                // ------------------------------------------------
                // Balanced condition check:
                // nums[i] - i >= nums[j] - j
                //
                // Agar ye satisfy hoti hai,
                // toh nums[i] ko subsequence me add kar sakte hain
                // ------------------------------------------------
                if(nums[i] - i >= nums[j] - j) {

                    // Option:
                    // nums[j] par khatam hone wali subsequence
                    // me nums[i] add kar do
                    //
                    // t[j] + nums[i]
                    t[i] = max<long long>(t[i], t[j] + nums[i]);

                    // Global maximum update
                    maxSum = max<long long>(maxSum, t[i]);
                }
            }
        }

        // --------------------------------------------------------
        // Final Answer:
        // Kabhi-kabhi best answer single element hi hota hai
        // Isliye max(maxSum, maxEl) return karte hain
        // --------------------------------------------------------
        return maxSum > maxEl ? maxSum : maxEl;
    }
};






// ------------------------------------------------------------
// Approach-3 : Optimal LIS style (Similar to Patience Sorting)
// ------------------------------------------------------------
// Time Complexity : O(n log n)
// Space Complexity: O(n)
//
// Idea:
// ----
// Balanced condition:
//      nums[i] - i >= nums[j] - j
//
// Isko LIS jaise treat karte hain jahan:
//      "key"   = nums[i] - i
//      "value" = maximum subsequence SUM ending at this key
//
// map<int, long long> use karte hain taaki
// keys sorted rahein aur upper_bound ka use ho sake
// ------------------------------------------------------------
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) 
    {
        int n = nums.size();

        // map:
        // key   -> nums[i] - i
        // value -> maximum balanced subsequence sum ending with this key
        //
        // Yeh map hamesha increasing keys ke saath "best possible sums" store karta hai
        map<int, long long> mp;

        // Final answer store karne ke liye
        long long ans = INT_MIN;
        
        // Har element ko LIS-style process karenge
        for(int i = 0; i < n; i++) 
        {

            // ----------------------------------------------------
            // STEP 1: current element ka "balance key" nikaalo
            // ----------------------------------------------------
            int key = nums[i] - i;

            // ----------------------------------------------------
            // STEP 2: mp.upper_bound(key)
            // ----------------------------------------------------
            // Yeh iterator dega:
            //   first element jiska key > current key
            //
            // Matlab:
            //   hum current element ko un subsequences ke saath
            //   jod sakte hain jinka key <= current key
            auto it = mp.upper_bound(key);

            // ----------------------------------------------------
            // STEP 3: Base case
            // ----------------------------------------------------
            // Agar hum kisi previous subsequence ko extend nahi kar paaye
            // toh sirf nums[i] hi subsequence hoga
            long long cur_ans = nums[i];

            // ----------------------------------------------------
            // STEP 4: Best previous subsequence dhoondhna
            // ----------------------------------------------------
            // Agar it != mp.begin():
            //   iska matlab koi key <= current key exist karta hai
            if(it != mp.begin()) 
            {
                it--; // largest key <= current key
                cur_ans += it->second; // previous best sum add karo
            }

            // ----------------------------------------------------
            // STEP 5: map update
            // ----------------------------------------------------
            // Agar same key pe pehle se koi value hai,
            // toh maximum sum hi store karenge
            mp[key] = max(mp[key], cur_ans);

            // ----------------------------------------------------
            // STEP 6: Dominated states remove karna (IMPORTANT)
            // ----------------------------------------------------
            // Ab hum un entries ko hata dete hain:
            //   jinka key > current key
            //   AND
            //   jinka sum <= cur_ans
            //
            // Reason:
            //   Agar koi future element aayega,
            //   toh woh hamesha cur_ans wali state ko prefer karega
            it = mp.upper_bound(key);

            while(it != mp.end() && it->second <= cur_ans) 
            {
                mp.erase(it++); // erase and move iterator safely
            }

            // ----------------------------------------------------
            // STEP 7: Global answer update
            // ----------------------------------------------------
            ans = max(ans, cur_ans);
        }

        return ans;
    }
};


