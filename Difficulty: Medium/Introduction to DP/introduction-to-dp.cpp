//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long int M=1e9+7;
  long long f(int n ,vector<long long int> &dp)
  {
      if(n<=1) return n;
      if(dp[n]!=-1) return dp[n];
      return dp[n]=(f(n-1,dp)+f(n-2,dp))%M;
  }
    long long int topDown(int n) {
        // code here
        vector<long long int>dp(n+1,-1);
        return dp[n]=f(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
          if(n<=1)return n;
        long long prev2=0;
        long long prev=1;
        long long cur;
        for(int i=2; i<=n; i++)
        {
            cur=(prev+prev2)%M;
            prev2=prev;
            prev=cur;
        }
        return cur%M;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends