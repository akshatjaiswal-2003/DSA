https://leetcode.com/problems/symmetric-tree/description/


class Solution {
public:

    // Ye helper function check karta hai
    // ki left subtree aur right subtree
    // ek dusre ka mirror image hain ya nahi
    bool helper(TreeNode* rootLeft, TreeNode* rootRight)
    {
        // 🔴 Case 1:
        // Agar dono nodes NULL hain
        // matlab dono side ek saath khatam ho gayi
        // => symmetric till here
        if(rootLeft == NULL && rootRight == NULL) 
            return true;

        // 🔴 Case 2:
        // Agar ek NULL hai aur dusra NULL nahi
        // matlab structure different hai
        // => symmetric nahi ho sakta
        if(rootLeft == NULL || rootRight == NULL) 
            return false;

        // 🔴 Case 3:
        // Dono nodes exist karte hain
        // lekin unki values equal nahi hain
        // => mirror condition fail
        if(rootLeft->val != rootRight->val) 
            return false;

        /*
            🔁 Mirror comparison:
            Left subtree ka LEFT part
            compare hoga Right subtree ke RIGHT part se

            aur

            Left subtree ka RIGHT part
            compare hoga Right subtree ke LEFT part se
        */

        bool leftAns = helper(rootLeft->left, rootRight->right);
        bool rightAns = helper(rootLeft->right, rootRight->left);

        // Dono taraf se mirror match hona chahiye
        return leftAns && rightAns;
    }

    bool isSymmetric(TreeNode* root) {

        // Root ke left aur right subtree ko
        // mirror ki tarah compare kar rahe hain
        return helper(root->left, root->right);
    }
};



🧠 Intuition (Simple Hinglish)
	•	Symmetric tree ka matlab:
	•	Left subtree mirror image ho right subtree ka
	•	Mirror ka rule:
	•	Left ka left ↔ Right ka right
	•	Left ka right ↔ Right ka left
	•	Har node par:
	•	Values same honi chahiye
	•	Structure same hona chahiye

👉 Ye DFS + recursion based solution hai



⏱️ Time & Space Complexity
TC - O(n)
SC - O(h)


🎤 Interview Explanation (Best Version)

“To check symmetry, we compare the left and right subtrees as mirror images.
At each step, values of nodes must match and their children must be mirror-aligned:
left’s left with right’s right, and left’s right with right’s left.
If all recursive checks pass, the tree is symmetric.”