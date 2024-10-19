//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long>pq1;
        priority_queue<long long>pq2;
        for(long long i=0; i<K1; i++)
        {
            pq1.push(A[i]);
        }
        for(long long i=0; i<K2-1; i++)
        {
            pq2.push(A[i]);
        }
        for(long long i=K1; i<N; i++)
        {
            if(A[i]<pq1.top())
            {
                pq1.pop();
                pq1.push(A[i]);
            }
        }
        for(long long i=K2-1; i<N; i++)
        {
            if(A[i]<pq2.top())
            {
                pq2.pop();
                pq2.push(A[i]);
            }
        }
        long long sum1=0;
        while(!pq1.empty())
        {
            sum1+=pq1.top();
            pq1.pop();
        }
        long long sum2=0;
        while(!pq2.empty())
        {
            sum2+=pq2.top();
            pq2.pop();
        }
        return sum2-sum1;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends