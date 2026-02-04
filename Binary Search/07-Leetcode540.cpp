class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // Binary Search ke liye low aur high pointers
        int low = 0;
        int high = nums.size() - 1;

        // Jab tak search space ek element par reduce nahi ho jaata
        while (low < high)
        {
            // mid calculate kar rahe hain (overflow safe way)
            int mid = low + (high - low) / 2;

            /*
                Idea:
                -----
                Array sorted hai
                Har element 2 baar aata hai
                Sirf ek element single hai

                Observation:
                - Single element ke LEFT side par pairs ka pattern normal hota hai
                  (even index par first, odd index par second)
                - Single element ke RIGHT side par pattern shift ho jaata hai

                Hum mid ke RIGHT side ki length check karte hain:
                (high - mid)

                Agar length EVEN hai:
                → single element RIGHT side mein ho sakta hai
                Agar length ODD hai:
                → single element LEFT side mein ho sakta hai
            */

            bool isEven;

            // Check kar rahe hain ki mid ke right side ka size even hai ya odd
            if ((high - mid) % 2 == 0)
                isEven = true;
            else
                isEven = false;

            /*
                Ab comparison:
                ----------------
                Case 1: nums[mid] == nums[mid + 1]
                → matlab mid ek pair ka FIRST element ho sakta hai
            */
            if (nums[mid] == nums[mid + 1])
            {
                /*
                    Agar right side EVEN hai:
                    → single element RIGHT side mein hoga
                    → low ko mid + 1 par shift kar do
                */
                if (isEven)
                    low = mid + 1;
                /*
                    Agar right side ODD hai:
                    → single element LEFT side mein hoga
                    → high ko mid - 1 par shift kar do
                */
                else
                    high = mid - 1;
            }
            else
            {
                /*
                    Case 2: nums[mid] != nums[mid + 1]
                    → matlab mid pair ka SECOND element ho sakta hai
                    ya mid hi single element ho sakta hai
                */

                /*
                    Agar right side EVEN hai:
                    → single element LEFT side mein ho sakta hai
                    → high ko mid par le aao
                */
                if (isEven)
                    high = mid;
                /*
                    Agar right side ODD hai:
                    → single element RIGHT side mein hoga
                    → low ko mid + 1 par le jao
                */
                else
                    low = mid + 1;
            }
        }

        /*
            Jab low == high ho jaata hai,
            wahi index single non-duplicate element ka hota hai
        */
        return nums[low];
    }
};



🔥 Important Notes (Interview Gold)
	•	Time Complexity: O(log n)
	•	Space Complexity: O(1)
	•	Sorted array + pairs → Binary Search perfect use case
	•	low < high use karna important hai (infinite loop se bachne ke liye)

