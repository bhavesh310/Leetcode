class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> squares;
        for (int x : nums) {
            squares.push_back(1LL * x * x);
        }

        sort(squares.begin(), squares.end());

        long long ans = 0;
        int mid = n / 2;

        // Subtract the smaller half
        for (int i = 0; i < mid; i++) {
            ans -= squares[i];
        }

        // Add the larger half
        for (int i = mid; i < n; i++) {
            ans += squares[i];
        }

        return ans;
    }
};
