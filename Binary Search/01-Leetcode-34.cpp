class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        // Binary search ke liye low & high
        int low = 0;
        int high = nums.size() - 1;

        // flag batayega target mila ya nahi
        bool flag = false;

        // Result vector:
        // v[0] = first occurrence
        // v[1] = last occurrence
        vector<int> v;

        // ============================
        // PART 1: FIRST OCCURRENCE
        // ============================
        while(low <= high)
        {
            // Mid calculation (overflow safe)
            int mid = low + (high - low) / 2;

            // Agar mid par target mil gaya
            if(nums[mid] == target)
            {
                flag = true;   // target present hai

                // Agar left side me bhi same element hai
                // matlab ye first occurrence nahi hai
                if(mid != 0 && nums[mid - 1] == nums[mid])
                {
                    // left side me aur search karo
                    high = mid;
                }
                else
                {
                    // Ye first occurrence hai
                    v.push_back(mid);
                    break;
                }
            }
            // Agar mid ka element target se chhota hai
            // to right half me jao
            else if(nums[mid] < target) 
                low = mid + 1;

            // Agar mid ka element target se bada hai
            // to left half me jao
            else 
                high = mid - 1;
        }

        // ============================
        // PART 2: LAST OCCURRENCE
        // ============================

        // Dubara pointers reset
        low = 0;
        high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // Agar mid par target mil gaya
            if(nums[mid] == target)
            {
                // Agar right side me bhi same element hai
                // matlab ye last occurrence nahi hai
                if(mid != nums.size() - 1 && nums[mid] == nums[mid + 1])
                {
                    // right side me aur search karo
                    low = mid + 1;
                }
                else
                {
                    // Ye last occurrence hai
                    v.push_back(mid);
                    break;
                }
            }
            // Agar mid ka element target se chhota hai
            else if(nums[mid] < target) 
                low = mid + 1;

            // Agar mid ka element target se bada hai
            else 
                high = mid - 1;
        }

        // Agar target kahin bhi nahi mila
        if(flag == false)
        {
            return {-1, -1};
        }
        // Warna first & last index return karo
        else 
            return v;
    }
};



🧠 CORE IDEA (Simple Words)
	•	Array sorted hai
	•	Isliye binary search use kar rahe hain
	•	Do alag binary search:
	    1.	First occurrence nikalne ke liye (left side shrink)
	    2.	Last occurrence nikalne ke liye (right side shrink)


⏱ Time & Space Complexity
	•	Time Complexity: O(log n)
    (2 binary searches)
	•	Space Complexity: O(1)
    (result vector ke alawa koi extra space nahi)
