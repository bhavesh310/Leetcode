class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size(),half=n/2;

        long long total=0;
        
        for(int x:nums)
            total+=x;

        long long cur=0;
        for(int i=0;i<half;i++)
        cur+=nums[i];

        int ans=0;

        for(int i=0;i<n;i++){
            if(cur>total-cur)
            ans++;

            cur-=nums[i];
            cur+=nums[(i+half)%n];
        }

        return ans;
    }
};