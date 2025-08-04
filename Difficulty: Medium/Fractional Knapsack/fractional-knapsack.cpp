// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
  bool static comp(const pair<int,int> &a, const pair<int,int> &b)
  {
      double v1=(double)a.first/(double)a.second;
      double v2=(double)b.first/(double)b.second;
      return v1>v2;
  };
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++)
        {
            v.push_back({val[i],wt[i]});
        }
        sort(v.begin(),v.end(),comp);
        int curWt=0;
        double totVal=0;
        for(int i=0; i<v.size(); i++)
        {
            if(curWt+v[i].second<=capacity)
            {
                 curWt+=v[i].second;
                totVal+=v[i].first;
            }
            else
            {
                 int remain=capacity-curWt;
                 totVal=totVal+((double)v[i].first/(double)v[i].second)*(double)remain;
                 break;
            }
        }
        return totVal;
    }
};
