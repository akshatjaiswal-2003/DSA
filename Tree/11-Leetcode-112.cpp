https://leetcode.com/problems/path-sum/description/




class Solution {
public:

    // 🔁 helper function ka kaam:
    // Ye check karta hai ki
    // root se leaf tak koi aisa path exist karta hai ya nahi
    // jiska sum exactly targetSum ke barabar ho
    bool helper(TreeNode* root, int targetSum)
    {
        // 🛑 Base case 1:
        // Agar node NULL ho gayi
        // matlab path yahin break ho gaya
        if(root == NULL) 
            return false;

        // 🟢 Base case 2 (SUCCESS case):
        // Agar current node leaf hai (no left & no right)
        // aur targetSum == root->val
        // matlab ek valid root-to-leaf path mil gaya
        if(root->left == NULL && root->right == NULL 
           && targetSum == root->val) 
            return true;

        // ❌ Base case 3 (FAIL case):
        // Agar leaf node par aa gaye
        // lekin targetSum match nahi hua
        // to ye path invalid hai
        if(root->left == NULL && root->right == NULL 
           && targetSum != root->val) 
            return false;

        // 🔽 Recursive step:
        // Current node ka value subtract kar do
        // kyunki ab children ke liye remaining sum chahiye
        targetSum -= root->val;

        // 🔀 Ab dono possibilities check karo:
        // ya to left subtree me valid path ho
        // ya right subtree me
        return helper(root->left, targetSum) 
            || helper(root->right, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        // 🚀 Actual function sirf helper ko call karta hai
        return helper(root, targetSum);
    }
};




⏱ Time & Space Complexity

Time Complexity: •	O(N)
(Worst case me har node visit)


Space Complexity: •	O(H)
(Recursion stack, H = height of tree)