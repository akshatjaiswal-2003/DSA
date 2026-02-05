https://www.geeksforgeeks.org/problems/rotation4723/1



class Solution {
  public:
    int findKRotation(vector<int> &arr) {

        /*
            Idea:
            -----
            Rotated sorted array mein
            jo sabse CHHOTA element hota hai,
            wahi rotation count hota hai (uska index).

            Example:
            [4,5,6,7,0,1,2]
             ↑ ↑ ↑ ↑
             rotations = index of 0 = 4
        */

        int low = 0;
        int high = arr.size() - 1;

        // Binary search tab tak chalayenge
        // jab tak search space ek element par na aa jaaye
        while (low < high)
        {
            // Mid nikal rahe hain (overflow safe)
            int mid = low + (high - low) / 2;

            /*
                Comparison Logic:
                -----------------
                arr[mid] vs arr[high]

                Case 1:
                arr[mid] < arr[high]
                → Right part sorted hai
                → Minimum element LEFT side (mid included) mein hoga
                → high = mid

                Case 2:
                arr[mid] > arr[high]
                → Left part sorted hai
                → Minimum element RIGHT side mein hoga
                → low = mid + 1
            */

            if (arr[mid] < arr[high])
            {
                // Minimum element mid ya uske LEFT mein hai
                high = mid;
            }
            else
            {
                // Minimum element mid ke RIGHT mein hai
                low = mid + 1;
            }
        }

        /*
            Jab low == high ho jaata hai,
            wahi index minimum element ka hota hai
            aur wahi number of rotations hota hai
        */
        return high;   // ya return low (dono same honge)
    }
};



🔑 Key Takeaways (Interview Ready)
	•	Rotation count = index of minimum element
	•	Ye binary search O(log n) mein kaam karta hai
	•	Space complexity: O(1)
	•	low < high use karna important hai (infinite loop avoid karne ke liye)
