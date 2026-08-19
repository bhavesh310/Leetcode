class Solution {
public:
      vector<string>getTokens(string version){
        stringstream ss(version); //used to break string into tokens
        string token="";  //token stores each extracted substring
        vector<string>tokens;
        //Reads from stringstream(ss) & extracts substrings separated by'.'
        while(getline(ss,token,'.')){
            tokens.push_back(token);
        }
        return tokens;
      }
    int compareVersion(string version1, string version2) {
        vector<string>v1=getTokens(version1);
        vector<string>v2=getTokens(version2); //Get tokens from string(version)
        int m=v1.size(),n=v2.size(),i=0;
        while(i<m || i<n){
            //If one string is shorter than other,missing parts is treated as 0
            int a= i<m ? stoi(v1[i]):0; //Convert string to int,if out of bound store 0
            int b= i<n ? stoi(v2[i]):0;
            if(a<b) return -1;
            if(a>b) return 1;
            i++; //Move to next version part
        }
        return 0; //If all parts are equal,return 0
    }
};