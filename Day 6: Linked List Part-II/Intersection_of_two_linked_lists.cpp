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

Node * findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int n=0;
    int m=0;
    Node * h1=firstHead;
    while(h1!=nullptr){
        h1=h1->next;
        n++;
    }
    h1=secondHead;
    while(h1!=nullptr){
        h1=h1->next;
        m++;
    }
    if(m>n){
        Node * h2;
        h2=secondHead;
        int a=m-n;
        while(a>0){
            h2=h2->next;
            a--;
        }
        h1=firstHead;
        while(h1!=nullptr && h2!=nullptr && h1!=h2){
            h1=h1->next;
            h2=h2->next;
        }
        if(h1==nullptr || h2==nullptr){
            return nullptr;
        }
        else{
            return h1;
        }
    }
    else if(m<n){
        Node * h2;
        h2=firstHead;
        int a=n-m;
        while(a>0){
            h2=h2->next;
            a--;
        }
        h1=secondHead;
        while(h1!=nullptr && h2!=nullptr && h1!=h2){
            h1=h1->next;
            h2=h2->next;
        }
        if(h1==nullptr || h2==nullptr){
            return nullptr;
        }
        else{
            return h1;
        }
    }
    else{
        Node * h2;
        h2=firstHead;
        h1=secondHead;
        while(h1!=nullptr && h2!=nullptr && h1!=h2){
            h1=h1->next;
            h2=h2->next;
        }
        if(h1==nullptr || h2==nullptr){
            return nullptr;
        }
        else{
            return h1;
        }
    }
}