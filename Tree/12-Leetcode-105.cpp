https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/




class Solution {
public:

    // 🔁 helper function ka kaam:
    // preorder aur inorder array ke given range se
    // binary tree construct karna aur root return karna
    TreeNode* helper(vector<int>& pre, int preLow, int preHigh,
                     vector<int>& in,  int inLow,  int inHigh)
    {
        // 🛑 Base Case 1:
        // Agar preorder ka range invalid ho gaya
        // matlab yahan koi node exist nahi karta
        if(preLow > preHigh) 
            return NULL;

        // 🌱 Preorder ka pehla element hamesha ROOT hota hai
        TreeNode* root = new TreeNode(pre[preLow]);

        // 🛑 Base Case 2:
        // Agar sirf ek hi element bacha hai
        // to wahi node root hoga, left/right NULL
        if(preLow == preHigh) 
            return root;

        // 🔍 Ab inorder array me root ka index dhundo
        // kyunki inorder me:
        // left subtree | root | right subtree
        int i = inLow;
        while(i <= inHigh)
        {
            if(pre[preLow] == in[i]) 
                break;
            i++;
        }

        // 📊 Count nikal rahe hain:
        // inorder ke left side me kitne elements hain
        int leftCount = i - inLow;

        // inorder ke right side me kitne elements hain
        int rightCount = inHigh - i;

        // 🌳 Left Subtree Construction:
        // preorder me root ke baad leftCount elements
        root->left = helper(
            pre,
            preLow + 1,
            preLow + leftCount,
            in,
            inLow,
            i - 1
        );

        // 🌳 Right Subtree Construction:
        // preorder me left subtree ke baad jo bacha
        root->right = helper(
            pre,
            preLow + leftCount + 1,
            preHigh,
            in,
            i + 1,
            inHigh
        );

        // 🔙 Constructed root return karo
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {

        // 🧮 Total number of nodes
        int n = pre.size();

        // 🚀 Pura range helper ko de do
        return helper(pre, 0, n-1, in, 0, n-1);
    }
};



⏱ Time & Space Complexity

⏱ Time Complexity:
	•	O(N²) ❌ (current code)
	•	kyunki har recursive call me inorder me linear search ho rahi hai

👉 Optimized version (HashMap):
	•	O(N) ✅

🧠 Space Complexity:
	•	O(N)
	•	recursion stack + tree nodes






// Optimized Code (Preorder + Inorder → Binary Tree)

class Solution {
public:

    // 🔍 inorder ke har element ka index store karenge
    unordered_map<int, int> inMap;

    // 🔁 Recursive helper function
    TreeNode* helper(vector<int>& pre, int preLow, int preHigh,
                     vector<int>& in,  int inLow,  int inHigh)
    {
        // 🛑 Base case:
        // Agar range invalid ho gayi
        if(preLow > preHigh || inLow > inHigh)
            return NULL;

        // 🌱 Preorder ka first element = ROOT
        int rootVal = pre[preLow];
        TreeNode* root = new TreeNode(rootVal);

        // 🔍 Root ka index inorder se O(1) me nikaal liya
        int inRootIdx = inMap[rootVal];

        // 📊 Left subtree me kitne nodes hain
        int leftCount = inRootIdx - inLow;

        // 🌳 Left subtree construct karo
        root->left = helper(
            pre,
            preLow + 1,
            preLow + leftCount,
            in,
            inLow,
            inRootIdx - 1
        );

        // 🌳 Right subtree construct karo
        root->right = helper(
            pre,
            preLow + leftCount + 1,
            preHigh,
            in,
            inRootIdx + 1,
            inHigh
        );

        // 🔙 Root return
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {

        int n = pre.size();

        // 🗂️ inorder ka index map bana lo
        for(int i = 0; i < n; i++)
        {
            inMap[in[i]] = i;
        }

        // 🚀 Full range ke saath recursion start
        return helper(pre, 0, n - 1, in, 0, n - 1);
    }
};



🎯 Interview One-Liner (Must Remember)

“Preorder ka first element root hota hai,
inorder root ke around left/right subtree batata hai,
aur hashmap se hum tree ko O(N) me build kar sakte hain”