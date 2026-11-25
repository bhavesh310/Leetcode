
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), newRank(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        // Build Suffix Array
        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            });

            newRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                pair<int, int> x = {
                    rank[a],
                    (a + k < n) ? rank[a + k] : -1
                };

                pair<int, int> y = {
                    rank[b],
                    (b + k < n) ? rank[b + k] : -1
                };

                newRank[b] = newRank[a] + (x != y);
            }

            rank = newRank;
        }

        // Inverse suffix array
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        // Kasai's LCP algorithm
        vector<int> lcp(n, 0);
        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        // Find smallest unique subarray
        int ans = n;

        for (int r = 0; r < n; r++) {
            int longest = lcp[r];

            if (r + 1 < n) {
                longest = max(longest, lcp[r + 1]);
            }

            int remaining = n - sa[r];

            // Required length must fit in the suffix
            if (longest < remaining) {
                ans = min(ans, longest + 1);
            }
        }

        return ans;
    }
};
