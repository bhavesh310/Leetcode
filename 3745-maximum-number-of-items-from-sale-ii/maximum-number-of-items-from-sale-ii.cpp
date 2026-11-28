class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Step 1: Find maximum factor and minimum price
        int maxFactor = 0;
        int minPrice = INT_MAX;

        vector<int> freq(n + 1, 0);

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            freq[factor]++;
            maxFactor = max(maxFactor, factor);
            minPrice = min(minPrice, price);
        }

        // Step 2: Count items whose factors are multiples
        vector<int> cnt = freq;

        for (int i = maxFactor; i >= 1; i--) {
            for (int j = i * 2; j <= maxFactor; j += i) {
                cnt[i] += freq[j];
            }
        }

        // Step 3: Sort items by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Step 4: Greedily purchase items with free-item benefits
        long long ans = 0;
        long long remaining = budget;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            // Two cheapest normal items are better
            if (2LL * price >= 2LL * minPrice * 2) {
                break;
            }

            // Number of other item types unlocked
            int gain = cnt[factor] - 1;

            if (gain <= 0) continue;

            // Each purchase gives 2 total items
            long long take = min((long long)gain,
                                 remaining / price);

            ans += 2LL * take;
            remaining -= take * price;
        }

        // Step 5: Spend remaining budget on cheapest item
        ans += remaining / minPrice;

        return ans;
    }
};