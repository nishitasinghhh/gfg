//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
       
         string res="";
        string temp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                temp+=s[i];
            }else {
                res=temp+'.'+res;
                temp="";
            }
        }
        res=temp+'.'+res;
        res[n]='\0';
        return res;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends