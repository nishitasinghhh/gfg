//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool SumEqual(int index, int k, int sum, vector<int> &ans, vector<int>&arr,int n)
    {
        if(sum==k) return true;
        if(sum>k) return false;
        if(index==n)
        {
            if(sum==k)
            return true;
            return false;
        }
        ans.push_back(arr[index]);
        sum+=arr[index];
        if(SumEqual(index+1,k,sum,ans,arr,n))
        return true;
        ans.pop_back();
        sum-=arr[index];
        if(SumEqual(index+1,k,sum,ans,arr,n))
        return true;
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<int>ans;
       
        if(SumEqual(0,k,0,ans,arr,n)==true)
        return true;
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends