class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {

        // 🔹 Ye vector final answer store karega
        // Har window ka first negative integer
        vector<int> ans;

        // 🔹 Queue me hum negative elements ke INDEX store karenge
        // Value nahi, index isliye kyunki window ke bahar jane wale
        // elements ko easily remove kar saken
        queue<int> q;

        // 🔁 Pure array ko ek baar left se right traverse karenge
        for(int i = 0; i < arr.size(); i++)
        {
            // 🔹 Agar current element negative hai
            // to uska index queue me daal do
            if(arr[i] < 0)
            {
                q.push(i);
            }

            // 🔹 Window shrink hone ka case:
            // Agar queue ka front element current window se bahar ho chuka hai
            // (i - k) se chhota ya barabar
            // to usko queue se nikal do
            if(!q.empty() && q.front() <= i - k)
            {
                q.pop();
            }

            // 🔹 Jab hum pehli complete window bana lete hain
            // i >= k-1 ka matlab hai window size k ho chuki hai
            if(i >= k - 1)
            {
                // 🔹 Agar queue empty nahi hai
                // to front index ka element hi
                // is window ka first negative integer hoga
                if(!q.empty())
                {
                    ans.push_back(arr[q.front()]);
                }
                else
                {
                    // 🔹 Agar queue empty hai
                    // matlab current window me koi negative element nahi hai
                    // to 0 push kar dete hain
                    ans.push_back(0);
                }
            }
        }

        // 🔹 Final answer return kar dete hain
        return ans;
    }
};




🧠 Core Idea (Interview Me Kaise Samjhayen)
	•	Ye problem Sliding Window category ki hai
	•	Window size = k
	•	Har window ke liye first negative integer chahiye

Why Queue?
	•	Queue hamesha window ke valid negative elements ka record rakhti hai
	•	Front of queue = current window ka first negative number



⏱️ Complexity
	•	Time Complexity: O(n)
	•	Space Complexity: O(k) (worst case queue me k elements)