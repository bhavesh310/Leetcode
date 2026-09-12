class Solution {
public:
    struct State {
        long long val = 0;
        vector<int> ids;
    };

    bool better(const State& a, const State& b) {
        if (a.val != b.val)
            return a.val > b.val;

        return lexicographical_compare(
            a.ids.begin(), a.ids.end(),
            b.ids.begin(), b.ids.end()
        );
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store original index
        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        vector<int> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = intervals[i][0];

        // First interval whose start > current end
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                intervals[i][1]
            ) - starts.begin();
        }

        // dp[i][k] = best answer using intervals[i...]
        // with at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Option 1: skip
                State skip = dp[i + 1][k];

                // Option 2: take
                State take;
                take.val =
                    intervals[i][2] + dp[nxt[i]][k - 1].val;

                take.ids = dp[nxt[i]][k - 1].ids;
                take.ids.push_back(intervals[i][3]);

                // Keep indices sorted because final answer
                // must be lexicographically compared.
                sort(take.ids.begin(), take.ids.end());

                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].ids;
    }
};