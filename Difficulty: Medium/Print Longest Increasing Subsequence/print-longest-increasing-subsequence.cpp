class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> LIS(n,1);
        vector<int> par(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int i=0;i<ind;i++)
            {
                if(arr[ind]>arr[i] && 1+LIS[i]>LIS[ind])
                {
                    LIS[ind]=1+LIS[i];
                    par[ind]=i;
                }
            }
        }
        
        int maxs=1;
        int ind=0;
        for(int i=0;i<n;i++)
        {
            if(LIS[i]>maxs)
            {
                maxs=LIS[i];
                ind=i;
            }
        }
        vector<int> ans;
        while(ind!=par[ind])
        
        {
            ans.push_back(arr[ind]);
            ind=par[ind];
        }
        ans.push_back(arr[ind]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};