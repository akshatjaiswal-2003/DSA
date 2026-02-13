https://leetcode.com/problems/leaf-similar-trees/description/



class Solution {
public:

    // 🌿 Ye helper function leaf nodes ko collect karega
    // root → current node
    // ans  → string jisme leaf sequence store hoga
    void fill(TreeNode* root, string &ans)
    {
        // 🛑 Base Case:
        // Agar node NULL hai to kuch nahi karna
        if(root == NULL) 
            return;

        // 🌿 Check karo kya current node leaf hai
        // Condition:
        // left == NULL AND right == NULL
        if(root->left == NULL && root->right == NULL)
        {
            // 👉 Leaf value ko string me add karo
            ans += to_string(root->val);

            // 🔹 Separator add kar rahe hain
            // Taaki values merge na ho jaaye
            // Example: 1 and 11 confuse na ho
            ans += "_";
        }

        // 🔁 Left subtree traverse karo
        fill(root->left, ans);

        // 🔁 Right subtree traverse karo
        fill(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        // 🌳 Dono trees ke leaf sequences store karne ke liye strings
        string ans1;
        string ans2;

        // 🌿 Tree 1 ka leaf sequence collect karo
        fill(root1, ans1);

        // 🌿 Tree 2 ka leaf sequence collect karo
        fill(root2, ans2);

        // 🔍 Dono sequences compare karo
        if(ans1 != ans2) 
            return false;

        return true;
    }
};




📊 Complexity Analysis

⏱ Time Complexity
	•	Har node ek baar visit
	•	Tree1 → O(N)
	•	Tree2 → O(M)

Total:

👉 O(N + M)