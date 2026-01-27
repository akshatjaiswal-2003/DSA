class Solution {
public:
    void deleteNode(ListNode* node) {

        // ⚠️ IMPORTANT:
        // Hume yaha sirf wahi node diya gaya hai jise delete karna hai
        // Head node available nahi hai
        // Aur yeh bhi guarantee hai ki yeh last node (tail) nahi hoga

        // 🔹 Step 1:
        // Current node ke andar next node ka value copy kar dete hain
        // Isse logically lagta hai ki current node "delete" ho gaya
        // Example: node = 5, node->next = 1
        // Ab node ka value 1 ho jayega
        node->val = node->next->val;

        // 🔹 Step 2:
        // Ek temporary pointer bana rahe hain jo next node ko point kare
        // Kyunki actual delete hum next node ko karne wale hain
        ListNode* temp = node->next;

        // 🔹 Step 3:
        // Current node ke next ko, next ke next se connect kar dete hain
        // Matlab beech wale (original next) node ko list se hata diya
        // node → temp → temp->next
        // ban gaya:
        // node → temp->next
        node->next = node->next->next;

        // 🔹 Step 4:
        // Ab jo node list se detach ho chuka hai usko memory se free karna zaroori hai
        // Warna memory leak ho sakta hai
        delete temp;
    }
};


// ⏱️ Complexity
// 	•	Time: O(1)
// 	•	Space: O(1)