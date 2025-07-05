// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int largest=INT_MIN;
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            largest=max(largest,arr[i]);
        }
        int secondLargest=-1;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>secondLargest && arr[i]!=largest)
            {
                secondLargest=arr[i];
            }
        }
        return secondLargest;
    }
};
