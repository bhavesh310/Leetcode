class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> dp(budget + 1, 0);
        int minPrice = INT_MAX;

        // Step 1: Find the minimum price
        for (auto& item : items) {
            minPrice = min(minPrice, item[1]);
        }

        // Step 2: 0/1 Knapsack
        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int reward = 0;

            // Count items received (including the purchased item)
            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0) {
                    reward++;
                }
            }

            // Buy the first copy of this item type
            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + reward);
            }
        }

        // Step 3: Spend remaining budget on cheapest items
        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            int remaining = budget - b;

            ans = max(ans, dp[b] + remaining / minPrice);
        }

        return ans;
    }
};