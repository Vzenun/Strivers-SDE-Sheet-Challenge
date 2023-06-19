/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    if(num1==nullptr){
        return num2;
    }
    if(num2==nullptr){
        return num1;
    }
    Node * ans=new Node(5);
    Node * t=ans;
    int cursor=-1;
    while(num1!=nullptr && num2!=nullptr){
        if(cursor==0 || cursor==-1){
            if(num1->data+num2->data>=10){
                cursor=1;
                num1->data=num1->data+num2->data-10;
                ans->next=num1;
                num1=num1->next;
                num2=num2->next;
            }
            else{
                cursor=0;
                num1->data=num1->data+num2->data;
                ans->next=num1;
                num1=num1->next;
                num2=num2->next;
            }
        }
        else{
            if(num1->data+num2->data+1>=10){
                cursor=1;
                num1->data=num1->data+num2->data+1-10;
                ans->next=num1;
                num1=num1->next;
                num2=num2->next;
            }
            else{
                cursor=0;
                num1->data=num1->data+num2->data+1;
                ans->next=num1;
                num1=num1->next;
                num2=num2->next;
            }
        }
        ans=ans->next;
    }
    while(num1!=nullptr){
        if(cursor==0 || cursor==-1){
            ans->next=num1;
            num1=num1->next;
        }
        else{
            if(num1->data+1>=10){
                cursor=1;
                num1->data=num1->data+1-10;
                ans->next=num1;
                num1=num1->next;
            }
            else{
                cursor=0;
                num1->data=num1->data+1;
                ans->next=num1;
                num1=num1->next;
            }
        }
        ans=ans->next;
    }
    while(num2!=nullptr){
        if(cursor==0 || cursor==-1){
            ans->next=num2;
            num2=num2->next;
        }
        else{
            if(num2->data+1>=10){
                cursor=1;
                num2->data=num2->data+1-10;
                ans->next=num2;
                num2=num2->next;
            }
            else{
                cursor=0;
                num2->data=num2->data+1;
                ans->next=num2;
                num2=num2->next;
            }
        }
        ans=ans->next;
    }
    if(cursor==0 || cursor==-1){
        return t->next;
    }
    else{
        ans->next=new Node(1);
        return t->next;
    }
}
