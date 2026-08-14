class Solution {
public:
    vector<vector<int>>ans;
    void subset(vector<int>nums,int index,int n,vector<int>&temp){
        //Base condition
        if(index==n){
            ans.push_back(temp);
            return;
        }
        //Not included
        subset(nums,index+1,n,temp);
        //Included
        temp.push_back(nums[index]);
        subset(nums,index+1,n,temp);
        //Work done with value then pop it from temp and return
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        subset(nums,0,nums.size(),temp);
        return ans;
    }
};