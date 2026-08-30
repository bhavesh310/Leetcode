class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;

            if (nums[i] > nums[mx])
                mx = i;
        }

        int leftIdx = min(mn, mx);
        int rightIdx = max(mn, mx);

        // Remove both from the left
        int fromLeft = rightIdx + 1;

        // Remove both from the right
        int fromRight = n - leftIdx;

        // Remove one from left and the other from right
        int fromBoth = (leftIdx + 1) + (n - rightIdx);

        return min({fromLeft, fromRight, fromBoth});
    }
};