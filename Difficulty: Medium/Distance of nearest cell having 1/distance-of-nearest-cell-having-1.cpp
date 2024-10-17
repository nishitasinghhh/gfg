//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    void findDistance(vector<vector<int>>& grid,vector<vector<int>> &vis,vector<vector<int>> &dis)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int step=q.front().second;
            dis[r][c]=step;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] )
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},step+1});
                }
            }
        }
    }
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        findDistance(grid,vis,dis);
        return dis;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends