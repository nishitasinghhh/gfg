//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>>start_end(n);
        for(int i=0; i<n; i++)
        {
            start_end[i]={end[i],start[i]};
        }
        sort(start_end.begin(),start_end.end());
        int count=0;
        int st=-1;
        for(auto it:start_end)
        {
            int startTime=it.second;
            int endTime=it.first;
            if(startTime>st)
            {
                count++;
                st=endTime;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends