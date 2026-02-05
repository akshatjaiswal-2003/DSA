https://leetcode.com/problems/same-tree/



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // 🔴 Case 1:
        // Agar dono trees ke current nodes NULL hain
        // matlab dono jagah tree khatam ho gaya
        // so structure bhi same hai
        if(p == NULL && q == NULL) 
            return true;

        // 🔴 Case 2:
        // Agar ek NULL hai aur dusra NULL nahi
        // matlab structure different hai
        if(p == NULL || q == NULL) 
            return false;

        // 🔴 Case 3:
        // Agar dono nodes exist karte hain
        // lekin unki values match nahi karti
        // matlab trees same nahi ho sakte
        if(p->val != q->val) 
            return false;

        // 🔽 Recursive check on LEFT subtree
        bool leftAns = isSameTree(p->left, q->left);

        // Agar left subtree same nahi hai
        // to directly false return kar do
        // (short-circuiting for efficiency)
        if(leftAns == false) 
            return false;

        // 🔽 Recursive check on RIGHT subtree
        bool rightAns = isSameTree(p->right, q->right);

        // Agar right subtree same nahi hai
        // to false return
        if(rightAns == false) 
            return false;

        // ✅ Agar:
        // - current node value same
        // - left subtree same
        // - right subtree same
        // tab trees bilkul identical hain
        return true;
    }
};


🧠 Intuition (Simple Words)
	•	Dono trees ko node-by-node compare karte hain
	•	Har node par 3 cheezein check hoti hain:
	1.	Dono NULL?
	2.	Ek NULL aur dusra non-NULL?
	3.	Dono ki value same?
	•	Agar upar ke checks pass ho jaayein:
	•	Left subtree compare
	•	Right subtree compare

👉 Pure tree ka DFS traversal ho jaata hai





⏱️ Time & Space Complexity

Time Complexity
	•	O(n)
(n = number of nodes, har node ek baar visit hota hai)

Space Complexity
	•	O(h)
(h = height of tree, recursion stack ke liye)