class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int,int> m;
        m[0]=-1;
        int maxlen=0;
        long long int s=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            if(m.find(s-k)!=m.end())
            {
                maxlen=max(maxlen,i-m[(s-k)]);
            }
            if(m.find(s)==m.end())
            {
                m[s]=i;
            }
        }
        return maxlen;
    }
};