//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string s) {
        // Your code goes here
        unordered_map<char,int>mpp;
        string str;
        for(auto ch:s)
        {
            if(mpp.find(ch)==mpp.end())
            {
                str+=ch;
                mpp[ch]=1;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends