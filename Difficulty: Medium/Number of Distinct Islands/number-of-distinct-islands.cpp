//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void bfs(int row, int col, vector<vector<int>>& grid, vector<pair<int,int>> &v, vector<vector<bool>> &vis)
  {
      queue<pair<int,int>>q;
      q.push({row,col});
      v.push_back({0,0});
      int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                    v.push_back({nrow-row,ncol-col});
                }
            }
        }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        set<vector<pair<int,int>>>s;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>v;
                    bfs(i,j,grid,v,vis);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends