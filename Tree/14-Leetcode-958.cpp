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




--------------------------------DFS approach----------------------------------


class Solution {
public:

    // 🔢 Step 1: Total nodes count karne ka function
    // Simple DFS traversal se har node count karenge
    int count(TreeNode* root)
    {
        // 🛑 Base case: agar node NULL hai
        if(root == NULL) 
            return 0;

        // 📦 Current node (1) + left subtree + right subtree
        return 1 + count(root->left) + count(root->right);
    }


    // 🔁 Step 2: DFS with index checking
    // i = current node ka index (heap style)
    // totalNodes = total nodes in tree
    bool dfs(TreeNode* root, int i, int totalNodes)
    {
        // 🛑 Agar node NULL hai
        // NULL hona allowed hai, isliye true return karte hain
        if(root == NULL) 
            return true;

        // ❌ Agar kisi node ka index totalNodes se bada ho gaya
        // matlab beech me gap hai → not complete
        if(i > totalNodes) 
            return false;

        // 🌳 Recursively left aur right subtree check karenge
        // Left child ka index = 2*i
        // Right child ka index = 2*i + 1

        return dfs(root->left, 2*i, totalNodes) &&
               dfs(root->right, 2*i + 1, totalNodes);
    }


    // 🚀 Main function
    bool isCompleteTree(TreeNode* root) {

        // 🔢 Pehle total nodes count karo
        int totalNodes = count(root);

        // 🔎 Ab DFS start karo root index = 1 se
        return dfs(root, 1, totalNodes);
    }
};



⏱ Time Complexity
	1.	count() → O(N)
	2.	dfs() → O(N)

Total → O(N)

📦 Space Complexity

Recursive stack → worst case skewed tree → O(N)