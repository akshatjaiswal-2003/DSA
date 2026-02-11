https : // leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

        class Solution
{
public:
    // 🔍 inorder ke har element ka index store karenge
    unordered_map<int, int> inMap;

    // 🔁 Recursive helper function
    TreeNode *helper(vector<int> &in, int inLow, int inHigh,vector<int> &post, int postLow, int postHigh)
    {
        // 🛑 Base case: agar range invalid ho gayi
        if (inLow > inHigh || postLow > postHigh) return NULL;

        // 🌱 Postorder ka LAST element = ROOT
        int rootVal = post[postHigh];
        TreeNode *root = new TreeNode(rootVal);

        // 🔍 Root ka index inorder se O(1) me nikaal liya
        int inRootIdx = inMap[rootVal];

        // 📊 Left subtree me kitne nodes hain
        int leftCount = inRootIdx - inLow;

        // 🌳 Left subtree construct karo
        root->left = helper(
            in,
            inLow,
            inRootIdx - 1,
            post,
            postLow,
            postLow + leftCount - 1);

        // 🌳 Right subtree construct karo
        root->right = helper(
            in,
            inRootIdx + 1,
            inHigh,
            post,
            postLow + leftCount,
            postHigh - 1);

        // 🔙 Root return
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        int n = inorder.size();

        // 🗂️ inorder ka index map bana lo
        for (int i = 0; i < n; i++)
        {
            inMap[inorder[i]] = i;
        }

        // 🚀 recursion start (full range)
        return helper(inorder, 0, n - 1,postorder, 0, n - 1);
    }
};



⏱️ Complexity (Interview bolne ke liye)
	•	Time: O(N)
	•	Space: O(N) (map + recursion stack)




🎯 Interview one-liner

“Postorder ka last element root hota hai.
Inorder se left aur right subtree ka size milta hai.
HashMap use karke inorder lookup O(1) ho jata hai,
isliye overall solution O(N) hai.”