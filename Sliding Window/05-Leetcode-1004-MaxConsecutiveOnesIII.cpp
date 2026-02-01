class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // i = left pointer (window ka start)
        // j = right pointer (window ka end)
        int i = 0, j = 0;

        // flip = current window me kitne 0 ko 1 banaya (flip kiya)
        int flip = 0;

        // n = array ka size
        int n = nums.size();

        // maxLen = ab tak ka maximum valid window length
        int maxLen = INT_MIN;

        // len = temporary variable window length store karne ke liye
        int len = 0;

        // Jab tak right pointer array ke andar hai
        while(j < n)
        {
            // Case 1:
            // Agar current element 1 hai
            // to bina kisi problem ke window expand kar sakte hain
            if(nums[j] == 1)
                j++;

            // Case 2:
            // Agar current element 0 hai
            // aur abhi flips available hain (flip < k)
            // to is 0 ko flip karke window expand kar do
            else if(flip < k)
            {
                j++;
                flip++;   // ek flip use ho gaya
            }

            // Case 3:
            // Agar current element 0 hai
            // aur flips already k ho chuke hain
            // matlab window ab invalid ho gayi
            else if(flip >= k)
            {
                // Abhi tak ki valid window ka length calculate karo
                len = j - i;
                maxLen = max(maxLen, len);

                // Window ko left se shrink karo
                // jab tak nums[i] == 1 hai, tab tak i badhao
                // kyunki 1 hataane se flip count change nahi hota
                while(nums[i] == 1)
                    i++;

                // Yahan nums[i] == 0 hoga
                // is 0 ko window se hata rahe hain
                // matlab ek flip free ho gaya
                i++;

                // Right pointer bhi aage badhao
                j++;
            }
        }

        // Loop ke baad last window ka length check karna zaroori hai
        len = j - i;
        maxLen = max(maxLen, len);

        // Maximum valid window length return karo
        return maxLen;
    }
};





🧠 Logic Breakdown (Short & Clear):
	•	Ye Sliding Window approach hai
	•	Window me at most k zeroes allow hain
	•	Jab zero zyada ho jaate hain → window shrink
	•	Har valid window ka length update




⏱ Complexity:
	•	Time: O(n)
	•	Space: O(1)



