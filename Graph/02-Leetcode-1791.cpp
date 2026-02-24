https://leetcode.com/problems/find-center-of-star-graph/description/




class Solution {
public:

    // Ye function star graph ka center node find karega.
    // edges -> given hai list of edges, jaha har edge ek vector hai size 2 ka [u, v]
    // Return -> center node ka value
    
    int findCenter(vector<vector<int>>& edges) {
        
        // 🔥 Degree store karne ke liye unordered_map use kiya
        // key   -> node number
        // value -> us node ka degree (kitni edges us se connected hai)
        unordered_map<int, int> degree;

        // 🔥 Har edge ko traverse kar rahe hain
        // it ek vector hoga jisme 2 elements honge [u, v]
        for(auto &it : edges)
        {
            // Edge ke dono nodes nikal liye
            int u = it[0];  // first node
            int v = it[1];  // second node

            // 🔥 Undirected graph hai
            // Isliye dono nodes ka degree increment hoga

            degree[u]++;  // u ke saath ek aur connection add ho gaya
            degree[v]++;  // v ke saath ek aur connection add ho gaya
        }

        // 🔥 Ab hum check karenge kaunsa node center hai
        // Star graph me center node ka degree = total number of edges
        // Kyunki:
        // Agar n nodes hain
        // To edges = n - 1
        // Aur center node sabse connected hoga (n - 1 edges)

        for(auto &it : degree)
        {
            // it.first  -> node
            // it.second -> degree of that node

            // Agar kisi node ka degree total edges ke equal hai
            // To wahi center hoga
            if(it.second == edges.size()) 
                return it.first;
        }

        // Agar kisi reason se center nahi mila (theoretically nahi hoga)
        // To -1 return kar rahe hain
        return -1;
    }
};



🔥 Concept Deep Understanding

💡 Star Graph Property:

Agar:
	•	n nodes hain
	•	edges = n - 1

To center node ka degree = n - 1

Aur baaki sab nodes ka degree = 1

Example:

edges = [[1,2],[2,3],[4,2]]

Degree:

1 → 1
2 → 3  ✅
3 → 1
4 → 1

Edges.size() = 3

Degree == 3 → Node 2 is center

⸻

⏱ Time Complexity
	•	Loop 1 → O(n)
	•	Loop 2 → O(n)

Total = O(n)

⸻

🧠 Space Complexity
	•	unordered_map me max n entries

Space = O(n)




---------------------- O(1) optimized solution------------------------


class Solution {
public:

    // 🔥 Optimized O(1) Approach
    // Star graph ki ek special property hoti hai:
    // Center node har edge me connected hota hai.
    // Iska matlab:
    // Pehli 2 edges me jo common node hoga wahi center hoga.
    
    int findCenter(vector<vector<int>>& edges) {
        
        // edges[0] -> first edge
        // edges[1] -> second edge
        
        // First edge ke nodes
        int a = edges[0][0];
        int b = edges[0][1];
        
        // Second edge ke nodes
        int c = edges[1][0];
        int d = edges[1][1];

        // 🔥 Ab logic simple hai:
        // Center node woh hoga jo dono edges me common ho.
        
        // Agar 'a' second edge me exist karta hai
        // to 'a' hi center hai
        if(a == c || a == d)
            return a;

        // Agar 'a' common nahi hai
        // to definitely 'b' hi common hoga
        // (Star graph property ke according)
        return b;
    }
};




⏱ Time Complexity

Sirf:
	•	4 variable access
	•	2 comparisons

👉 O(1) Constant Time

⸻

🧠 Space Complexity

👉 O(1) (No extra space used)