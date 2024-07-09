//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Trie{public:
           Trie* children[2];//for 0 
           
    Trie()
    {
        this->children[0]=NULL;
        this->children[1]=NULL;
    }
};
class Trienode{public:
               Trie* root;
      Trienode()
      {
          root=new Trie();
      }
      void insert(int num)
      {
          Trie* r=root;
          for(int i=31;i>=0;i--)
          {   
              int bit=(num>>i)&1;
              if(!r->children[bit])
              {
                  Trie* child=new Trie();
                  r->children[bit]=child;
              }
              r=r->children[bit];
          }}};
int getmaxi(int num,Trie* root)
{
    Trie* r=root;
    int ans=0;
    for(int i=31;i>=0;i--)
    {
        int bit=(num>>i)&1;
        if(r->children[!bit])
        {
            ans=(ans) | (1<<i);
            r=r->children[!bit];
        }
        else
        {
            r=r->children[bit];
        }
    }
    return ans;
}
class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){    
        //code here
        Trienode* adj=new Trienode();
        int cum_xor=0;
        int maxi=0;
        adj->insert(0);
        for(int i=0;i<N;i++)
        {
            cum_xor^=arr[i];
            maxi=max(maxi,getmaxi(cum_xor,adj->root));
            adj->insert(cum_xor);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends