//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int findPath(int i, int j, int n,vector<vector<int>>& t,vector<vector<int>>& dp)
  {
      if(i==n-1) return t[n-1][j];
      if(dp[i][j]!=-1) return dp[i][j];
      int down=t[i][j]+findPath(i+1,j,n,t,dp);
      int dia=t[i][j]+findPath(i+1,j+1,n,t,dp);
      return dp[i][j]=min(down,dia);
  }
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findPath(0,0,n,triangle,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minPathSum(triangle) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends