https://leetcode.com/problems/invert-binary-tree/



class Solution {
public:

    // Ye helper function har node par jaakar
    // uske left aur right child ko swap karta hai
    void helper(TreeNode* root)
    {
        // 🔴 Base case:
        // Agar current node NULL hai
        // to kuch karne ki zarurat nahi
        if(root == NULL) 
            return;

        // 🔁 Step 1:
        // Left aur Right child ko swap kar rahe hain
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 🔽 Step 2:
        // Ab recursively left subtree invert karo
        // (jo pehle right subtree tha)
        helper(root->left);

        // 🔽 Step 3:
        // Ab recursively right subtree invert karo
        // (jo pehle left subtree tha)
        helper(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {

        // Helper function call kar ke
        // poore tree ko invert kar do
        helper(root);

        // Inverted tree ka root return
        return root;
    }
};


🧠 Intuition (Simple Hinglish)
	•	Har node par:
	•	Left child ↔ Right child swap
	•	Phir:
	•	Left subtree ko invert karo
	•	Right subtree ko invert karo

👉 Ye DFS (Depth First Search) traversal hai
👉 Post / Pre order dono tarike se kaam karta hai



Time Complexity  - O(n)
Space Complexity - O(h)


🎤 Interview Explanation (Perfect Answer)

“We recursively traverse the tree.
At each node, we swap its left and right children.
Then we recursively invert the left and right subtrees.
This results in a complete mirror of the original tree.
Time complexity is O(n) and space complexity is O(h).”