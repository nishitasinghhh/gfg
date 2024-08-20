//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<bool>count(256,0);
        int first=0;
        int second=0;
        int len=0;
        while(second<S.length())
        {
            while(count[S[second]])
            {
                count[S[first]]=0;
                first++;
            }
            count[S[second]]=1;
            len=max(len,second-first+1);
            second++;
        }
        return len;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends