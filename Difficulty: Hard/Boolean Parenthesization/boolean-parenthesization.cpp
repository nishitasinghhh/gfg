//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
#define ll long long
const int mod = 1003;
int f(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp)
{
    if(i>j) return true;
    if(i==j)
    {
        if(isTrue) return s[i]=='T';
        else return s[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    ll ways=0;
    for(int ind=i+1; ind<=j-1; ind+=2)
    {
        ll lT=f(i,ind-1,1,s,dp);
        ll lF=f(i,ind-1,0,s,dp);
        ll rT=f(ind+1,j,1,s,dp);
        ll rF=f(ind+1,j,0,s,dp);
        if(s[ind]=='&')
        {
            if(isTrue)
            ways=(ways+(lT*rT)%mod)%mod;
            else
           ways=(ways+(lT*rF)%mod +(lF*rT)%mod +(lF*rF)%mod)%mod;
        }
        else if(s[ind]=='|')
        {
             if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else
        {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return dp[i][j][isTrue]= ways;
}
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,1,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends