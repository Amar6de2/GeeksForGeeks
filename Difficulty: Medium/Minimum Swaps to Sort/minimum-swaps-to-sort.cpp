class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<pair<int,int>> num(n);
        for(int i=0;i<n;i++)
        {
            num[i]={arr[i],i};
        }
        sort(num.begin(),num.end());
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            int pos=i;// this is the origpos where this arr[i] was initially
            int swap=0;//assuming the arr[i] is at the correct position ...so swap =1 means arr[i] ko arr[i] se swap kar rahe hai i th position pe !
            while(!vis[pos])
            {   
                vis[pos]=1;
                swap++;
                pos=num[pos].second;
            }
            ans+=max(swap-1,0);
        }
        return ans;
        
    }
};