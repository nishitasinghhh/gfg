//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
  Node* deleteFromHead(Node* head)
  {
      if(head==NULL && head->next==NULL)
      {
          return NULL;
      }
      Node* prev=head;
      head=head->next;
      head->prev=nullptr;
      prev->next=nullptr;
      free(prev);
      return head;
  }
  Node* deleteFromTail(Node* head)
  {
      if(head==NULL && head->next==NULL)
      return NULL;
      Node* tail=head;
      while(tail->next!=NULL)
      {
          tail=tail->next;
      }
      Node*prev=tail->prev;
      tail->prev=nullptr;
      prev->next=nullptr;
      free(tail);
      return head;
  }
    Node* deleteNode(Node* head, int x) {
        // Your code here
        int cnt=0;
        Node* temp=head;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==x)
            break;
            temp=temp->next;
        }
        Node* prev=temp->prev;
        Node* front=temp->next;
        if(prev==NULL && front==NULL)
        {
            free(temp);
            return NULL;
        }
        else if(prev==NULL)
        {
            deleteFromHead(head);
        }
        else if(front==NULL)
        {
            deleteFromTail(head);
        }
        else
        {
            prev->next=front;
            front->prev=prev;
            temp->next=nullptr;
            temp->prev=nullptr;
            free(temp);
            return head;
        }
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above functions*/
int main() {
    int t, x, n, i;
    scanf("%d", &t);

    while (t--) {
        /* Start with the empty list */
        struct Node *temp, *head = NULL;
        scanf("%d", &n);

        temp = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);

            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        free(head);
    }
    return 0;
}

// } Driver Code Ends