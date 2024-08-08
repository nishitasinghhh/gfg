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
  int findBurnTime(Node* root, unordered_map<Node*,Node*> &parent, Node* targetNode)
  {
      unordered_map<Node*,int>vis;
      queue<Node*>q;
      q.push(targetNode);
      vis[targetNode]=1;
      int maxi=0;
      while(!q.empty())
      {
          int size=q.size();
          int flg=0;
          for(int i=0; i<size; i++)
          {
              Node* temp=q.front();
              q.pop();
              if(temp->left && !vis[temp->left])
              {
                  flg=1;
                  q.push(temp->left);
                  vis[temp->left]=1;
              }
              if(temp->right && !vis[temp->right])
              {
                  flg=1;
                  q.push(temp->right);
                  vis[temp->right]=1;
              }
              if(parent[temp] && !vis[parent[temp]])
              {
                  flg=1;
                  q.push(parent[temp]);
                  vis[parent[temp]]=1;
              }
          }
          if(flg) maxi++;
      }
      return maxi;
  }
  Node* findParent(Node* root, unordered_map<Node*,Node*> &parent, int target)
  {
      Node* res;
      queue<Node*>q;
      q.push(root);
      while(!q.empty())
      {
          Node* current=q.front();
          if(current->data==target) res=current;
          q.pop();
          if(current->left)
          {
              parent[current->left]=current;
              q.push(current->left);
          }
          if(current->right)
          {
              parent[current->right]=current;
              q.push(current->right);
          }
      }
      return res;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>parent;
        Node* targetNode=findParent(root,parent,target);
        
        int time=findBurnTime(root,parent,targetNode);
        return time;
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