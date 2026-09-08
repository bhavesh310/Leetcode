class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        // Numbers from 1,000 onwards contain at least 1 comma
        if (n >= 1000)
            ans += n - 999;

        // Numbers from 1,000,000 onwards contain 2 commas
        // (Not needed for n <= 1e5, but useful for generalization)
        if (n >= 1000000)
            ans += n - 999999;

        return ans;
    }
};