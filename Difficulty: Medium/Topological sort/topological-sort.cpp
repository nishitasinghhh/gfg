class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    
    vector<int> topoSort( int v,vector<vector<int>>& edges) {
        // Your code here
        
        int vis[v]={0};
          vector<int>adj[v];
        for (auto i: edges){
            int u= i[0];
            int v= i[1];
            adj[u].push_back(v);
            
        }
        int indegree[v]={0};
        for(int i=0; i<v; i++)
        {
            for(auto it:adj[i])
            indegree[it]++;
        }
        queue<int>q;
        for(int i=0; i<v; i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        return topo;
        
    }
};
