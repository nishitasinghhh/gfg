//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct data{
   int start;
   int end;
   int pos;
};
class Solution {
  public:
  bool static comp(data val1, data val2)
  {
      return val1.end<val2.end;
  }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        data arr[n];
        for(int i=0; i<n; i++)
        {
            arr[i].start=start[i];
            arr[i].end=end[i];
            arr[i].pos=i+1;
        }
        sort(arr,arr+n,comp);
        int cnt=1;
        int freeTime=arr[0].end;
        for(int i=1; i<n; i++)
        {
            if(arr[i].start>freeTime)
            {
                cnt+=1;
                freeTime=arr[i].end;
            }
        }
        return cnt;
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