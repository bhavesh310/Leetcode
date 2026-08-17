class Solution {
public:
    // dp[i][j] stores the maximum score difference
    // current player can achieve over the opponent
    // considering only nums[i...j]
    int dp[21][21];

    int solve(vector<int>& nums, int i, int j) {

        // If only one element is left,
        // current player picks it.
        if (i == j)
            return nums[i];

        // Return already computed result
        if (dp[i][j] != -1)
            return dp[i][j];

        // Option 1:
        // Pick the left element.
        // Opponent will then play optimally,
        // so subtract opponent's best score difference.
        int pickLeft = nums[i] - solve(nums, i + 1, j);

        // Option 2:
        // Pick the right element.
        int pickRight = nums[j] - solve(nums, i, j - 1);

        // Choose the better option.
        return dp[i][j] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {

        // Initialize DP array with -1
        memset(dp, -1, sizeof(dp));

        // If score difference >= 0,
        // Player 1 can win or tie.
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};