class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long long int cum_xor=0;
        map<int,int> m;
        m[0]=1;
        long long int ans=0;
        for(auto it: arr)
        {
            cum_xor^=it;
            if(m.find(cum_xor^k)!=m.end())
            {
              ans+=m[cum_xor^k];
            }
            m[cum_xor]++;
        }
        return ans;
    }
};