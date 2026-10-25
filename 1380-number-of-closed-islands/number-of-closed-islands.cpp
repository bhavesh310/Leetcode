class Solution {
public:
      int m,n;
       bool dfs(vector<vector<int>>& grid,int r,int c){
        if(r>=m || r<0|| c>=n || c<0){ //Not closed out of bound
            return false;
        }
        //water found
        if(grid[r][c]==1){ //closed from side
           return true;
        }
        grid[r][c]=1; //mark visited for the '0' land
        //apply dfs in all four directions to check whether surrounded by water or not
        bool leftclosed=dfs(grid,r,c-1);
        bool rightclosed=dfs(grid,r,c+1);
        bool upclosed=dfs(grid,r-1,c);
        bool downclosed=dfs(grid,r+1,c);
        return leftclosed && rightclosed && upclosed && downclosed;  //closed island
     }
    int closedIsland(vector<vector<int>>& grid) {
        //Number of closed islands surrounded by water
         m=grid.size();
         n=grid[0].size();
         int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //land found
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)==true){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};