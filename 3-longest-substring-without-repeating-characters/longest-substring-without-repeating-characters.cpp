class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //String empty
        int ans=0;
        vector<bool>count(256,0);
        int first=0,second=0;
        //Main Loop
        while(second<s.size()){
            //Remove repeated character from window
            while(count[s[second]]){
                count[s[first]]=0;
                first++;
            }
            //Non-repeating character
            count[s[second]]=1;
            ans=max(ans,second-first+1);
            second++;
        }
        return ans;
    }
};