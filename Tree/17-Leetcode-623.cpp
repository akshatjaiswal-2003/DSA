https://leetcode.com/problems/add-one-row-to-tree/description/



class Solution {
public:

    // 🔁 Recursive helper function
    // root  → current node
    // val   → jo value insert karni hai
    // depth → target depth
    // curr  → current depth of traversal
    TreeNode* add(TreeNode* root, int val, int depth, int curr)
    {
        // 🛑 Base Case:
        // Agar node NULL hai to kuch nahi karna
        if(root == NULL) 
            return root;

        // 🎯 Important Condition:
        // Agar current depth == depth - 1
        // Matlab hum un nodes pe aa gaye jinke niche new row insert karni hai
        if(depth - 1 == curr)
        {
            // 📦 Old children ko temporarily store kar lo
            TreeNode* tempL = root->left;
            TreeNode* tempR = root->right;

            // 🌱 Do naye nodes create karo
            TreeNode* newNodeL = new TreeNode(val);
            TreeNode* newNodeR = new TreeNode(val);

            // 🔗 Unhe current node ke left aur right bana do
            root->left = newNodeL;
            root->right = newNodeR;

            // 🔄 Old left child ko new left node ke niche attach karo
            newNodeL->left = tempL;

            // 🔄 Old right child ko new right node ke niche attach karo
            newNodeR->right = tempR;
        }

        // 🔁 Recursively left subtree me jao
        add(root->left, val, depth, curr+1);

        // 🔁 Recursively right subtree me jao
        add(root->right, val, depth, curr+1);

        // ✅ Modified root return karo
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        // ⚠️ Special Case:
        // Agar depth == 1
        // Matlab new node hi new root banega
        if(depth == 1)
        {
            TreeNode* newNode = new TreeNode(val);

            // Old tree ko new root ke left attach karo
            newNode->left = root;

            return newNode;
        }

        // 🚀 Normal case
        int curr = 1;  // Root ki depth 1 hoti hai

        return add(root, val, depth, curr);
    }
};



📊 Complexity Analysis

⏱ Time Complexity

Har node ek baar visit ho raha hai.

👉 O(N)

⸻

📦 Space Complexity

Recursion stack:

Worst case skewed tree → O(N)

Balanced tree → O(log N)