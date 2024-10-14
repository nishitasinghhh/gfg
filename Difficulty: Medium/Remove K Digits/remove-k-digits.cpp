//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        int n=S.size();
        if(n==0) return "0";
        string ans;
        for(int i=0; i<n; i++)
        {
            while(!ans.empty() && K>0 && (S[i]-'0')<(ans.back()-'0'))
            {
                ans.pop_back();
                K--;
            }
            if(ans.empty() && S[i]=='0') continue;
            ans.push_back(S[i]);
        }
        while(!ans.empty() && K)
        {
            ans.pop_back();
            K--;
        }
        if(ans.empty()) return "0";
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends