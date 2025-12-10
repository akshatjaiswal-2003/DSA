class Solution {
public:
    int rob(vector<int>& nums) {

        // Edge case: agar sirf 1 house hai, wahi loot lo
        if (nums.size() == 1) 
            return nums[0];

        // prev1 = dp[i-1]  → last house tak ka best answer
        // prev2 = dp[i-2]  → second-last house tak ka best answer
        int prev1 = nums[0];          // dp[0]
        int prev2 = 0;                // dp[-1] = 0 (base case)

        // Har house par rob vs skip ka decision lenge
        for (int i = 1; i < nums.size(); i++) {

            // Option 1 → Rob current house:
            // nums[i] + dp[i-2]  (prev2)
            int rob = nums[i] + prev2;

            // Option 2 → Skip current house:
            // dp[i-1] (prev1)
            int skip = prev1;

            // Best choice for this index
            int curr = max(rob, skip);

            // Update DP rolling variables
            prev2 = prev1;  
            prev1 = curr;
        }

        // Last stored value hi hamara final answer hai
        return prev1;
    }
};
