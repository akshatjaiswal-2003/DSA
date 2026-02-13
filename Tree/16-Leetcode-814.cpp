https://leetcode.com/problems/binary-tree-pruning/description/


class Solution {
public:

    // 🔍 Ye helper function check karega ki
    // given subtree me kahin bhi value 1 exist karti hai ya nahi
    bool check(TreeNode* root)
    {
        // 🛑 Base Case:
        // Agar node NULL hai, iska matlab yaha koi 1 nahi hai
        if(root == NULL) 
            return false;

        // ✅ Agar current node ki value 1 hai
        // to hume mil gaya 1 → true return karo
        if(root->val == 1) 
            return true;

        // 🔁 Recursively left aur right subtree check karo
        // Agar kisi bhi side me 1 milta hai → true return hoga
        return check(root->left) || check(root->right);

        // ⚠️ Ye line kabhi execute nahi hogi
        // kyunki upar hi return ho raha hai
        return false;
    }

    TreeNode* pruneTree(TreeNode* root) {

        // 🛑 Agar tree empty hai
        if(root == NULL) 
            return root;

        // 🔍 Step 1: Check karo left subtree me koi 1 hai ya nahi
        if(check(root->left) == false)
        {
            // ❌ Agar left subtree me 1 nahi hai
            // to pura left subtree delete kar do
            root->left = NULL;
        }

        // 🔍 Step 2: Check karo right subtree me koi 1 hai ya nahi
        if(check(root->right) == false)
        {
            // ❌ Agar right subtree me 1 nahi hai
            // to pura right subtree delete kar do
            root->right = NULL;
        }

        // 🔁 Step 3: Recursively same process children pe apply karo
        pruneTree(root->left);
        pruneTree(root->right);

        // 🧠 Step 4: Final decision for current node
        // Agar:
        // - left NULL
        // - right NULL
        // - value bhi 0
        // To iska matlab is subtree me kahin bhi 1 nahi hai
        // To current node bhi delete ho jayega
        if(root->left == NULL && root->right == NULL && root->val == 0) 
            return NULL;

        // ✅ Otherwise node valid hai
        return root;
    }
};

⏱ Time Complexity

Worst case:

Har node ke liye subtree traverse

👉 O(N²)





----------------------Optimized-------------------------

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) 
            return NULL;

        // Pehle children prune karo
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // Agar:
        // - current value 0
        // - left NULL
        // - right NULL
        // To delete this node
        if(root->val == 0 && root->left == NULL && root->right == NULL)
            return NULL;

        return root;
    }
};



tc = O(n)