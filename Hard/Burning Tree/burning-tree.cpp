//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
/*
This is a code to caluculate the time taken to burn a tree,assuming that the fire starts from a target node 
and takes 1 unit to burn its neighbouring(left,right,parent) node.
Data structures used are map,queue,Binary Tree.
Time Complexity=O(N)
Space Complexity=O(N)
*/
class Solution {
  public:
  void create(Node* root,int target,Node* &targetnode,map<Node*,Node*> &m)
  {
      queue <Node*> q;
      q.push(root);
      m[root]=NULL;
      while(!q.empty())
      {Node* f=q.front();
       q.pop();
       if(f->data==target){targetnode=f;}
       if(f->left)
       {m[f->left]=f;
       q.push(f->left);}
       if(f->right)
       {m[f->right]=f;
       q.push(f->right);}}
 }
      
  void burntree(Node* targetnode,int &ans,map<Node*,Node*> m)
  {
      queue<Node*>q;
      q.push(targetnode);
      //make map of node and bool
      map<Node*,bool> m2;
      m2[targetnode]=true;
      while(!q.empty())
      { int s=q.size();
        bool flag=false;
        for(int i=0;i<s;i++)
        {Node* f=q.front();q.pop();
        if(f->left && m2[f->left]!=true)
        {q.push(f->left);flag=true; m2[f->left]=true;}
         if(f->right && m2[f->right]!=true)
         {q.push(f->right);flag=true;m2[f->right]=true;}
          if(m[f]!=NULL && m2[m[f]]!=true)
          {q.push(m[f]);flag=true;m2[m[f]]=true;}
      }
         if(flag==true){ans++;}//add anser only if flag has turned true that is some neighbouring node has sbeen burnt
      }
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //step 1:map child and parent
       Node* targetnode;
       map<Node*,Node*> m;
       create(root,target,targetnode,m);
       //step 2: calculate the answer
       int ans;
       burntree( targetnode,ans,m);
       return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends