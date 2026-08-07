class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        int first=-1,second=-1;
        //Main Loop
        int st=0,end=nums.size()-1;
        //First occurence of element
        while(st<=end){
            int mid=st+(end-st)/2;

            if(nums[mid]==target){
                first=mid;
                end=mid-1;
            }else if(nums[mid]<target)
            st=mid+1;
            else
            end=mid-1;
        }
        //Last occurence of element
        st=0,end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;

            if(nums[mid]==target){
                second=mid;
                st=mid+1;
            }else if(nums[mid]<target)
            st=mid+1;
            else
            end=mid-1;
        }
        ans[0]=first;
        ans[1]=second;
        return ans;
    }
};