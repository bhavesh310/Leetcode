class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,int>nextGreater;
        stack<int> st;
        //Store next greater for each element of set
        for (int num:nums2){
            while(!st.empty() && st.top()<num) {
                nextGreater[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        //Element's that have no next greater intialise them with '-1'
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        //Next greater for subset 
        for(int num:nums1)
        ans.push_back(nextGreater[num]);
        
        return ans;
    }
};