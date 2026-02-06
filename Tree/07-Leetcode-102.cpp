https://leetcode.com/problems/binary-tree-level-order-traversal/


class Solution {
public:

    // 🔴 Ye function binary tree ki height (max depth) nikalta hai
    // Height ka matlab:
    // root se lekar sabse deepest leaf tak kitne levels hain
    int height(TreeNode* root)
    {
        // Base case:
        // Agar root NULL ho gaya
        // to height = 0
        if(root == NULL) 
            return 0;

        // Left aur right subtree ki height nikalo
        // aur maximum wali lo
        // +1 isliye kyunki current node bhi count hota hai
        return 1 + max(height(root->left), height(root->right));
    }

    // 🔴 Ye function tree ke ek specific level ke nodes collect karta hai
    // curr  -> current level (starting from 1)
    // level -> jis level ke nodes chahiye
    // ans   -> us level ke node values store karne ke liye
    void nthLevel(TreeNode* root, int curr, int level, vector<int> &ans)
    {
        // Agar node NULL ho gayi
        // to aage traverse karne ka fayda nahi
        if(root == NULL) 
            return;

        // Agar current level == required level
        // to current node ka value answer mein daal do
        if(curr == level)
        {
            ans.push_back(root->val);
            return;
        }

        // 🔽 Agar abhi required level tak nahi pahuche
        // to left aur right subtree mein jao
        nthLevel(root->left, curr + 1, level, ans);
        nthLevel(root->right, curr + 1, level, ans);
    }

    // 🔴 Ye helper function poora level order traversal banata hai
    void helper(TreeNode* root, vector<vector<int>> &finalAns)
    {
        // 🔽 Sabse pehle tree ki total height nikali
        int n = height(root);

        // 🔽 Har level ke liye alag-alag traversal
        for(int i = 1; i <= n; i++)
        {
            vector<int> ans;

            // i-th level ke nodes nikale
            nthLevel(root, 1, i, ans);

            // Us level ke nodes ko final answer mein add kar diya
            finalAns.push_back(ans);
        }
    }

    // 🔴 Main function jo LeetCode call karta hai
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> finalAns;

        // Helper function se poora kaam karwa liya
        helper(root, finalAns);

        return finalAns;
    }
};


⏱️ Time & Space Complexity (Important for Interview)

❌ Time Complexity
	•	height() → O(n)
	•	nthLevel() → worst case O(n) for each level
	•	Total levels = height ≈ n (skewed tree)

👉 Overall TC = O(n²) ❌

✅ Space Complexity
	•	Recursive stack → O(h)
(h = height of tree)



--------------------------Optimal / best approach------------------------------

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> finalAns;

        // 🔴 Edge case: agar tree hi empty hai
        if(root == NULL) return finalAns;

        // ✅ Queue use karenge BFS (Breadth First Search) ke liye
        queue<TreeNode*> q;

        // Sabse pehle root ko queue me daal diya
        q.push(root);

        // 🔁 Jab tak queue empty nahi hoti
        while(!q.empty())
        {
            // 🔢 Queue ke andar iss time jitne nodes hain
            // wo ek hi level ke nodes honge
            int size = q.size();

            vector<int> level;  // current level ke nodes store karne ke liye

            // 🔂 Current level ke saare nodes process karenge
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                // 🔹 Node ki value current level vector me add
                level.push_back(curr->val);

                // 👉 Agar left child exist karta hai to queue me push
                if(curr->left != NULL)
                    q.push(curr->left);

                // 👉 Agar right child exist karta hai to queue me push
                if(curr->right != NULL)
                    q.push(curr->right);
            }

            // ✅ Ek level complete hone ke baad usko final answer me add
            finalAns.push_back(level);
        }

        return finalAns;
    }
};



🔥 Why this is OPTIMAL?

⏱ Time Complexity
	•	O(N)
👉 Har node sirf ek baar queue me aata hai aur process hota hai

💾 Space Complexity
	•	O(N) (worst case)
👉 Queue + answer vector