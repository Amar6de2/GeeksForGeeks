class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n=start.size();
        
        int i=0;
        int j=0;
        int ans=0;
        int p=0;
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
         while(i<n && j<n)
         {
            if(start[i]<end[j])
            {
                p++;
                ans=max(ans,p);
                i++;
            }
            else
            {
                p--;
                ans=max(ans,p);
                j++;
            }
            
         }
         while(i<n)
         {
             p++;
             i++;
             ans=max(ans,p);
         }
         return ans;
    }
};
