class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) 
    {

        // 🔹 n = array ka total size
        int n = arr.size();

        // 🔹 ans vector final answer store karega
        // Har sliding window ka first negative integer
        vector<int> ans;

        // 🔹 Queue me hum NEGATIVE elements ke INDEX store karenge
        // Index store karna zaroori hai taaki:
        // 1️⃣ window ke bahar jane wale elements ko easily remove kar saken
        // 2️⃣ current window ka first negative element track kar saken
        queue<int> q;

        // 🔁 Pure array ko left se right traverse kar rahe hain
        for(int i = 0; i < n; i++)
        {
            // 🔹 Step 1:
            // Agar current element negative hai
            // to uska index queue me push kar do
            if(arr[i] < 0)
            {
                q.push(i);
            }

            // 🔹 Step 2:
            // Agar queue ka front element
            // current window se bahar ho chuka hai
            // (i - k) se chhota ya barabar
            // to usko queue se hata do
            if(!q.empty() && q.front() <= i - k)
            {
                q.pop();
            }

            // 🔹 Step 3:
            // Jab pehli complete window ban jati hai
            // i >= k-1 ka matlab window size = k ho chuki hai
            if(i >= k - 1)
            {
                // 🔹 Agar queue empty nahi hai
                // to front index ka element hi
                // current window ka FIRST negative integer hoga
                if(!q.empty())
                {
                    ans.push_back(arr[q.front()]);
                }
                else
                {
                    // 🔹 Agar queue empty hai
                    // matlab current window me koi negative element nahi hai
                    // is case me 0 push kar dete hain
                    ans.push_back(0);
                }
            }
        }

        // 🔹 Final result return kar dete hain
        return ans;
    }
};



🧠 Core Concept (Interview Me Kaise Explain Kare)
	•	Ye problem Sliding Window category ki hai
	•	Window ka size fix hai → k
	•	Har window ke liye:
👉 First negative integer nikalna hai

🔹 Queue ka Role
	•	Queue sirf negative elements ke index store karti hai
	•	Queue ka front hamesha current window ka first negative element hota hai



⏱️ Complexity
	•	Time Complexity: O(n)
	•	Space Complexity: O(k) (worst case queue me k elements ho sakte hain)