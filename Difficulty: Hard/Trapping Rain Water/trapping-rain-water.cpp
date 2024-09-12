//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
  vector<int> findPrefixMax(vector<int> &arr)
  {
      int n=arr.size();
      vector<int>prefix(n);
      prefix[0]=arr[0];
      for(int i=1; i<n; i++)
      {
          prefix[i]=max(prefix[i-1],arr[i]);
      }
      return prefix;
  }
  vector<int> findSufixMax(vector<int> &arr)
  {
      int n=arr.size();
      vector<int>suffix(n);
      suffix[n-1]=arr[n-1];
      for(int i=n-2; i>=0; i--)
      {
          suffix[i]=max(suffix[i+1],arr[i]);
      }
      return suffix;
  }
    long long trappingWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long total=0;
        vector<int>prefix=findPrefixMax(arr);
        vector<int>suffix=findSufixMax(arr);
        for(int i=0; i<n; i++)
        {
            int leftMax=prefix[i];
            int rightMax=suffix[i];
            if(arr[i]<leftMax && arr[i]<rightMax)
            {
                total+=min(leftMax,rightMax)-arr[i];
            }
        }
        return total;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;

        vector<int> a(n);

        // adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a) << endl;
    }

    return 0;
}
// } Driver Code Ends