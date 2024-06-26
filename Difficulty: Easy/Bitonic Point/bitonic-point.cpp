//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    sort(arr,arr+n);
	    if(n==1){return arr[0];}
	    int mini=0;
	    int maxi=n-2;
	    if(arr[0]>arr[1]){return arr[0];}
	    if(arr[n-1]>arr[n-2]){return arr[n-1];}
	    
	    while(maxi>=mini)
	    {
	        int mid=(mini+maxi)/2;
	        if(arr[mid]>=arr[mid+1])
	        {
	            maxi=mid-1;
	        }
	        else
	        {
	            mini=mid+1;
	        }
	    }
	    return arr[mini];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends