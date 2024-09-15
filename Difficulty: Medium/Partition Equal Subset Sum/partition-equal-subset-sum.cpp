//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool f(int index, int arr[], int target, vector<vector<int>> &dp)
{
    if(target==0) return 1;
    if(index==0) return arr[index]==target;
    if(dp[index][target]!=-1) return dp[index][target];
    bool not_take=f(index-1, arr, target, dp);
    bool take=false;
    if(arr[index]<=target)
    take=f(index-1, arr, target-arr[index], dp);
    return dp[index][target]=take||not_take;
}
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<N; i++)
        {
            sum+=arr[i];
        }
        if(sum%2==1) return false;
        int s=sum/2;
        vector<vector<int>>dp(N,vector<int>(s+1,-1));
        return f(N-1,arr,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends