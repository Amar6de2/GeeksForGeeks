// User function Template for C++
class Trie{public:
    Trie* children[2];
    Trie()
    {
        this->children[0]=NULL;
        this->children[1]=NULL;
    }
};
class TrieNode{public:
       Trie* root;
       TrieNode()
       {
           root=new Trie();
       }
       void insertnum(int num)
       {   
          Trie* r=root;
          for(int i=31;i>=0;i--)
          {
              int bit=(num>>i) & 1;
              Trie* nod;
              if(r->children[bit])
              {
                 r=r->children[bit];
              }
              else
              {
                nod=new Trie();
                r->children[bit]=nod;
                r=r->children[bit];
              }
          }
       }
};
 int getmaxi(int num,Trie* r)
       {
           int maxi=0;
           for(int i=31;i>=0;i--)
           {
               int bit=(num>>i) & 1;
               if(r->children[!bit])
               {
                  maxi=maxi ^ (1<<i);
                  r=r->children[!bit];
               }
               else
               {
                  r=r->children[bit];
               }
           }
           return maxi;
       }
class Solution {
  public:
    int maxSubarrayXOR(int N, int arr[]) {
        // code here
        TrieNode* node=new TrieNode();
        int maxans=0;
        int cum_xor=0;
        node->insertnum(0);
        for(int i=0;i<N;i++)
        {
            cum_xor^=arr[i];
            maxans=max(maxans,getmaxi(cum_xor,node->root));
            node->insertnum(cum_xor);
        }
        return maxans;
    }
};