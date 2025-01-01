//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int index=k;
        int el=-1;
        int cnt=1;
        int n1=a.size();
        int n2=b.size();
        int i=0;
        int j=0;
        while(i<n1 && j<n2)
        {
            if(a[i]<b[j])
            {
                if(cnt==k) el= a[i];
                cnt++;
                i++;
            }
            else
            {
                if(cnt==k) el = b[j];
                cnt++;
                j++;
            }
        }
        while(i<n1)
        {
            if(cnt==k) el =a[i];
                cnt++;
                i++;
        }
        while(j<n2)
        {
            if(cnt==k) el= b[j];
                cnt++;
                j++;
        }
        return el;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends