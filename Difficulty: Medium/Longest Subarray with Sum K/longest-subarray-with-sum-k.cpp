class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mpp;
        int maxLen=0;
        int sum=0;
        
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            if(sum==k)
            maxLen=max(maxLen,i+1);
            int rem=sum-k;
            if(mpp.find(rem)!=mpp.end())
            {
                maxLen=max(maxLen,i-mpp[rem]);
            }
            if(mpp.find(sum)==mpp.end())
            {
                mpp[sum]=i;
            }
        }
        return maxLen;
    }
};
