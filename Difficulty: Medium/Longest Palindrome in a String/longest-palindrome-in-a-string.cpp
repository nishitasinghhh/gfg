//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  string solve(string &s, int st, int e )
  {
      int n=s.size();
      while(st>=0 && e<n)
      {
          if(s[st]==s[e])
          {
              st--;
              e++;
          }
          else 
          break;
      }
      string ans=s.substr(st+1, e-st-1);
      return ans;
  }
    string longestPalin (string S) {
        // code here
        int n=S.size();
        int size=0;
        string ans;
        for(int i=0; i<n; i++)
        {
            string temp=solve(S,i,i);
            if(temp.size()>size)
            {
                ans=temp;
                size=temp.size();
            }
            temp=solve(S,i,i+1);
            if(temp.size()>size)
            {
                ans=temp;
                size=temp.size();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends