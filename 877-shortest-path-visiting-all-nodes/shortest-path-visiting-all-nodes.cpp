class Solution {
public:
    typedef pair<int,int>P;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();

        if(n==1 || n==0)
        return 0;

        queue<P>q;
        set<P>visited;

        for(int i=0;i<n;i++){
            int maskValue=(1<<i);

            q.push({i,maskValue});
            visited.insert({i,maskValue});
        }

        int allVisited=pow(2,n)-1; //1111 all '1's
        int path=0;

        //Level 0=states reachable in 0 moves
        //Find the minimum number of level's will visit all nodes
        while(!q.empty()){
            int size=q.size();
            path++;

            while(size--){
                auto curr=q.front();
                q.pop();

                int currNode=curr.first;
                int currMask=curr.second;

                for(int &adj : graph[currNode]){

                    int nextMask=currMask | (1<<adj);

                    if(nextMask==allVisited)
                    return path;

                    if(visited.find({adj,nextMask}) == visited.end()){
                        visited.insert({adj,nextMask});
                        q.push({adj,nextMask});
                    }
                }
            }
        }

        return -1;
    }
};