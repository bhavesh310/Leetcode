class Solution {
public:
    void mergeSort(vector<int>&nums,int st,int end){
        if(st>=end)
        return ;
        //Find mid
        int mid=st+(end-st)/2;
        //Left part
        mergeSort(nums,st,mid);
        //Right part
        mergeSort(nums,mid+1,end);
        //Merge both parts
        merge(nums,st,mid,end);
    }
;
    void merge(vector<int>&nums,int st,int mid,int end){
        vector<int>temp(end-st+1);
        int index=0;

        int left=st,right=mid+1;
        //Main Loop
        while(left<=mid && right<=end){
            if(nums[left]<=nums[right]){
                temp[index]=nums[left];
                index++,left++;
            }else if(nums[right]<nums[left]){
                temp[index]=nums[right];
                index++,right++;
            }
        }
        //Remaining elements of left array
        while(left<=mid){
            temp[index]=nums[left];
            index++,left++;
        }
        //Remaining elements of right array
        while(right<=end){
            temp[index]=nums[right];
            index++,right++;
        }

        index=0;
        //Make changes to original array
        for(int i=st;i<=end;i++){
            nums[i]=temp[index];
            index++;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};