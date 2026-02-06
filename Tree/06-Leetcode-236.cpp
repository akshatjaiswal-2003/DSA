https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/



class Solution {
public:

    // Ye function check karta hai:
    // kya target node given root ke subtree mein exist karti hai ya nahi
    bool find(TreeNode* root, TreeNode* target)
    {
        // 🔴 Base case:
        // Agar root NULL ho gaya
        // matlab target yahan nahi mil sakta
        if(root == NULL) 
            return false;

        // 🔴 Agar current node hi target hai
        // to directly true return
        if(root == target) 
            return true;

        // 🔽 Otherwise:
        // left subtree ya right subtree mein dhundo
        return find(root->left, target) || find(root->right, target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        /*
            Idea:
            - Agar p aur q dono left subtree mein hain
              => LCA bhi left subtree mein hoga
            - Agar p aur q dono right subtree mein hain
              => LCA bhi right subtree mein hoga
            - Otherwise current root hi LCA hai
        */

        // 🔽 Case 1:
        // p aur q dono left subtree mein mil gaye
        if(find(root->left, p) && find(root->left, q))  
            return lowestCommonAncestor(root->left, p, q);

        // 🔽 Case 2:
        // p aur q dono right subtree mein mil gaye
        else if(find(root->right, p) && find(root->right, q))  
            return lowestCommonAncestor(root->right, p, q);

        // 🔽 Case 3:
        // Ek node left mein aur ek right mein
        // ya root hi p/q hai
        // to current root hi LCA hai
        return root;
    }
};



❌ Problem with This Approach (Very Important)

🔴 Time Complexity Issue
	•	find() function O(n) hai
	•	Har recursive LCA call mein:
	•	find() ko multiple times call kar rahe ho
	•	Worst case:
	•	Har node par pura tree traverse

👉 Overall Time Complexity = O(n²) ❌

Interview mein yahin par minus points milte hain.







✅ Interview-Perfect Optimized Approach (O(n))

🔑 Key Idea
	•	Ek hi DFS traversal mein:
	•	p mil gaya?
	•	q mil gaya?
	•	Jis node par:
	•	left se ek mila
	•	right se ek mila
→ wahi LCA


⚡ Optimized Code

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // 🔴 Base case:
        // Agar root NULL ho
        // ya root hi p ya q ho
        // to root return kar do
        if(root == NULL || root == p || root == q)
            return root;

        // 🔽 Left subtree mein search
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // 🔽 Right subtree mein search
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 🔴 Case 1:
        // Agar left aur right dono non-null hain
        // matlab p aur q alag-alag side mein mile
        // => current root hi LCA hai
        if(left != NULL && right != NULL)
            return root;

        // 🔴 Case 2:
        // Agar sirf ek side se node mili
        // wahi upar propagate karo
        return (left != NULL) ? left : right;
    }
};

🎤 Interview Explanation (Strong Answer)

“We perform a single DFS traversal.
If the current node is p or q, we return it.
We recursively search left and right subtrees.
If both sides return non-null, the current node is the LCA.
Otherwise, we propagate the non-null result upward.”
