class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //Store indegree of every node
        vector<int>indegree(n,0);

        //Calculate indegree for each node
        for(auto &edge:edges){
            int from=edge[0];
            int to=edge[1];

            //Incoming edge to 'to'
            indegree[to]++;
        }

        vector<int> ans;

        //Nodes having indegree 0 cannot be reached from any other node
        //So they must be included as they don't have any incoming edge on them
        for (int i=0;i<n;i++)
        if(indegree[i]==0)
        ans.push_back(i);
        
        return ans;
    }
};