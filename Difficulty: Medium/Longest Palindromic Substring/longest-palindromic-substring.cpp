//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
string solve(string &s, int start, int end)
{
    int n=s.size();
    while(start>=0 && end<n)
    {
        if(s[start]==s[end])
        {
            start--;
            end++;
        }
        else
        break;
    }
    string ans=s.substr(start+1, end-start-1);
    return ans;
}
    string longestPalindrome(string S){
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



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends