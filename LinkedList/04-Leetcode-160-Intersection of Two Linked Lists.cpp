class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // 🔹 Step 1: Dono linked lists ki length nikalenge
        int lenA = 0;
        int lenB = 0;

        // Temporary pointers jo lists traverse karenge
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // 🔁 List A ki length calculate kar rahe hain
        while(tempA != NULL)
        {
            lenA++;                 // Har node ke liye length increment
            tempA = tempA->next;   // Next node par move
        }

        // 🔁 List B ki length calculate kar rahe hain
        while(tempB != NULL)
        {
            lenB++;                 // Har node ke liye length increment
            tempB = tempB->next;   // Next node par move
        }

        // 🔹 Step 2:
        // Dono lists ki length ka absolute difference nikal rahe hain
        // Ye difference batata hai ki ek list dusri se kitni badi hai
        int diff = abs(lenA - lenB);

        // 🔹 Step 3:
        // Temp pointers ko wapas head par le aate hain
        tempA = headA;
        tempB = headB;

        // 🔹 Step 4:
        // Jo list badi hai, uske pointer ko 'diff' steps aage badha dete hain
        // Taaki dono pointers same distance par aa jayein
        // Intersection check ke liye alignment zaroori hai
        if(lenA > lenB)
        {
            // List A badi hai
            while(diff--)
            {
                tempA = tempA->next;
            }
        }
        else
        {
            // List B badi hai
            while(diff--)
            {
                tempB = tempB->next;
            }
        }

        // 🔹 Step 5:
        // Ab dono pointers ko saath-saath move karte hain
        // Jab tak dono same node ko point na karne lagen
        // Agar intersection hoga to pointer equality milegi
        while(tempA != tempB)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        // 🔹 Step 6:
        // Yaha do cases possible hain:
        // 1️⃣ tempA == tempB != NULL → intersection node mil gaya
        // 2️⃣ tempA == tempB == NULL → intersection exist hi nahi karta
        return tempA;
    }
};

// 🧠 Key Concepts (Interview Me Bolne Layak 🔑)
// 	•	Intersection ka matlab value same hona nahi
// 	•	Intersection ka matlab same memory address / same node
// 	•	Isliye hum tempA != tempB compare karte hain, val compare nahi karte


// ⏱️ Complexity
// 	•	Time Complexity: O(n + m)
// 	•	Space Complexity: O(1)
// 	•	No extra data structure used ✔️