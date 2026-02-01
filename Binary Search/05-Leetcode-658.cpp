class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();

        // Binary search ka idea yahan thoda different hai:
        // Hum individual element par nahi,
        // balki k-size ke window ke START index par binary search kar rahe hain

        // low = possible starting index of window
        int low = 0;

        // high = last possible starting index
        // kyunki window size k hai,
        // to start index maximum (n - k) tak hi ja sakta hai
        int high = n - k;

        // Binary search on window start index
        while(low < high)
        {
            // Mid start index
            int mid = low + (high - low) / 2;

            /*
                Compare kar rahe hain:
                left side distance  = x - arr[mid]
                right side distance = arr[mid + k] - x

                Idea:
                - Agar left element x se zyada door hai
                - aur right element comparatively zyada close hai
                - to window ko right shift karna chahiye
            */

            if(x - arr[mid] > arr[mid + k] - x)
            {
                // Matlab:
                // left side ka element zyada far hai
                // better window right side me milegi
                low = mid + 1;
            }
            else
            {
                // Matlab:
                // current window ya left side better hai
                high = mid;
            }
        }

        // Final answer:
        // low ab best window ka starting index hai
        // arr[low] se arr[low + k - 1] tak elements return karo
        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};





🧠 CORE IDEA (Simple Hinglish)
	•	Array sorted hai
	•	Hume k closest elements to x chahiye
	•	Closest elements hamesha contiguous window me milte hain
	•	Isliye hum window ke start index par binary search karte hain
    •	Agar left side zyada door hai → window right shift
	•	Agar right side zyada door hai → window left side better



⏱ Time & Space Complexity
	•	Time Complexity: O(log(n-k) + k)
	    •	Binary search on window start
	    •	Copy k elements
	•	Space Complexity: O(k)
        (answer vector)




🎤 Interview Me Kaise Explain Kare (One-Liner)

“Since the array is sorted, the k closest elements will form a contiguous window.
I binary search the starting index of this window by comparing distances.”