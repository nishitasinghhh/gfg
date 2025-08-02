class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* element=new StackNode(x);
        element->next=top;
        top=element;
        
    }

    int pop() {
        
        // code here
        if(top==NULL)
        return -1;
        StackNode* temp=top;
        int value=temp->data;
        top=top->next;
        free(temp);
        return value;
    }

    MyStack() { top = NULL; }
};