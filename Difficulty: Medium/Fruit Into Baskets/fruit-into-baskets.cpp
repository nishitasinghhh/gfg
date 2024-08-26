//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int maxlen=0;
        int right=0;
        int left=0;
        unordered_map<int,int>mpp;
        while(right<arr.size())
        {
            mpp[arr[right]]++;
            if(mpp.size()>2)
            {  while(mpp.size()>2)
            {
                 mpp[arr[left]]--;
                if(mpp[arr[left]]==0)
                mpp.erase(arr[left]);
                left++;
            }
               
            }
            if(mpp.size()<=2)
            {
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends