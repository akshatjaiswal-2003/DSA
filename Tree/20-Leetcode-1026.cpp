https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/



class Solution {
public:

    // 🌍 Global variable
    // Isme maximum difference store hoga
    int maxDiff;

    // 🔍 Ye function compare karega:
    // root (ancestor) ko
    // uske subtree ke har child se
    void maxDiffFill(TreeNode* root, TreeNode* child)
    {
        // 🛑 Base case
        // Agar root NULL ya child NULL hai to return
        if(root == NULL) return;
        if(child == NULL) return;

        // 📏 Difference calculate karo
        // ancestor (root) aur descendant (child) ka
        maxDiff = max(maxDiff, abs(root->val - child->val));

        // 🔁 Ab child ke left subtree me check karo
        maxDiffFill(root, child->left);

        // 🔁 Ab child ke right subtree me check karo
        maxDiffFill(root, child->right);
    }

    // 🔁 Ye function har node ko ancestor maan kar
    // uske neeche ke sab descendants ke saath compare karega
    void helper(TreeNode* root)
    {
        // 🛑 Base case
        if(root == NULL) return;

        // 🎯 Current node ko ancestor maan kar
        // left subtree ke saath compare karo
        maxDiffFill(root, root->left);

        // 🎯 Right subtree ke saath compare karo
        maxDiffFill(root, root->right);

        // 🔁 Ab left child ko ancestor bana do
        helper(root->left);

        // 🔁 Ab right child ko ancestor bana do
        helper(root->right);
    }

    int maxAncestorDiff(TreeNode* root) {

        // 🔄 Initialize global variable
        maxDiff = -1;

        // 🌳 Entire tree process karo
        helper(root);

        // ✅ Final maximum difference return karo
        return maxDiff;
    }
};



🧠 Intuition: Tumhara Code Kya Kar Raha Hai?

Step-by-step:
	1.	Har node ko ancestor treat kar rahe ho
	2.	Uske pure subtree me jaa kar difference calculate kar rahe ho
	3.	Fir next node ko ancestor bana rahe ho
	4.	Same process repeat

Matlab:

For each node → traverse entire subtree again




📊 Complexity Analysis (Important ⚠️)

Let N = number of nodes

Worst case (skewed tree):
	•	For root → N comparisons
	•	For next node → N-1 comparisons
	•	Next → N-2

👉 Time Complexity = O(N²) ❌





-------------------------💎 Optimized Code (O(N))---------------------

Trick:

Instead of comparing every ancestor separately,

👉 Root se downward jaate waqt:
	•	Path ka minimum value track karo
	•	Path ka maximum value track karo

Phir difference:  max - min



class Solution {
public:

    int solve(TreeNode* root, int currMin, int currMax)
    {
        if(root == NULL)
            return currMax - currMin;

        // Update min and max on path
        currMin = min(currMin, root->val);
        currMax = max(currMax, root->val);

        // Explore both subtrees
        int left = solve(root->left, currMin, currMax);
        int right = solve(root->right, currMin, currMax);

        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};