class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {

        // i = left pointer (window ka start)
        // j = right pointer (window ka end)
        int i = 0, j = 0;

        // n = array ka size
        int n = nums.size();

        // sum = current window ka sum
        int sum = 0;

        // ans = minimum length store karega
        // INT_MAX se initialize kiya taaki easily minimum nikal sake
        int ans = INT_MAX;

        // Jab tak right pointer array ke andar hai
        while(j < n)
        {
            // Right pointer ka element window me add kar rahe hain
            sum += nums[j];

            // Jab tak current window ka sum target se bada ya equal hai
            // tab tak window ko shrink karne ki koshish karenge
            while(sum >= target)
            {
                // Current window ka length = j - i + 1
                // Minimum length update kar rahe hain
                ans = min(ans, j - i + 1);

                // Ab window ko left se chhota kar rahe hain
                // i-th element ko sum se hata rahe hain
                sum -= nums[i];

                // Left pointer aage badha diya
                i++;
            }

            // Right pointer ko aage badhao (window expand)
            j++;
        }

        // Agar ans abhi bhi INT_MAX hai
        // matlab koi subarray mila hi nahi jiska sum >= target ho
        if(ans == INT_MAX) return 0;

        // Warna minimum length return karo
        else return ans;
    }
};



🧠 Logic Summary:
	•	Ye Sliding Window (Two Pointers) technique hai
	•	Window expand (j++) jab sum chhota ho
	•	Window shrink (i++) jab sum target se bada/equal ho



⏱️ Complexity
	•	Time Complexity: O(n) ✅
	•	Space Complexity: O(1) ✅