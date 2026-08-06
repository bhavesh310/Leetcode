class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        //Stores current subarray sum
        int prefix=0;
        //Main Loop
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            maxi=max(maxi,prefix);
            //If current sum becomes negative
            //reset it to 0 as it cannot contribute
            //to a larger subarray sum in future
            if(prefix<0)
            prefix=0;
        }
        return maxi;
    }
};