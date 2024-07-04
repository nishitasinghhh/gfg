//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long>ans(n);
        stack<long long>st;
        for(int i=2*n-1; i>=0; i--) //store the index 
        {
            while(!st.empty() && st.top()<=arr[i%n])
            {
               
                st.pop();
            }
            if(i<n)
            {
                if(!st.empty())
                {
                    ans[i]=st.top();
                }
                else
                ans[i]=-1;
            }
            st.push(arr[i%n]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends