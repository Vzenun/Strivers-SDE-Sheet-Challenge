/****************************************************************

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


*****************************************************************/

bool detectCycle(Node *head)
{
	//	Write your code here
    if(head==nullptr){
        return false;
    }
    if(head->next==nullptr){
        return false;
    }
    if(head->next->next==head){
        return false;
    }
    Node * h1=head;
    Node * h2=head;
    while(h2->next!=nullptr && h2->next->next!=nullptr){
        h1=h1->next;
        h2=h2->next->next;
        if(h1==h2){
            return true;
        }
    }
    return false;
}