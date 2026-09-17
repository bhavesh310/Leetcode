class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& candidates, int target, int start,
               vector<int>& current) {
        
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            
            // If current number is greater than target, skip it
            if (candidates[i] > target)
                break;
            
            current.push_back(candidates[i]);
            
            // Same i because we can reuse the same candidate
            solve(candidates, target - candidates[i], i, current);
            
            current.pop_back(); // backtrack
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> current;
        solve(candidates, target, 0, current);
        
        return ans;
    }
};