https://leetcode.com/problems/binary-tree-right-side-view/


class Solution {
public:

    // 🔁 Ye function DFS (preorder style) use karta hai
    // root  -> current node
    // level -> current depth / level of tree (root = level 1)
    // ans   -> answer vector jisme right side view store hoga
    void preorder(TreeNode* root, int level, vector<int> &ans)
    {
        // 🔴 Base case:
        // Agar node NULL hai matlab tree ka end aa gaya
        if(root == NULL) return;

        // ⭐ KEY LOGIC ⭐
        // Agar current level pe pehli baar aa rahe hain
        // to ans.size() < level hoga
        //
        // Example:
        // level = 1, ans.size() = 0  → push
        // level = 2, ans.size() = 1  → push
        //
        // Iska matlab:
        // Har level ka pehla node hi answer me jaayega
        if(ans.size() < level)
            ans.push_back(root->val);

        // 👉 Sabse pehle RIGHT subtree call
        // Kyunki hume RIGHT SIDE VIEW chahiye
        // Pehla visible node right side ka hona chahiye
        preorder(root->right, level + 1, ans);

        // 👉 Baad me LEFT subtree
        preorder(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;   // final answer vector

        // Root se DFS start, level = 1 se
        preorder(root, 1, ans);

        return ans;
    }
};





class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;   // 🟢 Final answer: right side view nodes

        // 🔴 Edge case:
        // Agar tree hi empty hai, to direct empty vector return
        if (!root) return ans;

        // 🟡 Queue banayi for Level Order Traversal (BFS)
        queue<TreeNode*> q;

        // 🌱 Root ko queue me daal diya
        q.push(root);

        // 🔁 Jab tak queue empty nahi hoti, traversal chalu rahega
        while (!q.empty()) {

            // 📏 Current level me kitne nodes hain
            int size = q.size();

            // 🔄 Current level ke saare nodes process honge
            for (int i = 0; i < size; i++) {

                // 🔽 Queue ke front se node nikala
                TreeNode* node = q.front();
                q.pop();

                // ⭐ MAIN LOGIC ⭐
                // Agar ye current level ka LAST node hai
                // (i == size-1)
                // to ye RIGHT SIDE se visible node hoga
                if (i == size - 1)
                    ans.push_back(node->val);

                // 👈 Left child ko queue me daalo (agar exist karta ho)
                if (node->left)
                    q.push(node->left);

                // 👉 Right child ko queue me daalo (agar exist karta ho)
                if (node->right)
                    q.push(node->right);
            }
        }

        // 🟢 Saare levels process ho gaye
        return ans;
    }
};


🧠 Intuition (Simple Words)
	•	Hum Level Order Traversal (BFS) use kar rahe hain
	•	Har level pe:
	•	Nodes ko left se right process karte hain
	•	Last node of that level = Rightmost node