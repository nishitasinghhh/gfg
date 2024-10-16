//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
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
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {
  private:
  public:
Node* markParent(Node* root,int target,unordered_map<Node*,Node*> &parent)
{
    Node* res;
    queue<Node*>q;
    q.push(root);
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
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*,Node*>parent;
        Node* targetNode=markParent(root,target,parent);
        unordered_map<Node*, bool>vis;
        queue<Node*>q;
        q.push(targetNode);
        vis[targetNode]=1;
        int cur_level=0;
        while(!q.empty())
        {
            int size=q.size();
            if(cur_level++==k) break;
            for(int i=0; i<size; i++)
            {
                Node* temp=q.front();
                q.pop();
                if(temp->left && !vis[temp->left])
                {
                    q.push(temp->left);
                    vis[temp->left]=1;
                }
                if(temp->right && !vis[temp->right])
                {
                    q.push(temp->right);
                    vis[temp->right]=1;
                }
                if(parent[temp] && !vis[parent[temp]])
                {
                    q.push(parent[temp]);
                    vis[parent[temp]]=1;
                }
            }
        }
        vector<int>result;
        while(!q.empty())
        {
            result.push_back(q.front()->data);
            q.pop();
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    Solution x = Solution();

    while (t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        vector<int> res = x.KDistanceNodes(head, target, k);
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends