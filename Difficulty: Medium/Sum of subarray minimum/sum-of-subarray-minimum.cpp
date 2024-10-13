//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<int> findNSE(vector<int> arr, int n)
  {
      vector<int>nse(n);
      stack<int>st;
      for(int i=n-1; i>=0; i--)
      {
          while(!st.empty() && arr[st.top()]>=arr[i])
          {
              st.pop();
          }
          nse[i]=st.empty()?n:st.top();
          st.push(i);
      }
      return nse;
  }
  vector<int> findPSE(vector<int> arr, int n)
  {
      vector<int>pse(n);
      stack<int>st;
      for(int i=0; i<n; i++)
      {
          while(!st.empty() && arr[st.top()]>arr[i])
          {
              st.pop();
          }
          pse[i]=st.empty()?-1:st.top();
          st.push(i);
      }
      return pse;
      
  }
    int sumSubarrayMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>nse=findNSE(arr,n);
        vector<int>pse=findPSE(arr,n);
        int total=0;
        int mod=(int)(1e9+7);
        for(int i=0; i<n; i++)
        {
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(right*left*arr[i]*1ll)%mod)%mod;
        }
        return total;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.sumSubarrayMins(arr);
        cout << res << endl;
        // cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends