//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
Node* merge(Node* leftHead,Node* rightHead)
    {
        if(leftHead==NULL) return rightHead;
        if(rightHead==NULL) return leftHead;
        Node* t1=leftHead;
            Node* t2=rightHead;
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->data<=t2->data)
            {
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }
            else
            {
          temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        while(t1)
        {
            temp->next=t1;
                temp=t1;
                t1=t1->next;
        }
        while(t2)
        {
             temp->next=t2;
                temp=t2;
                t2=t2->next;
        }
        return dummy->next;
    }
    Node* findMiddle(Node* head)
    { if (head == NULL || head->next == NULL) {
            return head;
        }
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
            return head;
       Node* middle=findMiddle(head);
       Node* left=head;
     Node* right=middle->next;
        middle->next=NULL;
        Node* lefthead=mergeSort(left);
       Node* righthead=mergeSort(right);
        return merge(lefthead,righthead);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends