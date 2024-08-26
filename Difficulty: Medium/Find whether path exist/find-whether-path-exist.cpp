//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, pair<int,int> &source,pair<int,int> &destination)
    {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({source.first,source.second});
        vis[source.first][source.second]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            if(grid[row][col]==2)
            return true;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]!=0)
                {
                    vis[nrow][ncol]=1;
                   
                    q.push({nrow,ncol});
                }
            }
        }
        if(source.first==destination.first && source.second==destination.second)
        return true;
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        pair<int,int> source;
        pair<int,int> destination;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                
                if(grid[i][j]==1)
                {
                    source={i,j};
                }
                
            }
        }
        return bfs(grid,vis,source,destination);
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends