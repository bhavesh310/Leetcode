
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute cost for every substring
        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len++) {
                int j = i + len - 1;

                // Try every proper divisor
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    // Divide substring into d groups
                    for (int r = 0; r < d; r++) {
                        int cnt = (len - 1 - r) / d + 1;

                        // Make each group a palindrome
                        for (int t = 0; t < cnt / 2; t++) {
                            int left = i + r + t * d;
                            int right = i + r + (cnt - 1 - t) * d;

                            if (s[left] != s[right]) {
                                changes++;
                            }
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // DP: dp[i][p] = minimum changes for first i
        // characters divided into p semi-palindromes
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    if (dp[j][p - 1] == INF) continue;

                    dp[i][p] = min(
                        dp[i][p],
                        dp[j][p - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
