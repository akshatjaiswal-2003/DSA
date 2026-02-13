https://leetcode.com/problems/count-complete-tree-nodes/description/



class Solution {
public:

    // 🔍 Ye function leftmost path ki height nikalta hai
    // Matlab root se continuously left jaate rahenge
    int getLeftHeight(TreeNode* root)
    {
        // 🛑 Agar NULL hai to height 0
        if(root == NULL) 
            return 0;

        // 🔁 1 count karo (current node)
        // + left subtree ki height
        return 1 + getLeftHeight(root->left);
    }

    // 🔍 Ye function rightmost path ki height nikalta hai
    // Matlab root se continuously right jaate rahenge
    int getRightHeight(TreeNode* root)
    {
        // 🛑 Agar NULL hai to height 0
        if(root == NULL) 
            return 0;

        // 🔁 1 count karo (current node)
        // + right subtree ki height
        return 1 + getRightHeight(root->right);
    }

    int countNodes(TreeNode* root) {

        // 🛑 Base Case:
        // Agar tree empty hai
        if(root == NULL) 
            return 0;

        // 📏 Leftmost height nikal lo
        int lh = getLeftHeight(root);

        // 📏 Rightmost height nikal lo
        int rh = getRightHeight(root);

        // 🎯 Agar dono equal hain
        // Matlab tree PERFECT hai
        if(lh == rh)
        {
            // Formula use karo:
            // 2^h - 1
            // Kyunki perfect binary tree me total nodes fix hote hain
            return (pow(2, lh) - 1);
        }

        // ❗ Agar equal nahi hain
        // Matlab tree complete hai but perfect nahi
        // To recursively left aur right subtree count karo
        return countNodes(root->left) 
             + countNodes(root->right) 
             + 1;  // +1 current node ke liye
    }
};



📊 Complexity Analysis (Very Important)

⏱ Time Complexity

Worst case:

Har recursive call me height calculate kar rahe hain
Height calculation = O(log N)

Recursive calls ≈ O(log N)

So total:

👉 O(log² N)