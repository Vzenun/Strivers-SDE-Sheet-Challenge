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

Node *firstNode(Node *head)
{
    //    Write your code here.
    if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
        return NULL;
    }
    else{
        Node* h1=head;
        Node* h2=head;
        bool a=false;
        while(h2!=nullptr && h2->next!=nullptr){
            h1=h1->next;
            h2=h2->next->next;
            if(h1==h2){
                a=true;
                break;
            }
        }
        if(a==false){
            return NULL;
        }
        else{
            h2=head;
            while(h1!=h2){
                h1=h1->next;
                h2=h2->next;
            }
            return h1;
        }
    }
}