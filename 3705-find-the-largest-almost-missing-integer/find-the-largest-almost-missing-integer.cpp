class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();

        if(k==1){
            unordered_map<int,int>cnt;
            for(int x:nums)
            cnt[x]++;

            int ans=-1;
            for(auto &[x, f]:cnt)
            if(f==1)
            ans=max(ans,x);

            return ans;
        }

        if(k==n)
        return *max_element(nums.begin(),nums.end());

        int ans=-1;

        if(count(nums.begin(),nums.end(),nums.front())==1)
        ans=max(ans,nums.front());

        if(count(nums.begin(),nums.end(),nums.back())==1)
        ans=max(ans,nums.back());

        return ans;
    }
};