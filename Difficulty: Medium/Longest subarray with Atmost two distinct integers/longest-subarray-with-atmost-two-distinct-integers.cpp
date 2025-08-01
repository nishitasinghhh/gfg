class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxi=0;
        int l=0;
        int r=0;
        unordered_map<int,int>mpp;
        while(r<n)
        {
            mpp[arr[r]]++;
            while(mpp.size()>2)
            {
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0)
                mpp.erase(arr[l]);
                l++;
            }
            if(mpp.size()<=2)
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};