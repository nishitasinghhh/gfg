//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void findCombinations(int ind,int B,vector<int> &A, vector<vector<int>>&ans,
    vector<int>&ds, int n )
    {
        if(ind==n)
        {
            if(B==0)
            {
                sort(ds.begin(),ds.end());
                ans.push_back(ds);
            }
            return;
        }
        if(A[ind]<=B && A[ind]!=A[ind-1])
        {
            ds.push_back(A[ind]);
        findCombinations(ind,B-A[ind],A,ans,ds,n);
        ds.pop_back();
        }
        
        
        findCombinations(ind+1,B,A,ans,ds,n);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        vector<vector<int>>ans;
        vector<int>ds;
        int n=A.size();
        findCombinations(0,B,A,ans,ds,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    
cout << "~" << "\n";
}
}	
// } Driver Code Ends