https://leetcode.com/problems/path-sum-iii/


class Solution {
public:

    // 🔁 Helper function ka kaam:
    // Ye function check karta hai ki
    // current node se neeche jaate hue
    // kitne paths ka sum = targetSum ban raha hai
    void helper(TreeNode* root, long long targetSum, int &count)
    {
        // 🛑 Base case:
        // Agar node NULL ho gayi, to aage path possible nahi
        if(root == NULL) return;

        // 🎯 Agar current node ka value hi targetSum ke barabar hai
        // matlab ek valid path mil gaya (yahin end kar sakta hai)
        if(targetSum == root->val)
        {
            count++;   // ✅ path count badha do
        }

        // 🔽 Ab current node ka value subtract kar rahe hain
        // kyunki path continue karna hai
        targetSum -= root->val;

        // 👈 Left subtree me path continue karo
        helper(root->left, targetSum, count);

        // 👉 Right subtree me path continue karo
        helper(root->right, targetSum, count);
    }

    int pathSum(TreeNode* root, int targetSum) {

        // 🛑 Agar tree hi empty hai
        if(root == NULL) return 0;

        // 🔢 Ye count store karega
        // kitne valid paths mile
        int count = 0;

        // 🔁 Step 1:
        // Current node ko starting point maan kar
        // saare downward paths check karo
        helper(root, (long long)(targetSum), count);

        // 🔁 Step 2:
        // Ab recursively left subtree se paths count karo
        // aur right subtree se paths count karo
        count += pathSum(root->left, targetSum) 
               + pathSum(root->right, targetSum);

        // 🟢 Final answer return
        return count;
    }
};





🧠 Core Idea (Simple Hinglish)

👉 Path Sum III me:
	•	Path kahin se bhi start ho sakta hai
	•	Path kahin bhi end ho sakta hai
	•	Bas condition:
	•	Path downward hona chahiye
	•	Sum = targetSum

Strategy:
	1.	Har node ko starting point maan lo
	2.	Us node se neeche jaate hue:
	•	kitne paths ka sum targetSum ban raha → helper
	3.	Fir same cheez left subtree aur right subtree ke liye repeat




⏱ Time & Space Complexity

Time Complexity:
	•	O(N²) worst case
(Har node ko start point bana ke traversal)

Space Complexity:
	•	O(H) recursion stack
(H = height of tree)





⚠ Important Interview Point

👉 Ye solution correct hai but optimal nahi ❌
Best solution uses:
	•	Prefix Sum + HashMap
	•	Time Complexity: O(N) 🔥
