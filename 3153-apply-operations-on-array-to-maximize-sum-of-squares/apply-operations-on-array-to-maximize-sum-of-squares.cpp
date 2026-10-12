
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bits(32, 0);

        // Count set bits at each position
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) {
                    bits[i]++;
                }
            }
        }

        long long ans = 0;

        // Construct the largest possible number for each operation
        for (int j = 0; j < k; j++) {
            long long num = 0;

            for (int i = 0; i < 32; i++) {
                if (bits[i] > 0) {
                    num |= (1LL << i);
                    bits[i]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};
