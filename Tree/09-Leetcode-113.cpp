https://leetcode.com/problems/path-sum-ii/



class Solution {
public:

    // 🔁 Helper function:
    // root      -> current node
    // targetSum-> abhi kitna sum banana baaki hai
    // finalAns -> saare valid root-to-leaf paths store karega
    // ans      -> current path (root se current node tak)
    void helper(TreeNode* root, int targetSum, 
                vector<vector<int>> &finalAns, 
                vector<int> ans)
    {
        // 🛑 Base case:
        // Agar node hi NULL hai, to wapas jao
        if(root == NULL) return;

        // 🟥 Agar leaf node hai
        // aur targetSum current node ke value ke barabar nahi hai
        // matlab ye path invalid hai
        if(root->left == NULL && root->right == NULL 
           && targetSum != root->val)
            return;

        // 🟢 Agar leaf node hai
        // aur targetSum exactly current node ke value ke barabar hai
        // matlab ek VALID PATH mil gaya
        if(!(root->left) && !(root->right) 
           && targetSum == root->val)
        {
            // 🧩 Current node ko path me add karo
            ans.push_back(root->val);

            // ✅ Is complete path ko finalAns me store karo
            finalAns.push_back(ans);

            // 🔙 Wapas return (kyunki leaf node hai)
            return;
        }

        // 🔽 Current node ka value targetSum se subtract kar rahe hain
        targetSum -= root->val;

        // 🧩 Current node ko path me add kar diya
        ans.push_back(root->val);

        // 👈 Left subtree me search
        helper(root->left, targetSum, finalAns, ans);

        // 👉 Right subtree me search
        helper(root->right, targetSum, finalAns, ans);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        // 🟢 Final answer: saare valid paths
        vector<vector<int>> finalAns;

        // 🟡 Temporary vector for current path
        vector<int> ans;

        // 🔁 DFS traversal start
        helper(root, targetSum, finalAns, ans);

        // 🟢 Result return
        return finalAns;
    }
};


🧠 Intuition (Easy Hinglish)
	•	Hume root → leaf tak ke saare paths chahiye
	•	Jinka sum == targetSum
	•	DFS use karte hain:
	•	Har node pe:
	•	Uska value path me add
	•	targetSum ko reduce
	•	Jab leaf node aaye:
	•	Check karo targetSum == leaf->val
	•	Agar haan → path valid ✅




⏱ Complexity Analysis

Time Complexity:
	•	O(N)
Har node ek baar visit hota hai

Space Complexity:
	•	O(H) recursion stack (H = height of tree)
	•	Plus output space for storing paths