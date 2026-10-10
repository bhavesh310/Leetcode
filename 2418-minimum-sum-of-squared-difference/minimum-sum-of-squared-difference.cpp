class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> diff;
        long long sum = 0, mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            sum += d;
            mx = max(mx, d);
        }

        if (sum <= k) return 0;

        long long low = 0, high = mx;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long ops = 0;

            for (long long d : diff) {
                if (d > mid) ops += d - mid;
                if (ops > k) break;
            }

            if (ops <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0, used = 0;

        for (long long d : diff) {
            if (d > low) {
                used += d - low;
                d = low;
            }
            ans += d * d;
        }

        long long remaining = k - used;

        // Reduce 'remaining' differences from low to low - 1.
        // Each reduction saves low^2 - (low - 1)^2.
        ans -= remaining * (2 * low - 1);

        return ans;
    }
};