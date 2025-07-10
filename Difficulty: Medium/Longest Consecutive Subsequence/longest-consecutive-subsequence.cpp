class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        unordered_set<int>st;
        for(int i=0; i<n; i++)
        {
            st.insert(arr[i]);
        }
        int cnt=1;
        int maxCount=INT_MIN;
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int x=it;
                int cnt=1;
                while(st.find(x+1)!=st.end())
                {
                    x=x+1;
                    cnt++;
                }
                maxCount=max(maxCount,cnt);
            }
        }
        return maxCount;
    }
};