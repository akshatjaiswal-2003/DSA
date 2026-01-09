https://www.geeksforgeeks.org/problems/box-stacking/1


class Solution {
public:

    // dp[i] = Maximum height of stack where box[i] is at the TOP
    int dp[1001];

    // =====================================================
    // 🔹 Recursive + Memo function
    // =====================================================
    // idx → current box ko top maan ke max height nikalna
    // box → all rotated boxes list
    int fun(int idx, vector<vector<int>>& box)
    {
        // Agar pehle se calculate ho chuka hai
        if (dp[idx] != -1) return dp[idx];

        // Minimum height:
        // Agar koi box niche na lage
        // toh sirf current box ki height
        int ans = box[idx][2];  // height of current box

        // Ab sab boxes check karo jo
        // current box ke niche aa sakte hain
        for (int j = 0; j < idx; j++)
        {
            // Condition:
            // niche wala box base me strictly chhota hona chahiye
            if (box[j][0] < box[idx][0] && box[j][1] < box[idx][1])
            {
                // Option: current box + niche wale stack ki height
                ans = max(ans, box[idx][2] + fun(j, box));
            }
        }

        // Memoization
        return dp[idx] = ans;
    }

    // =====================================================
    // 🔹 Main Function
    // =====================================================
    int maxHeight(vector<int> &height,vector<int> &width,vector<int> &length) 
    {

        int n = height.size();
        vector<vector<int>> box;

        // =====================================================
        // 🔹 Step 1: Generate all rotations
        // =====================================================

        // Har box ke 3 unique rotations hote hain
        // (height fix, base change)

        // Base ko hum hamesha:
        // max(base1, base2), min(base1, base2)
        // me store karte hain
        // taaki comparison easy ho
        for (int i = 0; i < n; i++)
        {
            box.push_back({max(height[i], width[i]),min(height[i], width[i]),length[i]});

            box.push_back({max(width[i], length[i]),min(width[i], length[i]),height[i]});

            box.push_back({max(height[i], length[i]),min(height[i], length[i]),width[i]});
        }

        // =====================================================
        // 🔹 Step 2: Sort boxes
        // =====================================================

        // Sorting by base dimensions
        // taaki DP LIS-style kaam kare
        sort(box.begin(), box.end());

        // DP array initialize
        memset(dp, -1, sizeof(dp));

        // =====================================================
        // 🔹 Step 3: Har box ko top maan ke answer nikalo
        // =====================================================
        int ans = 0;
        for (int i = 0; i < box.size(); i++)
        {
            ans = max(ans, fun(i, box));
        }

        return ans;
    }
};



🧠 DP + LIS CONNECTION

| LIS                | Box Stacking                  |
| ------------------ | ----------------------------- |
| Increasing numbers | Increasing base dimensions    |
| Length count       | Height sum                    |
| dp[i]              | dp[i] = max height till box i |




🎯 TIME & SPACE COMPLEXITY

Rotations = 3N
Time: O(N²)
Space: O(N)



🗣️ INTERVIEW ONE-LINER

“This is a variation of LIS where each box rotation is treated as an element and 
DP is used to find the maximum stack height with strict base constraints.”



------------------------------------------------------------------------------------------------------------4

💻 BOTTOM-UP CODE

class Solution {
public:
    int maxHeight(vector<int> &height,vector<int> &width,vector<int> &length) 
    {

        int n = height.size();
        vector<vector<int>> box;

        // =====================================================
        // 🔹 STEP 1: Generate all rotations
        // =====================================================

        // Har box ke 3 valid rotations
        // Base ko always (max, min) me store karte hain
        // taaki comparison consistent rahe

        for (int i = 0; i < n; i++) 
        {

            // Rotation 1
            box.push_back({max(height[i], width[i]),min(height[i], width[i]),length[i]});

            // Rotation 2
            box.push_back({max(width[i], length[i]),min(width[i], length[i]),height[i]});

            // Rotation 3
            box.push_back({max(height[i], length[i]),min(height[i], length[i]),width[i]});
        }

        // =====================================================
        // 🔹 STEP 2: Sort boxes by base dimensions
        // =====================================================

        // Sorting helps in LIS-style DP
        // Smaller base pehle, bigger baad me

        sort(box.begin(), box.end());

        int m = box.size();

        // =====================================================
        // 🔹 STEP 3: DP array initialization
        // =====================================================

        // dp[i] = box[i] ki height
        // (minimum height = khud ka height)

        vector<int> dp(m);

        for (int i = 0; i < m; i++) 
        {
            dp[i] = box[i][2];  // height
        }

        // =====================================================
        // 🔹 STEP 4: LIS-style DP calculation
        // =====================================================

        // For every box i (top box)
        // check all boxes j < i
        // jo niche aa sakte hain

        for (int i = 0; i < m; i++) 
        {

            for (int j = 0; j < i; j++) 
            {

                // Agar box[j] ko box[i] ke niche rakh sakte hain
                if (box[j][0] < box[i][0] &&box[j][1] < box[i][1]) 
                {

                    // Maximum height update:
                    // current box height + niche wale stack
                    dp[i] = max(dp[i], box[i][2] + dp[j]);
                }
            }
        }

        // =====================================================
        // 🔹 STEP 5: Final Answer
        // =====================================================

        // dp array ka maximum value hi answer hai

        int ans = 0;
        for (int i = 0; i < m; i++) 
        {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};


🎯 INTERVIEW ONE-LINER

“This is a bottom-up dynamic programming solution similar to LIS, where dp[i] represents 
the maximum stack height with the i-th box as the top.”