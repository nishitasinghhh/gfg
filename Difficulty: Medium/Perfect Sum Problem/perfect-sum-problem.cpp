//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=(int)(1e9+7);
	int findways(int index, int target, int arr[],  vector<vector<int>> &dp)
	{
	   
	    if(index==0)
	    
	    {
	        if(target==0 && arr[0]==0) return 2;
	        if(target==0 || target==arr[0]) return 1;
	        return 0;
	    }
	    if(dp[index][target]!=-1) return dp[index][target];
	    int notTaken=findways(index-1, target, arr, dp);
	    int taken=0;
	    if(arr[index]<=target)
	    {
	        taken=findways(index-1,target-arr[index],arr, dp);
	    }
	    return dp[index][target]=(taken+notTaken)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return findways(n-1,sum,arr,dp);
	}
	  
};
//time complexity;-O(N*SUM)
//space complexit:-O(N*sum) +O(N)

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends