class Solution {
  public:
  bool CanPlaceCow(vector<int> &stalls,int dist, int k)
  {
      int n=stalls.size();
      int count=1;
      int last=stalls[0];
      for(int i=0; i<n; i++)
      {
          if(stalls[i]-last>=dist)
          {
              count++;
              last=stalls[i];
          }
          if(count>=k) return true;
      }
      return false;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(CanPlaceCow(stalls,mid,k))
            low=mid+1;
            else
            high=mid-1;
        }
        return high;
    }
};