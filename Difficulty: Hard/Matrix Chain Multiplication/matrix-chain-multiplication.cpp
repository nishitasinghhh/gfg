//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int findSteps(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
  {
      if(i==j) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      int mini=1e9;
      for(int k=i; k<j; k++)
      {
          int steps=arr[i-1]*arr[k]*arr[j]+findSteps(i,k,arr,dp)+findSteps(k+1,j,arr,dp);
          mini=min(mini,steps);
      }
      return dp[i][j]= mini;
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return findSteps(1,n-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends