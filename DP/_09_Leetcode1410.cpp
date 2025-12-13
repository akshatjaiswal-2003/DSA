// -------------------------------------------------------------
// Approach-1: Recursion + Memoization (Top-Down DP)
//
// Problem Summary:
// Aapko array banana hai of length N
// Jisme:
//   - Har element ki value [1...M] ke beech hogi
//   - "Search Cost" exactly K hona chahiye
//
// Search Cost ka matlab:
// Jab bhi hum array left → right scan karte hain
// aur koi element current maximum se bada milta hai,
// tab searchCost +1 hota hai
//
// Example:
// arr = [2, 1, 4, 3]
// scan karte time:
// max = 2  -> cost = 1
// 1 < 2    -> cost unchanged
// 4 > 2    -> cost = 2
// 3 < 4    -> cost unchanged
//
// Goal:
// Total number of such arrays count karna hai
// Answer modulo 1e9+7
//
// Time Complexity: O(N * M * K)
// Space Complexity: O(N * K * M)
// -------------------------------------------------------------
class Solution {
public:

    // ---------------------------------------------------------
    // Global variables to avoid passing again & again
    // ---------------------------------------------------------
    int N, M, K;

    // Modulo value
    int MOD = 1e9 + 7;

    // ---------------------------------------------------------
    // DP Memo Table
    // t[idx][searchCost][maxSoFar]
    //
    // idx        -> current index in array
    // searchCost -> ab tak kitni baar new max mila
    // maxSoFar   -> ab tak ka maximum element
    // ---------------------------------------------------------
    int t[51][51][101];

    // ---------------------------------------------------------
    // Recursive function
    // ---------------------------------------------------------
    int solve(int idx, int searchCost, int maxSoFar) {

        // -----------------------------------------------------
        // Base Case:
        // Agar poora array fill ho chuka hai
        // -----------------------------------------------------
        if (idx == N) {

            // -------------------------------------------------
            // Agar searchCost exactly K hai
            // toh yeh ek valid array hai
            // -------------------------------------------------
            if (searchCost == K)
                return 1;

            // -------------------------------------------------
            // Warna invalid configuration
            // -------------------------------------------------
            return 0;
        }

        // -----------------------------------------------------
        // Memoization check
        // Agar state pehle calculate ho chuki hai
        // -----------------------------------------------------
        if (t[idx][searchCost][maxSoFar] != -1) {
            return t[idx][searchCost][maxSoFar];
        }

        int result = 0;

        // -----------------------------------------------------
        // Try all possible values from 1 to M
        // Har position par hum 1..M me se koi bhi value rakh sakte hain
        // -----------------------------------------------------
        for (int i = 1; i <= M; i++) {

            // -------------------------------------------------
            // Case-1: Agar current value i,
            // maxSoFar se bada hai
            // -------------------------------------------------
            if (i > maxSoFar) {

                // -------------------------------------------------
                // New maximum mila:
                // searchCost + 1 hoga
                // maxSoFar update ho jaayega
                // -------------------------------------------------
                result = (result + solve(
                                    idx + 1,
                                    searchCost + 1,
                                    i
                                )) % MOD;

            } 
            // -------------------------------------------------
            // Case-2: Agar i <= maxSoFar
            // -------------------------------------------------
            else {

                // -------------------------------------------------
                // No new maximum
                // searchCost same rahega
                // maxSoFar unchanged
                // -------------------------------------------------
                result = (result + solve(
                                    idx + 1,
                                    searchCost,
                                    maxSoFar
                                )) % MOD;
            }
        }

        // -----------------------------------------------------
        // Result ko memo table me store karte hain
        // -----------------------------------------------------
        return t[idx][searchCost][maxSoFar] = result % MOD;
    }

    // ---------------------------------------------------------
    // Driver function
    // ---------------------------------------------------------
    int numOfArrays(int n, int m, int k) {

        // -----------------------------------------------------
        // Global variables initialize
        // -----------------------------------------------------
        N = n;
        M = m;
        K = k;

        // -----------------------------------------------------
        // DP table ko -1 se initialize
        // -----------------------------------------------------
        memset(t, -1, sizeof(t));

        // -----------------------------------------------------
        // Start recursion from:
        // idx = 0
        // searchCost = 0
        // maxSoFar = 0 (initially kuch bhi select nahi hua)
        // -----------------------------------------------------
        return solve(0, 0, 0);
    }
};



// -------------------------------------------------------------
// Approach-2: Bottom-Up Dynamic Programming
//
// Problem Recap:
// Hume length = N ka array banana hai
//   - Har element [1..M] ke beech
//   - Search Cost (new maximum milne ki count) exactly K hona chahiye
//
// Search Cost ka matlab:
// Jab left se right traverse karte hue
// koi element current max se bada milta hai,
// tab searchCost +1 hota hai
//
// Time Complexity: O(N * K * M^2)
// Space Complexity: O(N * K * M)
// -------------------------------------------------------------
class Solution {
public:

    /*
        DP Definition:

        ways[i][j][k] =
        number of ways to construct an array of:
            - length = i
            - maximum element = j
            - search cost = k
    */
    long long ways[51][101][51];

    // Modulo
    const int MOD = 1e9 + 7;
    
    int numOfArrays(int n, int m, int k) {

        // -----------------------------------------------------
        // BASE CASE INITIALIZATION
        //
        // Length = 1
        // Agar array me sirf ek hi element hai:
        //   [j]
        // then:
        //   max = j
        //   searchCost = 1 (first element hamesha new max hota hai)
        //
        // Isliye:
        // ways[1][j][1] = 1
        // -----------------------------------------------------
        for (int j = 1; j <= m; j++) {
            ways[1][j][1] = 1;
        }
        
        // -----------------------------------------------------
        // Bottom-Up DP filling
        // -----------------------------------------------------
        for (int a = 1; a <= n; a++) {        // a -> current array length
            for (int b = 1; b <= m; b++) {    // b -> current maximum value
                for (int c = 1; c <= k; c++) { // c -> current search cost

                    long long s = 0;

                    // -------------------------------------------------
                    // CASE-1:
                    // Last element jo append kar rahe hain
                    // woh range [1 .. b] me ho
                    //
                    // Matlab:
                    // - New maximum nahi banega
                    // - searchCost same rahega
                    // - max bhi b hi rahega
                    //
                    // Total choices = b
                    //
                    // Isliye:
                    // ways[a-1][b][c] * b
                    // -------------------------------------------------
                    s = (s + b * ways[a - 1][b][c]) % MOD;
                    
                    // -------------------------------------------------
                    // CASE-2:
                    // Last element = b
                    // Aur pehle max < b tha
                    //
                    // Matlab:
                    // - Naya maximum mil gaya
                    // - searchCost +1 hua
                    //
                    // Pehle ka max = x, jaha x < b
                    // -------------------------------------------------
                    for (int x = 1; x < b; x++) {
                        s = (s + ways[a - 1][x][c - 1]) % MOD;
                    }
					
                    // -------------------------------------------------
                    // Final answer store karte hain
                    // -------------------------------------------------
                    ways[a][b][c] = (ways[a][b][c] + s) % MOD;
                }
            }
        }

        // -----------------------------------------------------
        // Final Answer:
        // Length = n
        // Search Cost = k
        // Max kuch bhi ho sakta hai (1..m)
        // -----------------------------------------------------
        long long ans = 0;
        for (int j = 1; j <= m; j++) {
            ans = (ans + ways[n][j][k]) % MOD;
        }
        
        return int(ans);
    }
};
