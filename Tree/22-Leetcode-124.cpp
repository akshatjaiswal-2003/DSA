https://leetcode.com/problems/binary-tree-maximum-path-sum/



class Solution {
public:

    // 🌍 Global variable
    // Isme pura tree ka maximum path sum store hoga
    int maxSum;

    int helper(TreeNode* root)
    {
        // 🛑 Base Case:
        // Agar node NULL hai
        // to contribution 0 hoga
        if(root == NULL) 
            return 0;

        // 🔁 Postorder traversal
        // Pehle left aur right subtree ka max contribution lo
        int l = helper(root->left);
        int r = helper(root->right);

        // ⚠️ IMPORTANT:
        // Agar child contribution negative hai
        // to usko ignore karna better hota hai
        // (warna sum kam ho jayega)
        // Tumhare code me ye missing hai
        // Ideal:
        // l = max(0, l);
        // r = max(0, r);

        // 🟢 Case 1:
        // Path jo left + root + right ko include kare
        int s1 = root->val + l + r;

        // 🟢 Case 2:
        // Path jo sirf ek side + root use kare
        int s2 = max(l, r) + root->val;

        // 🟢 Case 3:
        // Sirf root ko consider kare
        int s3 = root->val;

        // 🔄 Global maximum update karo
        maxSum = max({maxSum, s1, s2, s3});

        // 📤 Parent ko kya return karna hai?
        // Parent split allow nahi karega
        // Isliye best single-side path return karo
        return max(s2, s3);
    }

    int maxPathSum(TreeNode* root) {

        // 🔄 Initialize with minimum
        maxSum = INT_MIN;

        // 🌳 Entire tree process karo
        helper(root);

        // ✅ Final maximum return karo
        return maxSum;
    }
};


⏱ Time Complexity

Har node ek baar visit

👉 O(N)
