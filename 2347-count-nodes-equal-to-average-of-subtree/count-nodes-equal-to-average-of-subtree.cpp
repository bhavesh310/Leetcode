class Solution {
public:
    int ans = 0;

    // Returns {sum of subtree, number of nodes}
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        // Get information from left and right subtrees
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Total sum and number of nodes in current subtree
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Check if current node equals subtree average
        if (root->val == sum / count)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};