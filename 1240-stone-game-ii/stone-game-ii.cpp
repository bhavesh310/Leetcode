class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int i, int M) {
        // All piles have been taken
        if (i == n)
            return 0;

        // Already calculated
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Try taking X piles
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            // Stones remaining after taking X piles
            int remaining = suffix[i];

            // Opponent gets dp[i + X][newM]
            int opponent = solve(i + X, max(M, X));

            // Current player gets remaining - opponent
            ans = max(ans, remaining - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // suffix[i] = sum of piles[i ... n-1]
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // M can be at most n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};
