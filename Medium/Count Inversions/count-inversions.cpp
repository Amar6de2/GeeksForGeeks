//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long int inv=0;
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[],int low,int mid,int high)//WE HAVE TO MERGE 2 arrays: one array s index starts from low to mid  and the other array s index starts from mid+1 to high
    {
      int i=low;
      int j=mid+1;
      int n=mid-low+1;
      int m=high-mid;
      vector<long long int> combine(n+m);int k=0;
      while(i<=mid && j<=high)
      {
          if(arr[i]>arr[j])
          {
              combine[k]=arr[j];
              inv+=mid-i+1;j++;k++;//arr1 will be from i to mid index
          }
          else{combine[k++]=arr[i++];}
      }
      while(i<=mid)
      {
          combine[k++]=arr[i++];
      }
      while(j<=high)
      {
          combine[k++]=arr[j++];
      }
      for(int x=low;x<=high;x++)
      {
          arr[x]=combine[x-low];
      }
    }
    void mergesort(long long arr[],int i,int j)
    {
        if(j<=i){return;}
        int mid=(i+j)/2;
        mergesort(arr,i,mid);//left part is from i to mid
        mergesort(arr,mid+1,j);//right part is from mid=1 to j
        merge(arr,i,mid,j);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergesort(arr,0,N-1);
        return inv;
        
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends