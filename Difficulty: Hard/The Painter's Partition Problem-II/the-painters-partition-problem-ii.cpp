// User function template for C++

class Solution {
  public:
  int countPainter(vector<int> &arr, int time)
  {
      int n=arr.size();
      int painter=1;
      long long boardsPainter = 0;
      for(int i=0; i<n; i++)
      {
          if(boardsPainter+arr[i]>time)
          {
              painter++;
              boardsPainter=arr[i];
          }
          else
          {
              boardsPainter+=arr[i];
          }
      }
      return painter;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(countPainter(arr,mid)>k)
            low=mid+1;
            else
            high=mid-1;
        }
        return low;
        // return minimum time
    }
};