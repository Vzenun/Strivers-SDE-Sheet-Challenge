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

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node * h1=head;
    Node * h2=head;
    while(K!=0){
        h1=h1->next;
        K--;
    }
    if(h1==nullptr){
        return head->next;
    }
    while(h1->next!=nullptr){
        h2=h2->next;
        h1=h1->next;
    }
    h2->next=h2->next->next;
    return head;
}
