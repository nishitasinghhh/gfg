//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        // code here
        int l=0;
        int r=0;
        int maxf=0;
        int maxlen=0;
        int hash[26]={0};
        while(r<S.size())
        {
            hash[S[r]-'A']++;
            maxf=max(maxf,hash[S[r]-'A']);
            while(r-l+1-maxf>K)
            {
                hash[S[l]-'A']--;
                l++;
            }
            if(r-l+1-maxf<=K)
            {
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
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
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends