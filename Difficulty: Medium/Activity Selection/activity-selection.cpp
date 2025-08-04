class Solution {
  public:
  bool static comp(const pair<int,int> &a, const pair<int,int> &b)
  {
      return a.second<b.second;
  };
    int activitySelection(vector<int> &start, vector<int> &end) {
        // code here
        if(start.size()!=end.size())
        return -1;
        vector<pair<int,int>>v;
        for(int i=0; i<start.size(); i++)
        {
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        int count=1;
        int lastTime=v[0].second;
        for(int i=1; i<v.size(); i++)
        {
            if(v[i].first>lastTime)
            {
                count++;
                lastTime=v[i].second;
            }
        }
        return count;
    }
};