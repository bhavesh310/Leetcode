class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long closest = 1e18;

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                long long sum = 1LL * nums[i] + nums[l] + nums[r];

                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum < target) {
                    l++;
                } 
                else if (sum > target) {
                    r--;
                } 
                else {
                    return target; // Exact match
                }
            }
        }

        return (int)closest;
    }
};