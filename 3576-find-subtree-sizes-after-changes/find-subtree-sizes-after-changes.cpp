
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<vector<int>> modified(n);
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int node) {
            int ch = s[node] - 'a';
            int prev = last[ch];

            // Update parent in the modified tree
            if (node != 0) {
                int p = prev == -1 ? parent[node] : prev;
                modified[p].push_back(node);
            }

            last[ch] = node;

            for (int child : adj[node]) {
                dfs(child);
            }

            // Backtrack
            last[ch] = prev;
        };

        dfs(0);

        vector<int> ans(n);

        function<int(int)> calculate = [&](int node) {
            int size = 1;

            for (int child : modified[node]) {
                size += calculate(child);
            }

            ans[node] = size;
            return size;
        };

        calculate(0);

        return ans;
    }
};
