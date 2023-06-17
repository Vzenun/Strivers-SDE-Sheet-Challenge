/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    Node * h1=head;
    Node * h2=head;
    if(head==nullptr){
        return nullptr;
    }
    else if(head->next==nullptr){
        return head;
    }
    else if(head->next->next==nullptr){
        return head->next;
    }
    else{
        while(h2!=nullptr && h2->next!=nullptr){
            h1=h1->next;
            h2=h2->next->next;
        }
        return h1;
    }
}

