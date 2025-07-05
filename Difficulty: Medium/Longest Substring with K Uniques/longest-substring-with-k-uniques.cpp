class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        map<int,int> m;
        int j=0;
        int i=0;
        int n=s.size();
        int maxlen=0;
        while(j<n)
        {
           m[s[j]-'a']++;
           while(m.size()>k)
           {
               m[s[i]-'a']--;
               if(m[s[i]-'a']==0)
               {m.erase(s[i]-'a');}
               i++;
           }
           if(m.size()==k)
           {
               maxlen=max(maxlen,j-i+1);
           }
           j++;
        }
        if(!maxlen){return -1;}
        return maxlen;
    }
};