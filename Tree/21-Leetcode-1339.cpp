https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/




🧠 Core Idea (Important)
	1.	Pehle pura tree ka total sum nikal lo
	2.	Fir har subtree ka sum calculate karo
	3.	Har node pe imagine karo ki yaha edge cut kiya
	4.	Product calculate karo
	5.	Maximum store karo



class Solution {
public:

    // 🌍 Global variable
    // Isme pura tree ka total sum store hoga
    int SUM = 0;

    // 🌍 Maximum product store karne ke liye
    long maxP = 0;

    // 🔢 Step 1: Pura tree ka total sum nikalne ke liye
    int helperSum(TreeNode* root)
    {
        // 🛑 Base Case
        if(root == NULL) 
            return 0;

        // 🔁 Postorder traversal
        // Left sum + Right sum + Current value
        return root->val 
             + helperSum(root->left) 
             + helperSum(root->right);
    }

    // 🔍 Step 2: Har subtree ka sum calculate karte hue
    // maximum product find karna
    int find(TreeNode* root)
    {
        // 🛑 Base Case
        if(root == NULL) 
            return 0;

        // 🔁 Left subtree ka sum
        int leftSum  = find(root->left);

        // 🔁 Right subtree ka sum
        int rightSum = find(root->right);

        // 🌳 Current subtree ka total sum (S1)
        long subTreeSum = root->val + leftSum + rightSum;

        // 🌳 Remaining tree ka sum (S2)
        long remaningSubTreeSum = SUM - subTreeSum;

        // 📏 Product calculate karo
        long product = subTreeSum * remaningSubTreeSum;

        // 🔄 Maximum update karo
        maxP = max(maxP, product);

        // 📤 Subtree sum return karo parent ke liye
        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {

        // 🔢 Step 1: Pura tree ka sum calculate karo
        SUM = helperSum(root);

        // 🔍 Step 2: Har possible cut check karo
        find(root);

        // 📦 Final answer mod me return karo
        return maxP % 1000000007;
    }
};


⏱ Time Complexity
	1.	helperSum() → O(N)
	2.	find() → O(N)