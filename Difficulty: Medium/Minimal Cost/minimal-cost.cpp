//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solveIt(int index,vector<int>&height,vector<int>&dp,int k)
  {
      if(index==0) return 0;
      if(dp[index]!=-1) return dp[index];
      int mmStep=INT_MAX;
      for(int j=1; j<=k; j++)
      {
          if(index-j>=0)
          {
              int jump=solveIt(index-j,height, dp,k)+abs(height[index]-height[index-j]);
              mmStep=min(mmStep,jump);
          }
      }
      return dp[index]=mmStep;
  }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
       vector<int>dp(n,-1);
       return solveIt(n-1,height,dp,k);
    }
};
//time complexity;-O(N)*K;
//space complexit:-O(N)+O(N)

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends