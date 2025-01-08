//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int findPath(int i, int j, vector<vector<int>> matrix,vector<vector<int>> &dp)
{
    int n=matrix.size();
    if(j<0 || j>=n) return -1e9;
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int up=matrix[i][j]+findPath(i-1, j, matrix,dp);
    int dia1=matrix[i][j]+findPath(i-1,j-1,matrix,dp);
    int dia2=matrix[i][j]+findPath(i-1,j+1,matrix,dp);
    return dp[i][j]=max(up,max(dia1,dia2));
    
}
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        // code here
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int up=matrix[i][j]+dp[i-1][j];
                int dia1=-1e9;
                if(j-1>=0)
                dia1=matrix[i][j]+dp[i-1][j-1];
                int dia2=-1e9;
                if(j+1<n)
                dia2=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=max(up,max(dia1,dia2));
            }
        }
        int maxi=dp[n-1][0];
        for(int i=1; i<n; i++)
        {
            maxi=max(maxi,dp[n-1][i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends