class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // 🔹 Flag use kar rahe hain ye check karne ke liye
        // ki cycle mili hai ya nahi
        bool flag = false;

        // 🔹 Do pointers banate hain:
        // slow → ek-ek step move karega
        // fast → do-do steps move karega
        // Dono initially head par point kar rahe hain
        ListNode* slow = head;
        ListNode* fast = head;

        // 🔁 Step 1: Cycle detect karna (Floyd’s Algorithm)
        // Loop tab tak chalega jab:
        // 1️⃣ fast NULL na ho
        // 2️⃣ fast ka next NULL na ho
        while(fast && fast->next)
        {
            // Slow ko 1 step aage badha rahe hain
            slow = slow->next;

            // Fast ko 2 steps aage badha rahe hain
            fast = fast->next->next;

            // 🔹 Agar slow aur fast same node par mil gaye
            // iska matlab linked list me cycle exist karti hai
            if(slow == fast)
            {
                flag = true;   // Cycle mil gayi
                break;         // Loop se bahar aa jao
            }
        }

        // 🔁 Step 2: Agar cycle mili ho tab
        if(flag == true)
        {
            // 🔹 Ek naya pointer temp banate hain
            // jo head se start karega
            ListNode* temp = head;

            // 🔹 Ab slow (meeting point) aur temp (head)
            // dono ko ek-ek step move karte hain
            // Jaha dono milenge wahi cycle ka starting node hoga
            while(slow != temp)
            {
                slow = slow->next;
                temp = temp->next;
            }

            // 🔹 Ye node cycle ka starting point hai
            return slow;
        }
        else
        {
            // 🔹 Agar cycle hi exist nahi karti
            // to NULL return kar dete hain
            return NULL;
        }
    }
};


// ⏱️ Complexity
// 	•	Time Complexity: O(n)
// 	•	Space Complexity: O(1)
// 	•	No extra data structure used 👍


// Interview One-Liner Answer

// “First I detect the cycle using Floyd’s algorithm, then I move one pointer from head and one from the meeting point; where they meet is the start of the cycle.”