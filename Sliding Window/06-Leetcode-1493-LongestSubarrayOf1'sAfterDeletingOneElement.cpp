class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        // Array ka size
        int n = nums.size();

        // i = left pointer (window ka starting index)
        // j = right pointer (window ka ending index)
        int i = 0, j = 0;

        // flip = window ke andar kitne 0 "delete" / "skip" kiye gaye hain
        // Is question me sirf 1 deletion allowed hai
        int flip = 0;

        // len = current valid window ka length
        int len = 0;

        // maxLen = ab tak ka maximum valid window length
        int maxLen = INT_MIN;

        // Sliding Window tab tak chalayenge jab tak j < n
        while(j < n)
        {
            // Case 1:
            // Agar current element 1 hai
            // to koi issue nahi, window ko expand kar do
            if(nums[j] == 1)
            {
                j++;
            }
            else
            {
                // Case 2:
                // Agar nums[j] == 0
                // aur abhi tak koi deletion use nahi hua (flip < 1)
                // to is 0 ko delete/skip maan ke window expand karo
                if(flip < 1) 
                {
                    j++;
                    flip++;   // ek deletion use ho gayi
                }
                else
                {
                    // Case 3:
                    // nums[j] == 0
                    // aur already ek deletion ho chuki hai
                    // to window invalid ho gayi

                    // IMPORTANT:
                    // -1 isliye kiya kyunki ek element delete karna mandatory hai
                    len = j - i - 1;

                    // maximum length update karo
                    maxLen = max(maxLen, len);

                    // Ab window ko left se shrink karna padega
                    // jab tak nums[i] == 1 hai, tab tak i badhao
                    // kyunki 1 hatane se deletion count change nahi hota
                    while(nums[i] == 1)
                        i++;

                    // Yahan nums[i] == 0 hoga
                    // is 0 ko window se remove kar rahe hain
                    // matlab pehli deletion free ho gayi
                    i++;

                    // Right pointer bhi aage badhao
                    j++;
                }
            }
        }

        // Loop ke baad last window ka answer calculate karna zaroori hai
        len = j - i - 1;
        maxLen = max(maxLen, len);

        // Final maximum length return karo
        return maxLen;
    }
};




🧠 Important Observation:
	•	Is problem me 1 element delete karna mandatory hai
	•	Isliye length nikalte waqt -1 kiya gaya hai
	•	Ye solution effectively:
	•	At most 1 zero allow karta hai
	•	Aur us zero ko delete maan ke answer deta hai


⏱ Complexity:
	•	Time Complexity: O(n)
	•	Space Complexity: O(1)