https://leetcode.com/problems/delete-nodes-and-return-forest/description/


class Solution {
public:

    // 🔁 Recursive helper function
    // Ye function modified subtree ka root return karega
    TreeNode* deleteHelper(TreeNode* root, 
                           unordered_set<int> &st, 
                           vector<TreeNode*> &result)
    {
        // 🛑 Base case
        if(root == NULL) 
            return NULL;

        // 🌳 Step 1: Pehle left subtree process karo
        root->left = deleteHelper(root->left, st, result);

        // 🌳 Step 2: Fir right subtree process karo
        root->right = deleteHelper(root->right, st, result);

        // 🔍 Step 3: Check karo kya current node delete list me hai
        if(st.find(root->val) != st.end())
        {
            // ❗ Agar current node delete ho raha hai:

            // 👉 Agar left child exist karta hai
            // to wo ek naya tree root ban jayega
            if(root->left != NULL) 
                result.push_back(root->left);

            // 👉 Agar right child exist karta hai
            // to wo bhi naya tree root ban jayega
            if(root->right != NULL) 
                result.push_back(root->right);

            // 🚫 Current node ko delete kar rahe hain
            // Parent ko NULL return karenge
            return NULL;
        }
        else 
        {
            // ✅ Agar delete nahi ho raha
            // to simply node ko return kar do
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        vector<TreeNode*> result;

        // 🔐 Fast lookup ke liye unordered_set use kar rahe hain
        unordered_set<int> st;

        // 🗂 to_delete list ko set me daal diya (O(1) lookup)
        for(auto &i : to_delete)
        {
            st.insert(i);
        }

        // 🌳 Tree ko process karo
        deleteHelper(root, st, result);

        // 🔎 Special Case:
        // Agar original root delete nahi hua
        // to wo bhi forest ka part hoga
        if(st.find(root->val) == st.end())
        {
            result.push_back(root);
        }

        // 🌲 Final forest return karo
        return result;
    }
};




⏱ Time Complexity
	•	Har node ek baar visit → O(N)
	•	Hash lookup → O(1)

Total → O(N)

⸻

📦 Space Complexity
	•	Recursion stack → O(H)
	•	HashSet → O(N)
	•	Result vector → O(N)

Worst case → O(N)