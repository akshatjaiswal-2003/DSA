class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {

        // 🔹 Do pointers bana rahe hain: slow aur fast
        // Dono initially head par point kar rahe hain
        ListNode* slow = head;
        ListNode* fast = head;

        // 🔹 Step 1: Fast pointer ko n steps aage le jana
        // Isse slow aur fast ke beech me exactly n nodes ka gap ban jayega
        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // 🔹 Step 2: Special edge case
        // Agar fast NULL ho gaya iska matlab:
        // - n == length of linked list
        // - Matlab hume head node delete karna hai
        // Example: [1->2->3], n = 3
        if(fast == NULL) return head->next;

        // 🔹 Step 3:
        // Ab slow aur fast dono ko ek-ek step move karte hain
        // Jab fast last node par pahunch jayega
        // Tab slow exactly us node ke just pehle hoga
        // jise delete karna hai
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // 🔹 Step 4:
        // Ab slow->next wahi node hai jise delete karna hai
        // To hum slow ko slow->next->next se connect kar dete hain
        slow->next = slow->next->next;

        // 🔹 Updated linked list ka head return kar dete hain
        return head;
    }
};


// ⏱️ Complexity (Interview must bolna)
// 	•	Time Complexity: O(n)
// 	•	Space Complexity: O(1)
// 	•	Single traversal, no extra memory 👍