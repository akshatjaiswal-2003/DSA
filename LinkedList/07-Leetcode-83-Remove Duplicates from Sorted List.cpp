class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // 🔹 Base case:
        // Agar list empty hai ya sirf ek node hai
        // to duplicates possible hi nahi
        if(head == NULL || head->next == NULL)
            return head;

        // 🔹 Pointer 'a' hamesha last unique node ko point karega
        ListNode* a = head;

        // 🔹 Pointer 'b' aage ke nodes ko check karega
        // ki same value repeat ho rahi hai ya nahi
        ListNode* b = head->next;

        // 🔁 Jab tak b NULL nahi hota, tab tak list traverse karte rahenge
        while(b != NULL)
        {
            // 🔁 Jab tak:
            // 1️⃣ b NULL na ho
            // 2️⃣ a aur b ke values same ho
            // tab tak b ko aage badhate rahenge
            // Isse saare duplicate nodes skip ho jayenge
            while(b != NULL && a->val == b->val)
            {
                b = b->next;
            }

            // 🔹 Ab b ya to NULL hai
            // ya kisi naye (unique) value par point kar raha hai
            // To a->next ko directly b se connect kar dete hain
            a->next = b;

            // 🔹 Ab a ko bhi next unique node par le jaate hain
            a = b;

            // 🔹 Agar b NULL nahi hai
            // to b ko ek step aage badha dete hain
            if(b != NULL)
                b = b->next;
        }

        // 🔹 Modified list ka head return kar dete hain
        return head;
    }
};



// 🧠 Important Observations (Interview Me Bolne Layak 🔑)
// 	•	Ye solution sirf sorted linked list ke liye kaam karta hai
// 	•	Duplicates hamesha continuous honge
// 	•	Extra memory use nahi hui → in-place modification



// ⏱️ Complexity
// 	•	Time Complexity: O(n)
// 	•	Space Complexity: O(1)
// 	•	Single traversal, no extra data structure ✔️



//  Interview One-Liner

// “Since the list is sorted, I skip consecutive nodes with the same value and directly connect the last unique node to the next unique node.”