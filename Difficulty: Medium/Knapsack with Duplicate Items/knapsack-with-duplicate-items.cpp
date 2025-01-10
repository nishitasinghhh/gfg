//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int getVal(int index,vector<int>& val,vector<int>& wt, int w,vector<vector<int>>&dp )
  {
      if(index==0)
      {
          return (int)(w/wt[0])*val[0];
      }
      if(dp[index][w]!=-1) return dp[index][w];
      int not_take=getVal(index-1,val,wt,w,dp);
      int take=INT_MIN;
      if(wt[index]<=w)
      take=val[index]+getVal(index,val,wt,w-wt[index],dp);
      return dp[index][w]= max(take,not_take);
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return getVal(n-1,val,wt,capacity,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends