//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int findPrice(int index, int N,vector<int> &price,vector<vector<int>>&dp)
  {
      if(index==0)
      return price[0]*N;
      if(dp[index][N]!=-1) return dp[index][N];
      int notTake=findPrice(index-1, N, price,dp);
      int take=INT_MIN;
      int rodLength=index+1;
      if(rodLength<=N)
      {
          take=price[index]+findPrice(index, N-rodLength, price,dp);
      }
      return dp[index][N]= max(take,notTake);
  }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return findPrice(n-1, n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends