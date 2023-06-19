#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
bool check(LinkedListNode<int> * h1,LinkedListNode<int>* &h2){
    if(h1==nullptr){
        return true;
    }
    else{
        if(check(h1->next,h2)){
            if(h1->data==h2->data){
                h2=h2->next;
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int> * h1=head;
    LinkedListNode<int> * h2=head;
    return check(h1,h2);
}