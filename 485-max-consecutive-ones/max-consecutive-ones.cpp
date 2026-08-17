class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,ans=0;
        for(int r=0;r<nums.size();r++){
            //Next possible streak for 1's start after r
            if(nums[r]==0){
                l=r+1;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};