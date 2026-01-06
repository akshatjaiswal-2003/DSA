//Approach-1 (Recursion + Memoization)
class Solution {
public:
    int t[101]; // DP array (memo table) - har index ka best answer store karta hai

    // Recursion function: i = current index, n = last allowed index
    int solve(vector<int>& nums, int i, int n) 
    {
        
        // BASE CASE: Agar index last allowed index se aage chala gaya,
        // to kuch bhi rob nahi kar sakte → return 0
        if(i > n) return 0;
        
        // Agar iss index ka answer pehle se calculated hai,
        // to directly memo table se return kar do
        if(t[i] != -1) return t[i];
        
        // OPTION-1: Take/Rob the current house (nums[i])
        // Agar isko rob karenge to next hum i+2 wale house par hi ja sakte
        int take = nums[i] + solve(nums, i+2, n);

        // OPTION-2: Skip the current house
        // Agar skip karenge to next hum i+1 wale adjacent house par jayenge
        int skip = solve(nums, i+1, n);
        
        // Dono me se maximum store karo (ye hi dp/memo table ka value hai)
        return t[i] = max(take, skip);
    }
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        
        // Special case: Agar sirf 1 house hai, usi ko rob karo
        if(n == 1) return nums[0];
        
        // Agar 2 houses hain, to dono adjacent hain (circular nahi samjho)
        if(n == 2) return max(nums[0], nums[1]);
        
        // ---------------------------------------------
        // IMPORTANT: House Robber II is circular.
        // Matlab first aur last house connected hain.
        // Toh humare paas 2 cases banenge:
        //
        // Case 1: 0th house ko rob karein → phir last house (n-1) rob nahi kar sakte
        //         Range = 0 to n-2
        //
        // Case 2: 1st house ko rob karein → phir 0th house rob nahi kar sakte
        //         Range = 1 to n-1
        // ---------------------------------------------

        memset(t, -1, sizeof(t)); // DP array ko reset karo
        int take_0th_index_house = solve(nums, 0, n-2); 
        // Yaha hum 0th house rob karke last house ko avoid kar rahe hain

        memset(t, -1, sizeof(t)); // DP array ko dubara reset karo (fresh run)
        int take_1st_index_house = solve(nums, 1, n-1); 
        // Yaha hum 1st house se rob start kar rahe hain (0th ko skip karke)

        // Dono possible answers me se maximum return karo
        return max(take_0th_index_house, take_1st_index_house);
    }
};



//Approach-2 (Bottom-Up DP similar to House Robber-I but with 2 cases)
// -------------------------------------------------------------
// Kyun 2 cases? (IMPORTANT)
// Because House Robber-II me houses CIRCULAR hain.
// Matlab: 0th house and (n-1)th house adjacent hain,
// isliye dono ko ek saath rob nahi kar sakte.
//
// • Case-1 -> Pehla house lo → last house mat lo  (0 ... n-2)
// • Case-2 -> Pehla house mat lo → second house se start karo (1 ... n-1)
//
// Dono cases ka answer alag-alag compute karke maximum return karenge.
// -------------------------------------------------------------

class Solution {
public:
    int n;
    
