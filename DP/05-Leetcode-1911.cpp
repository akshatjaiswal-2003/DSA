---------------------------------Approach-1 (Recursion + Memo)-------------------------------------------
// Time Complexity: O(n * 2) ≈ O(n) kyunki har index par hum 2 states visit karte hain (even/odd)
// Space Complexity: O(n * 2) for memo

class Solution {
public:
    int n;

    // DP table t[idx][iseven]
    // iseven = 1 → abhi positive sign lagna chahiye
    // iseven = 0 → abhi negative sign lagna chahiye
    long long t[1000001][2];

    long long solve(int idx, vector<int>& nums, bool iseven) {

        // BASE CASE:
        // agar idx array ke bahar chala gaya → koi value add nahi hogi
        if(idx >= n) {
            return 0;
        }

        // MEMO CHECK:
        // agar is state ka result pehle hi calculate ho chuka hai
        if(t[idx][iseven] != -1)
            return t[idx][iseven];

        // OPTION 1 → SKIP:
        // element ko skip kar do → sign same rahega
        long long skip = solve(idx+1, nums, iseven);

        // ELEMENT ko uthana hai ya nahi:
        long long val = nums[idx];

        // Agar ab turn odd index ke hisaab se treat ho raha hai
        // iseven == false → minus sign lagega
        if(iseven == false) {
            val = -val;
        }

        // OPTION 2 → TAKE:
        // agar element le liya → next turn ka sign flip ho jayega
        long long take = solve(idx+1, nums, !iseven) + val;

        // MAX of take and skip store kardo DP me
        return t[idx][iseven] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();

        // DP table ko initialize karna -1 se
        memset(t, -1, sizeof(t));

        // Start from index 0 with "positive" sign (iseven = true)
        return solve(0, nums, true);
    }
};









-----------------------------------Approach-2 (Bottom-Up DP)-------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// DP Meaning:
// t[i][0] → i-th element tak max alternating sum agar current element NEGATIVE sign ke saath lena ho.
// t[i][1] → i-th element tak max alternating sum agar current element POSITIVE sign ke saath lena ho.

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        // DP table: n rows × 2 columns
        vector<vector<long>> t(n, vector<long>(2, 0));

        // Initialization:
        // t[0][0] = max(-nums[0], 0)
        // Kyunki negative se start karne ka choice rarely useful hota hai,
        // but DP ko complete banane ke liye consider karte hain
        t[0][0] = max(-nums[0], 0);

        // t[0][1]:
        // First element agar positive lete hain
        t[0][1] = max(nums[0], 0);
        
        // DP transition:
        for(int i = 1; i < n; i++) 
        {

            // t[i][0]:
            // Hum NEGATIVE sign lagana chahte hain
            // Do choices:
            // 1. Take: t[i-1][1] - nums[i]  
            //      (pichle turn me + sign tha → ab - hoga)
            // 2. Skip: t[i-1][0]
            t[i][0] = max(t[i-1][1] - nums[i], t[i-1][0]);

            // t[i][1]:
            // Hum POSITIVE sign lagana chahte hain
            // Do choices:
            // 1. Take: t[i-1][0] + nums[i]
            //      (pichle turn me - sign tha → ab + hoga)
            // 2. Skip: t[i-1][1]
            t[i][1] = max(t[i-1][0] + nums[i], t[i-1][1]);
        }
        
        // Answer: last index ka best outcome
        return max(t[n-1][0], t[n-1][1]);
    }
};









-----------------------------Approach-3 (Using 1-based indexing for clarity)------------------------------
// t[i][0] = negative sign state
// t[i][1] = positive sign state

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        // DP table of size (n+1) × 2
        vector<vector<long>> t(n+1, vector<long>(2, 0));
        
        // 1-based indexing me loop 1 se start hota hai
        for(int i = 1; i <= n; i++) {

            // NEGATIVE state
            // Take: t[i-1][1] - nums[i-1]
            // Skip: t[i-1][0]
            t[i][0] = max(t[i-1][1] - nums[i-1], t[i-1][0]);
            
            // POSITIVE state
            // Take: t[i-1][0] + nums[i-1]
            // Skip: t[i-1][1]
            t[i][1] = max(t[i-1][0] + nums[i-1], t[i-1][1]);
        }
        
        // Answer from last index
        return max(t[n][0], t[n][1]);
    }
};




------------------------------------Space Optimized O(1) DP--------------------------------------------

// 💡 Key Idea

// DP table t[i][0] and t[i][1] ko store karne ke liye sirf last row ki hi zarurat hoti hai.
// Isliye hum sirf do variables use karte hain:
// neg → current alternating sum agar element par - sign lagna ho
// pos → current alternating sum agar element par + sign lagna ho
// Bas utna hi kaafi hai.

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        // pos = maximum alternating sum so far 
        //       assuming NEXT element ko + sign ke saath lena allowed hai
        long long pos = 0;

        // neg = maximum alternating sum so far 
        //       assuming NEXT element ko - sign ke saath lena allowed hai
        long long neg = 0;

        // Har element par pos aur neg values update karenge
        for(int x : nums) {

            // Agar current element x ko - sign ke saath lena ho:
            // Do choices:
            // 1️⃣ Take: pos - x  (kyunki pos positive turn tha → ab negative turn)
            // 2️⃣ Skip: neg
            long long new_neg = max(neg, pos - x);

            // Agar current element x ko + sign ke saath lena ho:
            // Do choices:
            // 1️⃣ Take: neg + x  (kyunki neg negative turn tha → ab positive turn)
            // 2️⃣ Skip: pos
            long long new_pos = max(pos, neg + x);

            // Update states
            neg = new_neg;
            pos = new_pos;
        }

        // Final answer: best of both states
        return max(pos, neg);
    }
};


// 🔥 Why does this work? (Ultra-short explanation)

// At every element x:

// | State   | Meaning                                  | Update                              |
// | ------- | ---------------------------------------- | ----------------------------------- |
// | **pos** | Next number ko **positive** lena allowed | max(previous pos, previous neg + x) |
// | **neg** | Next number ko **negative** lena allowed | max(previous neg, previous pos - x) |
