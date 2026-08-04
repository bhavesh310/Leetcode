class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        //Base condition
        if(nums.empty()) 
        return ans;
        //Sort array
        sort(nums.begin(),nums.end());

        int current=nums[0];
        int idx=0;
        //Main Loop
        while(current<=nums.back()){
            if(idx<nums.size() && nums[idx]==current)
            idx++;
            else 
            ans.push_back(current);
            
            current++;
        }

        return ans;
    }
};