    int rob(vector<int>& nums) {
        
        n = nums.size();
        
        // Base case: Agar sirf 1 house hai, usko hi rob karo
        if(n == 1)
            return nums[0];
        
        // Bottom-up DP table
        // t[i] = first 'i' houses se maximum paisa kitna rob kar sakte hain
        vector<int> t(n+1, 0);
        
        int result1 = 0;  // Case 1 ka answer
        int result2 = 0;  // Case 2 ka answer
        
        // -------------------------------------------------------------
        // CASE - 1 :
        // Hum 0th house ko rob consider karte hain,
        // isliye last house (n-1) ko avoid karna padega.
        //
        // Effectively solve range: nums[0 ... n-2]
        // DP indexing: i = house count (1-based DP)
        // nums indexing: i-1 (0-based)
        // -------------------------------------------------------------
        
        t[0] = 0;  // 0 houses -> 0 paisa
        
        for(int i = 1; i <= n-1; i++) {  
            // 'i' means first 'i' houses from nums[0 ... i-1]
            
            // Option 1: Skip current house → t[i-1]
            // Option 2: Take current house (nums[i-1]) → t[i-2] + nums[i-1]
            t[i] = max(
                t[i-1],
                nums[i-1] + ((i-2 >= 0) ? t[i-2] : 0)
            );
        }
        
        // Case-1 ka result = t[n-1], kyunki hum last house (n-1) ko use nahi kar rahe
        result1 = t[n-1];
        
        
        // -------------------------------------------------------------
        // CASE - 2 :
        // Hum 0th house ko bilkul consider hi nahi karte.
        // Hum 1st house se rob start karte hain → isliye DP differently set hoga.
        //
        // Effective range: nums[1 ... n-1]
        // DP indexing trick:
        //   t[0] = 0 (no houses)
        //   t[1] = 0 (first house skip kar diya)
        //
        // Ab nums[i-1] actual house ko map karega
        // -------------------------------------------------------------
        
        t.assign(n+1, 0);   // DP ko reset (clear) karke size n+1 set kar diya
        
        t[0] = 0; // no houses
        t[1] = 0; // hum first house (nums[0]) ko intentionally skip kar rahe
        
        for(int i = 2; i <= n; i++) {
            // Now DP maps:
            // t[2] -> nums[1]
            // t[3] -> nums[2]
            // ...
            // t[n] -> nums[n-1]
            
            t[i] = max(
                t[i-1],
                nums[i-1] + t[i-2]
            );
        }
        
        // Case-2 ka final answer = t[n]
        result2 = t[n];
        
        
        // -------------------------------------------------------------
        // Final Answer:
        // Circular constraint ke wajah se cases alag the,
        // par ab unka maximum hi final answer hoga.
        // -------------------------------------------------------------
        
        return max(result1, result2);
    }
};




// Approach-3 (Bottom-Up DP converted to constant O(1) space)
// ----------------------------------------------------------
// Yaha hum pura DP array use nahi kar rahe. 
// Sirf 2 variables (prev, prevPrev) ka use karke House Robber I ka 
// logic apply kar rahe hain.
//
// House Robber II circular hai, isliye 2 ranges ko solve karna zaroori hai:
//   Case 1: 0 se n-2 (first house lo, last house skip)
//   Case 2: 1 se n-1 (first house skip, last house consider)
//
// Har case ko solve() function se solve karenge jo O(1) space me House Robber I karta hai.
// ----------------------------------------------------------

class Solution {
public:

    // ----------------------------------------------------------
    // solve() → House Robber I ka O(1) space bottom-up DP version
    //
    // nums[l ... r] range ke liye best possible robbery return karta hai.
    //
    // prevPrev → DP[i-2] ka answer (2 step peeche ka best)
    // prev     → DP[i-1] ka answer (1 step peeche ka best)
    //
    // Har index par sirf 2 choices:
    //   1) skip → prev (last house ka best)
    //   2) take → nums[i] + prevPrev
    //
    // phir max(skip, take) ko next iteration ka prev banate hain.
    // ----------------------------------------------------------
    int solve(vector<int>& nums, int l, int r) {
        
        int prevPrev = 0;  // dp[i-2]
        int prev = 0;      // dp[i-1]
        
        // Pure range ko iterate karte hain
        for(int i = l; i <= r; i++) {
            
            // OPTION 1: current house skip (same as dp[i-1])
            int skip = prev;

            // OPTION 2: current house lo (nums[i]) + dp[i-2]
            int take = nums[i] + prevPrev;
            
            // current best = max(skip, take)
            int temp = max(skip, take);
            
            // DP update:
            // Move prevPrev → previous prev
            prevPrev = prev;

            // prev becomes current best
            prev = temp;
        }
        
        // prev contains best answer for range [l ... r]
        return prev;
    }
    
    int rob(vector<int>& nums) {

        int n = nums.size();

        // Special cases (circular but small length)
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        // ----------------------------------------------------------
        // Case-1:
        // 0th house ko consider karna hai → last house rob nahi kar sakte
        // Range: 0 se n-2
        // ----------------------------------------------------------
        int take_first_house = solve(nums, 0, n-2);
        
        // ----------------------------------------------------------
        // Case-2:
        // 0th house skip karna hai → 1st se start karenge
        // Range: 1 se n-1
        // ----------------------------------------------------------
        int skip_first_house = solve(nums, 1, n-1);
        
        // Dono me se maximum hi final answer hoga
        return max(take_first_house, skip_first_house);
    }
};
