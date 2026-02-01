class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {

        int n = customers.size();   // Total minutes / customers

        // 🔹 Step 1:
        // loss ka matlab: wo customers jo unhappy hain
        // agar owner grumpy hai (grumpy[i] == 1)
        // aur humne secret technique use nahi ki
        int loss = 0;

        // 🔹 Pehli window (size = minutes) ke liye
        // calculate kar rahe hain kitne customers unhappy honge
        for(int i = 0; i < minutes; i++)
        {
            // Agar owner grumpy hai, to customers unhappy honge
            if(grumpy[i] == 1) loss += customers[i];
        }

        // 🔹 maxLoss ka matlab:
        // kisi bhi window me maximum unhappy customers
        // jinko hum technique use karke happy bana sakte hain
        int maxLoss = loss;

        // 🔹 maxIdx store karega us window ka starting index
        // jaha technique use karna best rahega
        int maxIdx = 0;

        // 🔹 Sliding window pointers
        int i = 1;           // window ka start
        int j = minutes;     // window ka end

        // 🔁 Step 2: Sliding window move karna
        while(j < n)
        {
            // Current window ka loss
            int curr = loss;

            // 🔹 New element add ho raha hai window me
            if(grumpy[j] == 1) curr += customers[j];

            // 🔹 Old element remove ho raha hai window se
            if(grumpy[i - 1] == 1) curr -= customers[i - 1];

            // 🔹 Agar current window better hai
            // (zyada unhappy customers ko happy bana sakte hain)
            if(maxLoss < curr)
            {
                maxLoss = curr;
                maxIdx = i;
            }

            // 🔹 loss update kar dete hain
            loss = curr;

            // 🔹 Window ko aage slide kar dete hain
            i++;
            j++;
        }

        // 🔹 Step 3:
        // Best window (maxIdx se start) me
        // owner ko non-grumpy bana dete hain
        // matlab technique apply kar di
        for(int i = maxIdx; i < maxIdx + minutes; i++)
        {
            grumpy[i] = 0;
        }

        // 🔹 Step 4:
        // Ab final satisfied customers ka sum nikalte hain
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            // Agar owner non-grumpy hai
            // to saare customers satisfied honge
            if(grumpy[i] == 0) sum += customers[i];
        }

        // 🔹 Maximum satisfied customers return
        return sum;
    }
};



🧠 Core Idea (Interview Me Kaise Samjhayen)
	•	Normally, jab grumpy[i] == 1 hota hai → customers unhappy
	•	Owner ek baar continuous minutes ke liye grumpy nahi hota
	•	Hume wo window choose karni hai jaha maximum unhappy customers ko happy banaya ja sake

👉 Isliye:
	•	Sliding window use ki
	•	Window ke andar ka “loss” maximize kiya



⏱️ Complexity
	•	Time Complexity: O(n)
	•	Space Complexity: O(1) (in-place modification)