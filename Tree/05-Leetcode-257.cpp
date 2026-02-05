https://leetcode.com/problems/binary-tree-paths/description/


class Solution {
public:

    // Ye helper function root se leaf tak ke saare paths banata hai
    // aur unko finalAns vector mein store karta hai
    void helper(TreeNode* root, string ans, vector<string> &finalAns)
    {
        // 🔴 Base case:
        // Agar current node NULL hai
        // matlab is path mein aage kuch nahi hai
        if(root == NULL) 
            return;

        // Current node ki value ko string mein convert kar rahe hain
        string a = to_string(root->val);

        // 🍃 Leaf node case:
        // Agar left aur right dono NULL hain
        // matlab yahin ek complete root-to-leaf path ban gaya
        if(root->left == NULL && root->right == NULL)
        {
            // Current node ki value add karo
            ans += a;

            // Complete path ko answer list mein push karo
            finalAns.push_back(ans);

            // Leaf mil gaya, is path par recursion yahin stop
            return;
        }

        // 🌿 Non-leaf node:
        // Current node ki value + "->" add kar rahe hain
        ans = ans + a + "->";

        // 🔽 Left subtree ke paths explore karo
        helper(root->left, ans, finalAns);

        // 🔽 Right subtree ke paths explore karo
        helper(root->right, ans, finalAns);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        // Final answer store karne ke liye vector
        vector<string> finalAns;

        // DFS start kar rahe hain root se
        // Initially path empty hai ""
        helper(root, "", finalAns);

        // Saare root-to-leaf paths return karo
        return finalAns;
    }
};


🧠 Intuition (Simple Hinglish)
	•	DFS traversal karte hain tree ka
	•	Root se start karke:
	•	Har node ki value string mein add karte jaate hain
	•	Jab leaf node milta hai:
	•	Current string ek complete path ban jaata hai
	•	Usko answer vector mein daal dete hain

👉 Backtracking automatically ho jaata hai kyunki ans string by value pass ho rahi hai




⏱️ Time & Space Complexity

Time Complexity
	•	O(n) nodes visit hote hain
	•	String concatenation cost bhi hota hai → overall O(n * h)

Space Complexity
	•	O(h) recursion stack
	•	Answer vector mein paths ka space alag se




🎤 Interview Explanation (Ready Script)

“We perform a DFS traversal from the root.
We keep building a string representing the current path.
Whenever we reach a leaf node, we add the complete path to the result.
Since strings are passed by value, no manual backtracking is required.”