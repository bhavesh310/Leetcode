class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);
            int numMod = num % k;

            // Subarray consisting of just this element
            newDp[numMod] += 1;

            // Extend every subarray ending at the previous index
            for (int r = 0; r < k; ++r) {
                if (dp[r] == 0) continue;
                int newMod = (int)((1LL * r * numMod) % k);
                newDp[newMod] += dp[r];
            }

            for (int r = 0; r < k; ++r) ans[r] += newDp[r];
            dp = newDp;
        }

        return ans;
    }
};