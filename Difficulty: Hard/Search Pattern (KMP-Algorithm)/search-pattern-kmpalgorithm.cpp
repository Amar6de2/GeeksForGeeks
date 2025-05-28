class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        int p=pat.size();
        vector<int> LPS(p,0);
        LPS[0]=0;
        int len=0;
        int i=1;
        while(i<p)
        {
            if(pat[i]==pat[len])
            {
              len++;
              LPS[i]=len;
              i++;
            }
            else
            {
              if(len==0)
              {
                  LPS[i]=0;
                  i++;
              }
              else
              {
                  len--;
              }
            }
        }
        
        vector<int> ans;
         i=0;
        int j=0;
        int t=txt.size();
        while(j<t)
        {
          if(txt[j]==pat[i])
          {
            i++;
            j++;
            if(i==p)
            {ans.push_back(j-p);
             i=LPS[i-1];//IMP 
            }
          }
          else
          {
              if(i==0)
              {j++;continue;}
              i=LPS[i-1];
          }
        }
        return ans;
        
    }
};