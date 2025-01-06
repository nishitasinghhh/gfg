//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int findMinE(vector<int> &heights, int index, vector<int> &dp)
  {
      if(index==0) return 0;
      if(dp[index]!=-1) return dp[index];
    int left=findMinE(heights, index-1,dp)+abs(heights[index]-heights[index-1]);
    int right=INT_MAX;
    if(index>1)
     right=findMinE(heights,index-2,dp)+abs(heights[index]-heights[index-2]);
      
      return dp[index]=min(left,right);
  }
    int minimumEnergy(vector<int>& heights, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return findMinE(heights,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends