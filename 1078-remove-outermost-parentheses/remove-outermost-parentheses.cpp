class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth=0;
        //Main Loop
        for(char c:s){
            if(c=='('){
                if(depth>0) result.push_back('(');
                depth++;
            }else{
                depth--;
                if(depth>0) result.push_back(')');
            }
        }
        return result;
    }
};