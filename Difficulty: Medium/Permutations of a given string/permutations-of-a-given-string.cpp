//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(int index, set<string> &ans, string &S)
	{
	    if(index>=S.size())
	    {
	        ans.insert(S);
	        return;
	    }
	    for(int j=index; j<S.size(); j++)
	    {
	        swap(S[index],S[j]);
	        solve(index+1,ans,S);
	        swap(S[index],S[j]);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>ans;
		 
		    int index=0;
		 
		    solve(index,ans,S);
		       vector<string>ds(ans.begin(),ans.end());
		    return ds;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends