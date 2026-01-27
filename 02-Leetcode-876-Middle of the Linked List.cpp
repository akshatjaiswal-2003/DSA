class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // 🔹 Slow pointer ek-ek step move karega
        // 🔹 Fast pointer do-do steps move karega
        // Dono ko initially head par rakha gaya
        ListNode* slow = head;
        ListNode* fast = head;

        // 🔁 Loop tab tak chalega jab:
        // 1. fast NULL na ho
        // 2. fast ka next NULL na ho
        // Ye condition isliye zaroori hai taaki
        // fast->next->next karte waqt segmentation fault na aaye
        while (fast != NULL && fast->next != NULL)
        {
            // Slow pointer ko 1 step aage badha rahe hain
            slow = slow->next;

            // Fast pointer ko 2 steps aage badha rahe hain
            fast = fast->next->next;
        }

        // 🧠 Jab fast pointer list ke end tak pahunch jata hai
        // tab slow pointer exactly middle node par hota hai

        // 🔹 Agar nodes odd hain → exact middle return hoga
        // 🔹 Agar nodes even hain → second middle node return hoga
        // (LeetCode ke question ki requirement ke according)

        return slow;
    }
};



// 🔑 Important Concepts (Interview Gold ✨)
// 	•	Is technique ko Tortoise & Hare Algorithm bolte hain
// 	•	Singly Linked List me bina length calculate kiye
// middle element nikalne ka best tareeka