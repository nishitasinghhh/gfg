//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
  
    // Function to find the length of the longest common subsequence in two strings.
    int getLCSLength(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0; i<=m; i++) dp[0][i]=0;
        for(int j=0; j<=n; j++) dp[j][0]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1]==s2[j-1])
      dp[i][j]= 1+dp[i-1][j-1];
      else
      dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.getLCSLength(s1, s2) << endl; // Call the getLCSLength function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends