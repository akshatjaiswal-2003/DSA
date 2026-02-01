class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // IMPORTANT EDGE CASE:
        // Agar k <= 1 hai, to koi bhi positive integers ka product
        // kabhi k se chhota nahi ho sakta
        // Isliye directly 0 return kar do
        if(k <= 1) return 0;

        // product = current sliding window ka product
        int product = 1;

        // i = left pointer
        // j = right pointer
        int i = 0, j = 0;

        // len = total valid subarrays ka count
        int len = 0;

        int n = nums.size();

        // Sliding window start
        while(j < n)
        {
            // Step 1:
            // Right pointer ke element ko product me multiply karo
            product *= nums[j];

            // Step 2:
            // Jab tak product >= k hai,
            // tab tak window invalid hai
            // isliye left pointer ko move karo
            while(product >= k)
            {
                // Is moment par:
                // [i, j-1] tak ke sab subarrays already valid the
                // aur j ko include karte hi product bigad gaya

                // j - i batata hai kitne valid subarrays
                // j ko include karne se pehle
                len += j - i;

                // Left element ko product se remove karo
                product /= nums[i];
                i++;
            }

            // Right pointer aage badhao
            j++;
        }

        // Loop ke baad:
        // Agar window abhi bhi valid hai,
        // to bache hue subarrays ko count karna padega
        while(i < n)
        {
            // j = n ho chuka hai
            // isliye har i ke liye (j - i) valid subarrays honge
            len += j - i;

            // Left pointer shrink
            product /= nums[i];
            i++;
        }

        // Final answer
        return len;
    }
};



🧠 CORE INTUITION (Very Important)

Agar window [i...j] ka product < k hai
👉 to is window ke saare subarrays jo j par end hote hain valid hote hain


⏱ Time & Space Complexity
	•	Time Complexity: O(n)
(i aur j dono sirf forward move karte hain)
	•	Space Complexity: O(1)
(extra space use nahi hua)