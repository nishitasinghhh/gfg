//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int find(int index, int W, int val[],int wt[], vector<vector<int>>&dp)
{
    if(index==0)
    {
             return (W / wt[0]) * val[0];
    }
    if(dp[index][W]!=-1) return dp[index][W];
    int notTake=0+find(index-1, W, val, wt, dp);
    int take=INT_MIN;
    if(wt[index]<=W)
    {
        take=val[index]+find(index,W-wt[index],val,wt,dp);
    }
    return dp[index][W]=max(take,notTake);
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N, vector<int>(W+1,-1));
        return find(N-1, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends