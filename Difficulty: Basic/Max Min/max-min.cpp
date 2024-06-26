//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	//code here.
    	int maxi=INT_MIN;
    	int mini=INT_MAX;
    	int sum=0;
    	for(int i=0; i<N; i++)
    	{
    	    maxi=max(maxi,A[i]);
    	    mini=min(mini,A[i]);
    	}
    	sum=maxi+mini;
    	return sum;
    }

};
//time complexity:-O(N)
//space complexity:-O(1)

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends