class Solution {
public:
    bool judgeSquareSum(int c) {

        // a smallest possible value se start karega
        long long a = 0;

        // b largest possible value se start karega
        long long b = sqrt(c);

        // Jab tak a <= b
        while(a <= b)
        {
            long long sum = a*a + b*b;

            // Agar exact match mil gaya
            if(sum == c)
                return true;

            // Agar sum chhota hai, a badhao
            else if(sum < c)
                a++;

            // Agar sum bada hai, b ghatao
            else
                b--;
        }

        // Agar koi pair nahi mila
        return false;
    }
};


⏱ Time & Space Complexity
	•	Time Complexity: O(√c)
	•	Space Complexity: O(1)



🎤 INTERVIEW ME KAISE EXPLAIN KARNA

“I used a two-pointer approach where one pointer starts from 0 and the other from sqrt(c).
Depending on whether the sum of squares is smaller or larger than c, I adjust the pointers.”