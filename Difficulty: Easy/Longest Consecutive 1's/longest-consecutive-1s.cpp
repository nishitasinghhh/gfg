class Solution {
  public:
    int maxConsecutiveOnes(int n) {
        // code here
        int count=0;
        int ans=0;
        while(n)
        {
            if(n&1)
            {
                count++;
                ans=max(ans,count);
            }
            else
            count=0;
            n=n>>1;
        }
        return ans;
    }
};
