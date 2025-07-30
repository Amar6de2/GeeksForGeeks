class Solution {
  public:

    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low>=high){return;}
        int partt=partition(arr,low,high);
        quickSort(arr,low,partt-1);
        quickSort(arr,partt+1,high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        
        int pivot=arr[low];
        int i=low;
        int j=high;
        while(j>i)// = daalne se TLE !!
        {
            while( i<high && pivot>=arr[i])
            {
                i++;
            }
            while(pivot<arr[j] && j>low)//mistake here !!
            {
                j--;
            }
            if(i<j)
            {swap(arr[i],arr[j]);
               
            }
        }
        swap(arr[low],arr[j]);
        return j;
        
    }
};