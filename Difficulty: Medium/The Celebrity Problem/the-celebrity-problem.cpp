//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        for(int i=n-1; i>=0; i--)
        {
            st.push(i);
        }
        while(st.size()>1)
        {
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            if(M[first][second] && !M[second][first])
            st.push(second);
            if(!M[first][second] && M[second][first])
            st.push(first);
        }
        if(st.empty()) return -1;
        int num=st.top();
        st.pop();
        int row=0;
        int col=0;
        for(int i=0; i<n; i++)
        {
            row+=M[num][i];
            col+=M[i][num];
        }
        return row==0 && col==n-1? num:-1;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends