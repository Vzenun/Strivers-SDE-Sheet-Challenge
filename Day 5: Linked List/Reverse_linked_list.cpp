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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head==nullptr){
        return head;
    }
    else if(head->next==nullptr){
        return head;
    }
    else{
        LinkedListNode<int> * t=reverseLinkedList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return t;
    }
}