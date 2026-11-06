
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();

        // Store original query indices
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        // Sort logs by timestamp
        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        // Sort queries by time
        sort(q.begin(), q.end());

        vector<int> ans(m);
        unordered_map<int, int> freq;

        int left = 0, right = 0;
        int active = 0;

        for (auto& [time, idx] : q) {

            // Add servers with timestamp <= time
            while (right < logs.size() && logs[right][1] <= time) {
                int server = logs[right][0];

                if (freq[server] == 0)
                    active++;

                freq[server]++;
                right++;
            }

            // Remove logs with timestamp < time - x
            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0)
                    active--;

                left++;
            }

            // Servers with zero requests
            ans[idx] = n - active;
        }

        return ans;
    }
};
