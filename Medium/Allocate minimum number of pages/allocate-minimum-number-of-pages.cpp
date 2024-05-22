//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int stud(int A[],int maxbook,int N)
    {
        int child=1;long long int pages=0;
        for(int i=0;i<N;i++)
        {
            if(pages+A[i]<=maxbook){pages+=A[i];}
            else{pages=A[i];child++;}
        }
        return child;
        
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M){return -1;}
        int mini=-1e9;
        int maxi=0;
        for(int i=0;i<N;i++)
        {mini=max(mini,A[i]);
         maxi+=A[i];}
         //if(stud(A,mini,N)<M){return -1;}
        while(mini<=maxi)
        {
            int mid=mini+(maxi-mini)/2;//this is the max number of pages in a book alloted to a student
            int student=stud(A,mid,N);
            if(student>M){mini=mid+1;}
            else{maxi=mid-1;}
        }
        return mini;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends