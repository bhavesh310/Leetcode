class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        int zeroCount = 0;

        for (int x : nums) {
            totalXor ^= x;

            if (x == 0) {
                zeroCount++;
            }
        }

        // Entire array has non-zero XOR
        if (totalXor != 0) {
            return n;
        }

        // Every element is zero
        if (zeroCount == n) {
            return 0;
        }

        // XOR is zero, but at least one non-zero exists
        return n - 1;
    }
};