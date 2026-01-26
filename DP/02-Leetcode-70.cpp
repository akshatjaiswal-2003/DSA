class Solution {
public:
    int climbStairs(int n) 
    {
        // Base cases:
        // If n is 0 or 1, ways = n itself
        if(n <= 2) return n;

        // a = ways to reach (i - 2)
        // b = ways to reach (i - 1)
        int a = 1; // ways for stair 1
        int b = 2; // ways for stair 2
        int c;     // will store ways for current stair i

        // Calculate ways for all stairs from 3 to n
        for(int i = 3; i <= n; i++) 
        {
            c = a + b; // current ways = sum of previous two
            a = b;     // move forward (i-2) becomes (i-1)
            b = c;     // current becomes previous for next iteration
        }

        // b now contains the answer for n stairs
        return b;
    }
};


### **Time Complexity:** `O(n)`  
### **Space Complexity:** `O(1)`