class Solution {
public:
    int mySqrt(int x) {

        // low = search space ka start
        // high = search space ka end
        // Square root hamesha 0 se x ke beech hi hota hai
        int low = 0;
        int high = x;

        // Binary search loop
        while(low <= high)
        {
            // mid nikal rahe hain (overflow-safe formula)
            // long long isliye use kiya kyunki
            // mid*mid int range se bahar ja sakta hai
            long long m = low + (high - low) / 2;

            // Case 1:
            // Agar mid ka square exactly x ke barabar ho
            if(m * m == x)
            {
                // Perfect square mil gaya
                return m;
            }
            // Case 2:
            // Agar mid ka square x se chhota hai
            // matlab answer mid se bada hoga
            else if(m * m < x)
            {
                // Right half me search karo
                low = m + 1;
            }
            // Case 3:
            // Agar mid ka square x se bada hai
            // matlab answer mid se chhota hoga
            else // (m * m > x)
            {
                // Left half me search karo
                high = m - 1;
            }
        }

        // Loop ke bahar aane ka matlab:
        // low > high ho gaya
        // high wo largest value hai jiska square <= x tha
        // Isi ko integer square root kehte hain
        return high;
    }
};



🧠 CORE IDEA (Simple Explanation)
	•	Hume integer part of √x chahiye
	•	Array nahi hai, lekin search space sorted hai:

        0, 1, 2, 3, ..., x
	•	Isliye Binary Search apply karte hain
	•	Perfect square mil jaaye → return
	•	Nahi mile → jo sabse bada number ho jiska square ≤ x, wahi answer



⏱ Time & Space Complexity
	•	Time Complexity: O(log x)
	•	Space Complexity: O(1)