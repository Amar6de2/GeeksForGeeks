class Solution {
  public:
    long long int ans=0;
    // Function to count inversions in the array.
    void merge(int s,int m,int e,vector<int> &arr)
    {
        int i=s;
        int j=(m+1);
        int n1=m-s+1;
        int n2=e-m;
        vector<int> x(n1+n2);
        int k=0;
        while(i<=m && j<=e)
        {
            if(arr[i]<=arr[j])
            {
                x[k++]=arr[i++];
            }
            else
            {
                x[k++]=arr[j++];
                ans+=(m-i+1);
            }
        }
        while(i<=m)
        {
            x[k++]=arr[i++];
        }
        while(j<=e)
        {
            x[k++]=arr[j++];
        }
        for(int i=0;i<(n1+n2);i++)
        {
            arr[i+s]=x[i];
        }
    }
    void f(int s,int e,vector<int> &arr)
    {
        if(s>=e){return;}
        int m=(s+e)/2;
        f(s,m,arr);
        f(m+1,e,arr);
        merge(s,m,e,arr);
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        f(0,n-1,arr);
        return ans;
        
    }
};