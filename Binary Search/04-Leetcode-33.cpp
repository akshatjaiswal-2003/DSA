class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // Binary search ke pointers
        int low = 0;
        int high = n - 1;

        // Jab tak search space valid hai
        while(low <= high)
        {
            // Mid index (overflow-safe)
            int mid = low + (high - low) / 2;

            // Case 1:
            // Agar mid par hi target mil gaya
            if(nums[mid] == target) 
                return mid;

            // ================================
            // Case 2:
            // Left half sorted hai
            // (nums[low] <= nums[mid] se pata chalta hai)
            // ================================
            else if(nums[low] <= nums[mid])
            {
                // Check karo target left sorted half me lie karta hai ya nahi
                if(nums[low] <= target && target < nums[mid])
                {
                    // Target left half me hai
                    high = mid - 1;
                }
                else
                {
                    // Target left half me nahi hai
                    // Right half me search karo
                    low = mid + 1;
                }
            }

            // ================================
            // Case 3:
            // Right half sorted hai
            // (nums[mid] <= nums[high] se pata chalta hai)
            // ================================
            else if(nums[mid] <= nums[high])
            {
                // Check karo target right sorted half me lie karta hai ya nahi
                if(nums[mid] < target && target <= nums[high])
                {
                    // Target right half me hai
                    low = mid + 1;
                }
                else
                {
                    // Target right half me nahi hai
                    // Left half me search karo
                    high = mid - 1;
                }
            }
        }

        // Agar poora array search karne ke baad bhi
        // target nahi mila
        return -1;
    }
};





Har step pe:
	•	Ya to left half sorted hota hai
	•	Ya right half sorted hota hai

👉 Hum pehle identify karte hain kaunsa half sorted hai,
👉 phir check karte hain target us sorted half me aata hai ya nahi,
👉 uske according low aur high move karte hain.



⏱ Time & Space Complexity
	•	Time Complexity: O(log n)
	•	Space Complexity: O(1)


🎤 Interview Me Kaise Explain Kare (One-Liner)

“At every step, one half of the rotated array is sorted.
I identify the sorted half and check if the target lies inside it.
Accordingly, I discard the other half using binary search.”
