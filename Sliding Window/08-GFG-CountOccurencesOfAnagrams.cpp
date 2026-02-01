// User function template for C++
class Solution {
  public:

    // Helper function:
    // Ye function check karta hai ki
    // counter array ke saare elements zero hain ya nahi
    // Agar saare zero hain => pattern ka exact anagram mila
    bool allZero(vector<int> &counter)
    {
        // Har character ka count check karo
        for(auto &i : counter)
        {
            // Agar kisi bhi character ka count non-zero hua
            // matlab pattern aur window match nahi kar rahe
            if(i != 0) return false;
        }
        // Saare zero => perfect anagram
        return true;
    }

    int search(string &pat, string &txt) {
        // txt ki length
        int n = txt.size();

        // counter array:
        // 26 size ka array, har lowercase letter ke liye
        // ye track karega pat aur current window ka difference
        vector<int> counter(26,0);

        // pat ki length = window size
        int k = pat.size();

        // Step 1:
        // Pattern ke characters ka frequency count bhar do
        for(int i = 0; i < k; i++)
        {
            counter[pat[i] - 'a']++;
        }

        // Sliding window pointers
        int i = 0;   // left pointer
        int j = 0;   // right pointer

        // Answer counter (kitne anagrams mile)
        int ans = 0;

        // Step 2:
        // Sliding window on txt
        while(j < n)
        {
            // Right pointer ka character include kar rahe hain
            // Isliye uska count decrease karo
            counter[txt[j] - 'a']--;

            // Jab window ka size pattern ke barabar ho jaye
            if(j - i + 1 == k)
            {
                // Check karo ki window anagram hai ya nahi
                if(allZero(counter))
                {
                    // Agar haan, answer increment
                    ans++;
                }

                // Ab window ko slide karna hai
                // Left pointer ke character ko bahar nikal rahe hain
                // Isliye uska count wapas increase karo
                counter[txt[i] - 'a']++;

                // Left pointer aage badhao
                i++;
            }

            // Right pointer aage badhao
            j++;
        }

        // Total anagrams count return
        return ans;
    }
};



🧠 CORE LOGIC (Interview Explanation)

👉 Idea:
	•	Pattern ka frequency count banao
	•	Text par fixed-size sliding window (size = pat.length) chalao
	•	Har window ke liye:
	    •	Right char ka count --
	    •	Left char nikalte waqt count ++
	•	Agar counter array poora zero ho gaya
        👉 matlab window ek anagram hai



⏱ Time & Space Complexity
	•	Time Complexity: O(n * 26)
        (26 constant hai, practically O(n))
	•	Space Complexity: O(26) → O(1)