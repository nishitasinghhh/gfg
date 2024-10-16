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
class Solution {
  public:
  int findMinTime(Node* root, Node* targetNode,  unordered_map<Node*,Node*> &parent)
  {
      unordered_map<Node*,bool>vis;
      queue<Node*>q;
      q.push(targetNode);
      vis[targetNode]=1;
      int mini=0;
      while(!q.empty())
      {
          int size=q.size();
          bool flag=false;
          for(int i=0; i<size; i++)
          {
              Node* temp=q.front();
              q.pop();
              if(temp->left && !vis[temp->left])
              {
                  flag=1;
                  q.push(temp->left);
                  vis[temp->left]=1;
              }
              if(temp->right && !vis[temp->right])
              {
                  flag=1;
                  q.push(temp->right);
                  vis[temp->right]=1;
              }
              if(parent[temp] && !vis[parent[temp]])
              {
                  flag=1;
                  q.push(parent[temp]);
                  vis[parent[temp]]=1;
              }
          }
          if(flag) mini++;
      }
      return mini;
  }
  Node* findParent( unordered_map<Node*,Node*> &parent, Node* root, int target)
  {
      queue<Node*>q;
      q.push(root);
      Node* res;
      while(!q.empty())
      {
          Node* node=q.front();
          q.pop();
          if(node->data==target) res=node;
          if(node->left)
          {
              parent[node->left]=node;
              q.push(node->left);
          }
          if(node->right)
          {
              parent[node->right]=node;
              q.push(node->right);
          }
      }
      return res;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>parent;
        Node* targetNode=findParent(parent,root,target);
        int mini=findMinTime(root,targetNode,parent);
        return mini;
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