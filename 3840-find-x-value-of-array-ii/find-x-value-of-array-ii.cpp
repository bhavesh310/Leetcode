class Solution {
    struct Node {
        int prod = 1;
        int cnt[5] = {0, 0, 0, 0, 0};
    };

    int k;
    vector<Node> tree;

    Node mergeNode(const Node& left, const Node& right) {
        Node res;

        // Product of the complete combined segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside the left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] = left.cnt[r];
        }

        // Prefixes that start in the left segment
        // and continue into the right segment
        for (int r = 0; r < k; r++) {
            int newRem = (left.prod * r) % k;
            res.cnt[newRem] += right.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int v = nums[l] % k;

            tree[node].prod = v;
            tree[node].cnt[v] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = mergeNode(tree[node * 2],
                               tree[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int pos, int value) {

        if (l == r) {
            value %= k;

            tree[node].prod = value;

            for (int i = 0; i < k; i++) {
                tree[node].cnt[i] = 0;
            }

            tree[node].cnt[value] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(node * 2, l, mid, pos, value);
        } else {
            update(node * 2 + 1, mid + 1, r, pos, value);
        }

        tree[node] = mergeNode(tree[node * 2],
                               tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        // Completely inside query range
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Completely in left child
        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        // Completely in right child
        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        // Query overlaps both children
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums,
                            int k,
                            vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        // Build segment tree
        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(1, 0, n - 1, index, value);

            // Consider nums[start ... n-1]
            Node res = query(1, 0, n - 1,
                             start, n - 1);

            // Number of prefixes with product % k == x
            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};