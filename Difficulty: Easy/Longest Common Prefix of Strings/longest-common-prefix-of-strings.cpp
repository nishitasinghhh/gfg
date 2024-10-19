//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        if(arr.size()==1) return arr[0];
        sort(arr.begin(),arr.end());
        int n=arr.size();
       
        string first=arr[0];
        string last=arr[n-1];
        string ans;
        int x=0;
        int y=0;
        while(x<first.length() && y<last.length())
        {
            if(first[x]==last[y])
            {
                ans+=first[x];
                x++;
                y++;
            }
            else
            break;
        }
        if(ans.size()==0) return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends