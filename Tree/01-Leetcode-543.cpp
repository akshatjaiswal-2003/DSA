// https://leetcode.com/problems/diameter-of-binary-tree/


class Solution {
public:

    // -----------------------------------------
    // height() function
    // -----------------------------------------
    // Ye function kisi bhi node ka HEIGHT nikalta hai
    // Height = max depth from that node to any leaf
    //
    // Example:
    //      1
    //     /
    //    2
    //   /
    //  3
    //
    // height(1) = 3
    // height(2) = 2
    // height(3) = 1
    //
    int height(TreeNode* root)
    {
        // Base case:
        // Agar node NULL hai
        // to height = 0
        if(root == NULL) 
            return 0;

        // Recursive case:
        // 1 (current node) +
        // max(left subtree height, right subtree height)
        return 1 + max(height(root->left), height(root->right));
    }


    // -----------------------------------------
    // helper() function
    // -----------------------------------------
    // Ye function har node par jaakar
    // "diameter through that node" calculate karta hai
    //
    // Diameter through a node =
    // height(left subtree) + height(right subtree)
    //
    int helper(TreeNode* root, int &maxDia)
    {
        // Agar node NULL hai
        // to koi diameter possible nahi
        if(root == NULL) 
            return 0;

        /*
            Current node se diameter nikal rahe hain:

            dia = left subtree ki height
                + right subtree ki height

            NOTE:
            Yahan height() function har baar O(n) ka kaam kar raha hai
            jo inefficiency laata hai
        */
        int dia = height(root->left) + height(root->right);

        // Global maximum diameter update kar rahe hain
        maxDia = max(maxDia, dia);

        // Left subtree ke liye helper call
        helper(root->left, maxDia);

        // Right subtree ke liye helper call
        helper(root->right, maxDia);

        // maxDia return kar rahe hain
        // (waise is return ka yahan koi practical use nahi ho raha)
        return maxDia;
    }


    // -----------------------------------------
    // diameterOfBinaryTree()
    // -----------------------------------------
    // Ye main function hai jo LeetCode call karta hai
    //
    // Diameter = longest path between ANY two nodes
    // Path root se ho ya na ho, farq nahi padta
    //
    int diameterOfBinaryTree(TreeNode* root) {

        // Maximum diameter ko store karne ke liye variable
        int maxDia = 0;

        // Helper function call
        helper(root, maxDia);

        // Final diameter return
        return maxDia; 
    }
};



⚠️ Important Observation (VERY IMPORTANT)

❌ Problem in this approach
	•	height() function har node par baar-baar call ho raha hai
	•	height() khud O(n) hai
	•	helper() bhi har node par jaa raha hai






// ✅ Optimized Approach (Single DFS)

class Solution {
public:

    // Ye function height return karega
    // aur saath hi saath maxDiameter update karta rahega
    int dfs(TreeNode* root, int &maxDia)
    {
        // Base case:
        // Agar node NULL hai to height = 0
        if(root == NULL)
            return 0;

        // Left subtree ki height nikal lo
        int leftHeight = dfs(root->left, maxDia);

        // Right subtree ki height nikal lo
        int rightHeight = dfs(root->right, maxDia);

        /*
            Diameter through current node:

                  root
                 /    \
            leftHeight rightHeight

            Diameter = leftHeight + rightHeight
        */
        int currDia = leftHeight + rightHeight;

        // Global maximum diameter update karo
        maxDia = max(maxDia, currDia);

        // Current node ki height return karo
        // Height = 1 (current node) + max(left, right)
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        // Global maximum diameter
        int maxDia = 0;

        // DFS traversal
        dfs(root, maxDia);

        // Final answer
        return maxDia;
    }
};


Time Complexity  O(n)
Space Complexity O(h) (height of tree)

