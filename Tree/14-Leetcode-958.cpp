https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/





class Solution {
public:

    // 🌳 Queue use kar rahe hain Level Order Traversal (BFS) ke liye
    queue<TreeNode*> q;

    bool isCompleteTree(TreeNode* root) {

        // 🔹 Sabse pehle root ko queue me daal do
        q.push(root);

        // 🔹 Ye flag batayega ki kya humne NULL node dekh liya hai
        // Agar NULL mil gaya, uske baad koi bhi non-null node aaya
        // to tree complete nahi hai
        bool past = false;

        // 🔁 Jab tak queue khali nahi hoti
        while(!q.empty())
        {
            // 📦 Front node nikalo
            TreeNode* temp = q.front();
            q.pop();

            // 🛑 Agar NULL node mil gaya
            if(temp == NULL)
            {
                // Iska matlab ab se sab nodes NULL hi hone chahiye
                past = true;
            }
            else
            {
                // ❌ Agar NULL ke baad koi valid node mil gaya
                // to tree complete nahi hai
                if(past == true) return false;

                // 🌱 Left child ko queue me daalo
                q.push(temp->left);

                // 🌱 Right child ko queue me daalo
                q.push(temp->right);
            }
        }

        // Agar kabhi invalid condition nahi mili
        // to tree complete hai
        return true;
    }
};




🧠 Logic Deep Samjho

Step-by-step kaise kaam karta hai:
	1.	Level order traversal karte hain (BFS)
	2.	Jaise hi NULL milta hai → flag set kar dete hain
	3.	Agar NULL ke baad koi non-null node mil gaya:
	•	Matlab gap aa gaya
	•	Complete binary tree rule break
	•	Return false



⏱ Time Complexity:

O(N)
Har node ek baar visit ho raha hai.

📦 Space Complexity:

O(N)
Queue me worst case me ek full level store ho sakta hai.