
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        vector<long long> cost;

        // Maintain the two halves of the sliding window
        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < high.size()) {
                int val = *high.begin();
                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        // Calculate cost for every window of size x
        for (int i = 0; i < n; i++) {

            int val = nums[i];

            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            // Remove element outside the window
            if (i >= x) {
                int out = nums[i - x];

                auto it = low.find(out);

                if (it != low.end()) {
                    low.erase(it);
                    sumLow -= out;
                } else {
                    it = high.find(out);
                    high.erase(it);
                    sumHigh -= out;
                }
            }

            balance();

            // Calculate minimum operations
            if (i >= x - 1) {
                long long median = *low.rbegin();

                long long operations =
                    median * low.size() - sumLow +
                    sumHigh - median * high.size();

                cost.push_back(operations);
            }
        }

        // DP: minimum cost to select j non-overlapping windows
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Select a window ending at i
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
