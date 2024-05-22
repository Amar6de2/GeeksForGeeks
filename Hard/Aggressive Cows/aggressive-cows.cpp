//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int howmanycowsplaced(int mindist,vector<int> &stalls)
    {   int cow=1;int last=stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-last>=mindist){cow++;last=stalls[i];}//we move last[i] why as see we are concerned only for min distance and we know that dist[i]-dist[0] will alwyys be greater than dist[i]-last as this is sorted array
            
        }
        return cow;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int mini=INT_MAX;
        for(int i=0;i<stalls.size()-1;i++){mini=min(mini,stalls[i+1]-stalls[i]);}
        int maxi=stalls[stalls.size()-1]-stalls[0];
        while(mini<=maxi)
        {
            int mid=mini+(maxi-mini)/2;//this is the minimum distance possible between any 2 cows
            int cow=howmanycowsplaced(mid,stalls);
            if(cow>=k){mini=mid+1;}
            else{maxi=mid-1;}
            
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends