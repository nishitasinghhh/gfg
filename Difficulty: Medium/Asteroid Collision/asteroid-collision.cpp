//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        vector<int>st;
        for(int i=0; i<N; i++)
        {
            if(asteroids[i]>0)
            {
                st.push_back(asteroids[i]);
            }
            else
            {
                while(!st.empty() && st.back()<abs(asteroids[i]) && st.back()>0)
                {
                    st.pop_back();
                }
                if(!st.empty() && st.back()==abs(asteroids[i]))
                {
                    st.pop_back();
                }
                else if(st.empty() || st.back()<0)
                {
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends