class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<int>open;
        //door[] array stores matching parenthesis pairs
        vector<int>door(n);
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            open.push(i);
            else if(s[i]==')'){ 
                int j=open.top(); //Get latest unmatched '(' index
                open.pop();
                door[i]=j; //Map ')' to '('
                door[j]=i; //Map '(' to ')'
            }
        }
        string result;
        int flag=1;
        for(int i=0;i<n;i+=flag){
            if(s[i]=='(' || s[i]==')'){
                i=door[i];  //Jump to its matching parenthesis
                //reverse direction(flag=-flag)
                flag=-flag; //Change direction(+:R,-:L)
            }else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};