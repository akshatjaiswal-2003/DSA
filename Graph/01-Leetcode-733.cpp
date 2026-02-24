https://leetcode.com/problems/flood-fill/description/


class Solution {
public:
    
    // Ye main function hai jo LeetCode call karega
    // image -> 2D grid (matrix)
    // sr -> starting row index
    // sc -> starting column index
    // color -> naya color jisse fill karna hai
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        // 🔥 Important Optimization:
        // Agar starting cell ka color already new color ke equal hai
        // to hume kuch karne ki zarurat hi nahi hai.
        // Agar ye check nahi lagate to infinite recursion ho sakta tha
        // kyunki hum same color ko baar baar replace karte rehte.
        if(image[sr][sc] == color) 
            return image;

        // DFS call kar rahe hain
        // initialColor ko store kar rahe hain taaki sirf wahi color replace ho
        // jo starting cell ka original color tha
        dfs(image, sr, sc, image[sr][sc], color);

        // DFS complete hone ke baad updated image return kar diya
        return image;
    }

    // Ye recursive DFS function hai
    // currRow, currCol -> current cell jisko process karna hai
    // initialColor -> starting cell ka original color (sirf isi ko replace karna hai)
    // color -> new color jisse fill karna hai
    void dfs(vector<vector<int>>& image, int currRow, int currCol, int initialColor, int color)
    {
        // Matrix ka size nikal liya
        int m = image.size();      // total rows
        int n = image[0].size();   // total columns

        // 🔥 Boundary Check (Very Important)
        // Agar current cell matrix ke bahar chala gaya
        // to turant return kar do warna runtime error aa jayega
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n)
        {
            return;
        }

        // 🔥 Color Match Check
        // Sirf unhi cells ko fill karna hai jo starting cell ke color ke equal ho
        // Agar color match nahi karta to iska matlab:
        // - ya to ye boundary cell hai
        // - ya already recolor ho chuka hai
        // - ya different region ka hissa hai
        if(image[currRow][currCol] != initialColor)
        {
            return;
        }

        // 🔥 Actual Flood Fill Step
        // Current cell ka color change kar diya
        // Ye mark bhi ho gaya visited ki tarah
        image[currRow][currCol] = color;

        // Ab 4 directions me DFS call karenge (Graph traversal jaisa)

        dfs(image, currRow-1, currCol, initialColor, color); // UP direction
        dfs(image, currRow, currCol+1, initialColor, color); // RIGHT direction
        dfs(image, currRow+1, currCol, initialColor, color); // DOWN direction
        dfs(image, currRow, currCol-1, initialColor, color); // LEFT direction
    }
};




🔥 Concept Summary (Short and Powerful)

Ye pura problem basically:

👉 Connected Component DFS traversal on grid

Hum:
	1.	Starting cell se begin karte hain
	2.	Sirf same color wale adjacent cells visit karte hain
	3.	Unka color change kar dete hain
	4.	Recursively 4 directions me spread karte hain

⸻

⏱ Time Complexity

O(m × n) → Har cell maximum ek baar visit hoga

🧠 Space Complexity

O(m × n) → Worst case recursion stack