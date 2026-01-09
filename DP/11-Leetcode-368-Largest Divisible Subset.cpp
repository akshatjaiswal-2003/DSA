// ------------------------------------------------------------
// Approach-1 : Brute Force (Same pattern as LIS)
// ------------------------------------------------------------
// Idea:
// Hume nums array se ek aisi subsequence nikalni hai jisme:
//   - Har next element previous element se divisible ho
//   - Subsequence ki length maximum ho
//
// Ye bilkul LIS jaisa hai, bas comparison condition different hai
//
// NOTE:
// Ye approach har possible subsequence try karti hai
// Isliye T.C exponential hai (2^n)
// ------------------------------------------------------------

class Solution {
public:
    
    /*
        generate(...)
        --------------
        idx   -> current index jahan par decision lena hai
        nums  -> sorted input array
        result-> ab tak ka BEST answer (largest divisible subset)
        temp  -> current subsequence jo hum build kar rahe hain
        prev  -> last taken element (divisibility check ke liye)
                -1 ka matlab abhi koi element nahi liya
    */
    void generate(int idx,vector<int>& nums,vector<int>& result,vector<int>& temp,int prev) 
    {

        // ---------------- BASE CASE ----------------
        // Agar array ke end tak pahunch gaye
        if(idx >= nums.size()) 
        {

            // Agar current subsequence (temp)
            // result se zyada badi hai
            // toh result update kar do
            if(temp.size() > result.size()) {
                result = temp;
            }
            return;
        }
        
        // ---------------- TAKE CASE ----------------
        // nums[idx] ko tabhi le sakte hain jab:
        //   1) prev == -1  (pehla element hai)
        //   2) nums[idx] % prev == 0 (divisible condition)
        if(prev == -1 || nums[idx] % prev == 0) 
        {

            // nums[idx] ko current subsequence me add karo
            temp.push_back(nums[idx]);

            // Next index ke liye recursive call
            generate(idx+1, nums, result, temp, nums[idx]);

            // Backtracking:
            // wapas aate waqt last element remove karo
            temp.pop_back();
        }
        
        // ---------------- NOT TAKE CASE ----------------
        // nums[idx] ko skip kar dete hain
        // prev same hi rahega
        generate(idx+1, nums, result, temp, prev);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {

        // Sorting is VERY IMPORTANT
        // Kyunki divisibility check tab meaningful hota hai
        // jab numbers ascending order me hon
        sort(begin(nums), end(nums));
        
        vector<int> result; // final best subset
        vector<int> temp;   // current subsequence
        
        // Start recursion:
        // idx = 0 (starting index)
        // prev = -1 (abhi koi element choose nahi kiya)
        generate(0, nums, result, temp, -1);
        
        return result;
    }
};








// ------------------------------------------------------------
// Approach-2 : Bottom Up DP (Same as LIS) + Path Reconstruction
// ------------------------------------------------------------
// Idea:
// Ye problem bilkul LIS jaisi hai
// Bas difference ye hai ki comparison condition hai:
//      nums[i] % nums[j] == 0
//
// Hume:
// 1) Largest length ka divisible subset chahiye
// 2) Aur us subset ke actual elements bhi print karne hain
//
// Isliye hum DP ke saath "prev index" bhi store karte hain
// ------------------------------------------------------------

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {

        // Step-1: Sort the array
        // Kyunki divisible subset me agar a < b hai
        // toh check sirf nums[i] % nums[j] == 0 se ho jaayega
        sort(begin(nums), end(nums));

        int n = nums.size();

        // ------------------------------------------------
        // t[i] = length of largest divisible subset
        //        ending exactly at index i
        // Initially har element khud me ek subset hai
        // ------------------------------------------------
        vector<int> t(n, 1);

        // ------------------------------------------------
        // prev_idx[i] = previous index of nums[i]
        // jisse hum subset reconstruct kar sake
        // Agar prev_idx[i] = j hai,
        // toh nums[j] -> nums[i] se pehle aaya
        // ------------------------------------------------
        vector<int> prev_idx(n, -1);

        // Ye store karega LIS ka last index
        int last_chosen_index = 0;

        // Maximum subset length
        int maxL = 1;

        // ------------------------------------------------
        // DP Calculation (Same as LIS)
        // ------------------------------------------------
        for(int i = 0; i < n; i++)
        {

            // i se pehle ke saare elements check karenge
            for(int j = 0; j < i; j++)
            {

                // Divisibility condition
                // Agar nums[i] divisible hai nums[j] se
                if(nums[i] % nums[j] == 0)
                {

                    // Check karo kya j ko include karke
                    // subset aur bada ban sakta hai
                    if(t[i] < t[j] + 1)
                    {

                        // Length update
                        t[i] = t[j] + 1;

                        // Path remember karo
                        prev_idx[i] = j;
                    }

                    // Overall maximum length update
                    if(t[i] > maxL)
                    {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        // -----------------------------------------------
        // Subset Reconstruction
        // -----------------------------------------------
        // last_chosen_index se peeche jaate jaayenge
        // prev_idx array ki help se
        vector<int> result;

        while(last_chosen_index >= 0)
        {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        // Result reverse order me hota hai
        // (optional: reverse(result.begin(), result.end()))

        return result;
    }
};