class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {

        // Mountain array ka peak kabhi bhi
        // index 0 ya last index par nahi hota
        // isliye hum search space 1 se n-2 tak rakhte hain
        int low = 1;
        int high = nums.size() - 2;

        // Binary search
        while(low <= high)
        {
            // Mid index (overflow-safe)
            int mid = low + (high - low) / 2;

            // Ye checks technically redundant hain,
            // kyunki low=1 aur high=n-2 rakha hai
            // phir bhi safety ke liye likhe gaye hain
            if(mid == 0) 
                low = mid + 1;
            else if(mid == nums.size() - 1) 
                high = mid - 1;

            // Case 1:
            // Agar mid apne dono neighbors se bada hai
            // matlab ye hi mountain ka peak hai
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }

            // Case 2:
            // Agar hum increasing slope par hain
            // (left chhota, right bada)
            // to peak right side me hoga
            else if(nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }

            // Case 3:
            // Agar hum decreasing slope par hain
            // to peak left side me hoga
            else 
            {
                high = mid - 1;
            }
        }

        // Loop ke baad:
        // high peak ke index par hoga
        return high;
    }
};



Binary search me hum mid par check karte hain:
	•	mid > left && mid > right → peak mil gaya
	•	mid < right → abhi chadhai chal rahi hai → right jao
	•	mid > right → utarai chal rahi hai → left jao


⏱ Time & Space Complexity
	•	Time Complexity: O(log n)
	•	Space Complexity: O(1)



🎤 Interview Me Kaise Explain Kare

“Since the array is a mountain array, I used binary search.
By comparing mid with its neighbors, I decide whether to go left or right.
This gives an O(log n) solution.”