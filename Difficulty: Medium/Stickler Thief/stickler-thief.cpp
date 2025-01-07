//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum money the thief can get.
    int findMaxSum(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        int prev=arr[0];
        int prev2=0;
        for(int i=0; i<n; i++)
        {
            int pick=arr[i];
            if(i>1)
            pick+=prev2;
            int not_pick=0+prev;
            int curi=max(pick,not_pick);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {

    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        // calling function findMaxSum()
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends