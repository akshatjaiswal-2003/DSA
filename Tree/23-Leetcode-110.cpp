https://leetcode.com/problems/balanced-binary-tree/description/



class Solution {
public:

    // 📏 Ye function kisi subtree ki height calculate karta hai
    // Height = longest path from node to leaf
    int height(TreeNode* root)
    {
        // 🛑 Base Case:
        // Agar node NULL hai to height 0
        if(root == NULL) 
            return 0;

        // 🔁 Recursively left aur right height calculate karo
        // Aur maximum le lo
        return 1 + max(height(root->left), height(root->right));
    }

    // 🔍 Ye function check karega ki subtree balanced hai ya nahi
    bool helper(TreeNode* root)   
    {
        // 🛑 Base Case:
        // NULL tree always balanced hota hai
        if(root == NULL) 
            return true;

        // 📏 Left subtree ki height nikal lo
        int ls = height(root->left);

        // 📏 Right subtree ki height nikal lo
        int rs = height(root->right);

        // ❗ Agar height difference 1 se zyada hai
        // To tree balanced nahi hai
        if(abs(ls - rs) > 1) 
            return false;

        // 🔁 Ab recursively check karo
        // Kya left subtree balanced hai?
        int lcs = helper(root->left);

        // 🔁 Kya right subtree balanced hai?
        int rcs = helper(root->right);

        // ✅ Dono balanced hone chahiye
        return lcs && rcs;
    }

    bool isBalanced(TreeNode* root) {

        // 🛑 Agar tree empty hai
        // To wo balanced mana jata hai
        if(root == NULL) 
            return true;

        // 🔍 Entire tree check karo
        return helper(root);
    }
};


🧠 Intuition Samjho

Har node pe tum:

1️⃣ Height nikal rahe ho left aur right ka
2️⃣ Difference check kar rahe ho
3️⃣ Fir recursively children pe same kaam kar rahe ho

Matlab:

For every node → tum height function dubara chala rahe ho.



⏱ Time Complexity = O(N²)




------------------------🚀 Optimal Approach (Single DFS – O(N))-----------------------

🧠 Intuition Deep Samjho

Har node pe hum:

1️⃣ Left subtree ki height lete hain
2️⃣ Right subtree ki height lete hain
3️⃣ Difference check karte hain

Agar kahin bhi imbalance mila:

👉 -1 return
👉 Upar tak propagate ho jayega
👉 Pure tree me turant stop ho sakta hai

Isliye efficient hai 🚀




class Solution {
public:

    // 📏 Ye function 2 kaam ek saath karta hai:
    // 1️⃣ Height calculate karta hai
    // 2️⃣ Check karta hai balanced hai ya nahi
    //
    // Return value:
    // ✔ Normal height agar subtree balanced hai
    // ❌ -1 agar subtree unbalanced hai

    int checkHeight(TreeNode* root)
    {
        // 🛑 Base Case:
        // Agar node NULL hai
        // To height 0 hoti hai
        if(root == NULL)
            return 0;

        // 🔁 Pehle left subtree ki height nikalo
        int l = checkHeight(root->left);

        // ❗ Agar left subtree already unbalanced hai
        // To turant -1 return karo (early exit)
        if(l == -1) 
            return -1;

        // 🔁 Fir right subtree ki height nikalo
        int r = checkHeight(root->right);

        // ❗ Agar right subtree unbalanced hai
        // To turant -1 return karo
        if(r == -1) 
            return -1;

        // 📏 Ab current node pe balance check karo
        // Agar height difference 1 se zyada hai
        // To ye subtree unbalanced hai
        if(abs(l - r) > 1)
            return -1;

        // ✅ Agar balanced hai
        // To normal height return karo
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {

        // Agar checkHeight -1 return kare
        // Matlab tree unbalanced hai
        // Otherwise balanced
        return checkHeight(root) != -1;
    }
};
