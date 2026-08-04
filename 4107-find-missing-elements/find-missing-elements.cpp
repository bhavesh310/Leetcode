class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        if(nums.empty()) return ans;

        sort(nums.begin(), nums.end());

        int current = nums[0];
        int idx = 0;

        while(current <= nums.back()) {
            if(idx < nums.size() && nums[idx] == current) {
                idx++;
            } else {
                ans.push_back(current);
            }
            current++;
        }

        return ans;
    }
};