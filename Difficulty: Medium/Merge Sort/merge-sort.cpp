class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r)
        {return;}
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    void merge(vector<int> &arr,int l,int m,int r)
    {
        int l1=(m-l+1);
        int l2=(r-m);
        int k=l1+l2;
        vector<int> vec(k);
        int i=l;
        int it=0;
        int j=m+1;
        while(i<=m && j<=r)
        {
            if(arr[i]>arr[j])
            {
                vec[it]=arr[j];
                j++;
            }
            else
            {
                vec[it]=arr[i];
                i++;
            }
            it++;
        }
        while(i<=m)
        {
            vec[it++]=arr[i++];
        }
        while(j<=r)
        {
            vec[it++]=arr[j++];
        }
        for(int o=0;o<k;o++)
        {
            arr[l+o]=vec[o];
        }
    }
};