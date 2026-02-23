https://leetcode.com/problems/find-duplicate-subtrees/description/



class Solution {
public:

    // 🔁 Ye function subtree ko string me convert karega
    // aur duplicates detect karega
    string solve(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*>& ans)
    {
        // 🛑 Base Case:
        // Agar node NULL hai
        // To special marker return karo
        // Taaki structure preserve rahe
        if(root == NULL)
        {
            return "N";   // N means Null
        }

        // 🔄 Subtree serialization
        // Format:
        // current_value, left_subtree_string, right_subtree_string
        //
        // Comma important hai
        // Taaki values mix na ho
        string s = to_string(root->val) + "," 
                 + solve(root->left, mp, ans) 
                 + solve(root->right, mp, ans);

        // 📊 Agar ye subtree string pehle ek baar aa chuki hai
        // Matlab ab second time mil rahi hai
        // To duplicate subtree mil gaya
        if(mp[s] == 1)
        {
            ans.push_back(root);
        }

        // 🔢 Frequency increase karo
        mp[s]++;

        // 📤 Parent ko serialized string return karo
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        // 🗺 Hashmap
        // Key   → subtree serialization string
        // Value → frequency count
        unordered_map<string, int> mp;

        // 📦 Result vector
        vector<TreeNode*> ans;

        // 🌳 Entire tree process karo
        solve(root, mp, ans);

        return ans;
    }
};




📊 Complexity Analysis

Let N = number of nodes

⏱ Time Complexity

Har node ek baar visit
But string concatenation ho raha hai

Worst case:

👉 O(N²) (string building cost)

⸻

📦 Space Complexity
	•	Hashmap store karega N strings
	•	Recursion stack O(H)

Total:

👉 O(N²) worst case



-----------------🚀 More Optimal Approach (Interview Level Upgrade)-----------------

class Solution {
public:

    // 🔁 Ye recursive function subtree ko serialize karta hai
    // Aur check karta hai ki same subtree pehle mila hai ya nahi
    //
    // Parameters:
    // root → current node
    // mp → map jo serialized subtree ko count karta hai
    // ans → duplicate subtree ke roots store karega
    //
    // Return:
    // string → current subtree ka serialized form

    string solve(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*>& ans)
    {
        // 🛑 Base Case:
        // Agar node NULL hai
        // To ek special marker return karte hain
        // "N" likhne se structure maintain rehta hai
        if(root == NULL)
        {
            return "N";
        }

        // 🔁 Current subtree ko string me convert kar rahe hain
        // Format:
        // node_value,left_subtree,right_subtree
        //
        // Isse structure uniquely represent hota hai
        string s = to_string(root->val) + "," 
                   + solve(root->left, mp, ans) + "," 
                   + solve(root->right, mp, ans);

        // ❗ Agar ye serialization pehle exactly 1 baar mila hai
        // Matlab ye subtree duplicate ho gaya hai
        // (2nd time mil raha hai)
        if(mp[s] == 1)
        {
            ans.push_back(root);
        }

        // 📈 Map me count increase karo
        mp[s]++;

        // 🔄 Serialized string return karo parent call ke liye
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        // 📦 Map: subtree string → frequency
        unordered_map<string, int> mp;

        // 🎯 Final answer vector
        vector<TreeNode*> ans;

        // 🔁 Recursion start
        solve(root, mp, ans);

        return ans;
    }
};