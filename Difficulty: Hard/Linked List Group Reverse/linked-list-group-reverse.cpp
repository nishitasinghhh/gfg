/*
class Node {
  public:
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
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head==NULL)
         return NULL;
        Node* next=NULL;
        Node* prev=NULL;
        Node* cur=head;
        int count=0;
        while(cur && count<k)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
        }
        if(next)
        head->next=reverseKGroup(next,k);
        return prev;
        
    }
};