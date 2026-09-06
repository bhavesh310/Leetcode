class Solution {
public:
    int countRotations(string s, int k) {
        int ans=0;

        for(int shift=0;shift<s.size();shift++){
            int score=0;
        for(int i=0;i<s.size()-1;i++){
            char a=s[(shift+i)%s.size()];
            char b=s[(shift+i+1)%s.size()];

            if(a==b)
            score++;
        }
            if(score==k)
            ans++;
        }

        return ans;
    }
};