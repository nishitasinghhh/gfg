class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int>ans;
        int l=0,r=0,n=arr.size(),sum=0;
        bool flg=false;
        while(r<n)
        {
            sum+=arr[r];
            while(sum>target)
            {
                sum-=arr[l];
                l++;
            }
            if(sum==target)
            {
                flg=true;
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            r++;
        }
        if(!flg) return {-1};
        return ans;
    }
};