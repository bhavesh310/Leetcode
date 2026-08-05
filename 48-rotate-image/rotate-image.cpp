class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //Main Loop
        //Transpose
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Reverse row-wise
        for(int i=0;i<n;i++){
            int st=0,end=n-1;
            while(st<end){
                swap(matrix[i][st],matrix[i][end]);
                st++,end--;
            }
        }
    }
};