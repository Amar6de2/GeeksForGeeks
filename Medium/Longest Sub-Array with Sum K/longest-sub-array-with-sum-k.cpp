//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int i=0;
        map<int,int> m;//sum->index
        int sum=0;
        int maxlen=0;
        while(i<N)
        {
            sum+=A[i];
           if(sum==K)
           {
               maxlen=max(maxlen,i+1);
           }
           int rem=sum-K;
           if(m.find(rem)!=m.end())
           {
               maxlen=max(maxlen,i-m[rem]);
           }
           if(m.find(sum)==m.end())
           {
               m[sum]=i;
           }
           i++;
        }
        return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends