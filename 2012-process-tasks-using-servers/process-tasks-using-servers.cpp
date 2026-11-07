
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // {weight, server_index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > available;

        // {free_time, weight, server_index}
        using T = tuple<long long, int, int>;

        priority_queue<T, vector<T>, greater<T>> busy;

        int n = servers.size();
        int m = tasks.size();

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        for (int i = 0; i < m; i++) {

            // Current task arrives at time i.
            time = max(time, (long long)i);

            // Release servers that have finished.
            while (!busy.empty() &&
                   get<0>(busy.top()) <= time) {

                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If all servers are busy, wait for the
            // earliest server to become free.
            if (available.empty()) {

                time = get<0>(busy.top());

                while (!busy.empty() &&
                       get<0>(busy.top()) <= time) {

                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Choose the server with minimum weight,
            // then minimum index.
            auto [weight, index] = available.top();
            available.pop();

            ans[i] = index;

            // Schedule the task.
            busy.push({
                time + tasks[i],
                weight,
                index
            });
        }

        return ans;
    }
};
