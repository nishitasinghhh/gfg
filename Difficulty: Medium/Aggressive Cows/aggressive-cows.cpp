//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int findAggresiveCow(vector<int> &stalls,int k, int mid)
  {
      int last=stalls[0];
      int cnt=1;
      for(int i=0; i<stalls.size(); i++)
      {
          if(stalls[i]-last>=mid)
          {
              cnt++;
              last=stalls[i];
          }
      }
      if(cnt>=k) return 1;
      return 0;
  }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int low=1;
        int high=stalls[n-1]-stalls[0];
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(findAggresiveCow(stalls,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends