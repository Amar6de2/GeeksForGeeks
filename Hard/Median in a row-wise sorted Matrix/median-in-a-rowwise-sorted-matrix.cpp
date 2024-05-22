//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int upp_bound(vector<int> &arr,int target)
    {
        int mini=0;
        int maxi=arr.size()-1;
        while(maxi>=mini)
        {
            int m=(maxi+mini)/2;
            if(arr[m]>target){maxi=m-1;}
            else{mini=m+1;}
        }
        return mini;
    }
    int howmanyelementsbehind(vector<vector<int>> &matrix,int r,int ele)
    {
        int count=0;
        for(int i=0;i<r;i++)
        {
            count+=upp_bound(matrix[i],ele);
        }
        return count;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here          
        //calculating the mini and maxi
        int elebehindmedian=(R*C)/2;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<R;i++)
        {
            mini=min(mini,matrix[i][0]);
            maxi=max(maxi,matrix[i][C-1]);
        }
        while(mini<=maxi)
        {
            int mid=mini+(maxi-mini)/2;
            if(howmanyelementsbehind(matrix,R,mid)<=elebehindmedian){mini=mid+1;}
            else{maxi=mid-1;}
        }
        return mini;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends