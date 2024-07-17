//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int maxChocoUtil(int i,int j1, int j2, int n, int m, vector<vector<int>>& grid,   vector<vector<vector<int>>> &dp)
  {
      if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;
        if(i==n-1) 
        {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
            
        }
        if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
           int maxi = INT_MIN;
           for(int dj1=-1; dj1<=1; dj1++)
           {
               for(int dj2=-1; dj2<=1; dj2++)
               { int ans;
                   if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
                maxi=max(maxi,ans);
            
               }
           }
           return dp[i][j1][j2] = maxi;
  }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
    }
};
//time complexity:-O(N*M*M)*9
//space complexity:-O(N*M*M)+O(N)

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends