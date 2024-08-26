//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int func(vector<int> &arr, int target)
  {
      if(target<0) return 0;
      int l=0;
      int r=0;
      int sum=0;
      int cnt=0;
      while(r<arr.size())
      {
          sum+=arr[r];
          while(sum>target)
          {
              sum=sum-arr[l];
              l++;
          }
          cnt+=(r-l+1);
          r++;
      }
      return cnt;
  }
    int numberOfSubarrays(vector<int>& arr, int target) {
        // Your code goes here.
        int ans=func(arr,target)-func(arr,target-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<int> arr;
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.numberOfSubarrays(arr, target) << endl;
    }
    return 0;
}
// } Driver Code Ends