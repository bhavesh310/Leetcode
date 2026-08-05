class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);

        vector<int> vis(n, 0);

        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for (int v : graph[u]) {
                if (!vis[v]) dfs(v);
            }
        };

        // Mark suspicious methods
        dfs(k);

        // Check if any outside node calls a suspicious node
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!vis[i]) ans.push_back(i);

        return ans;
    }
};