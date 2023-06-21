#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    map<LinkedListNode<int> *,LinkedListNode<int> *> mpt;
    LinkedListNode<int> *h1=head;
    LinkedListNode<int> *h2=new LinkedListNode<int>(3);
    LinkedListNode<int> *h3=h2;
    while(h1!=nullptr){
        h2->next=new LinkedListNode<int>(h1->data);
        h2=h2->next;
        mpt[h1]=h2;
        h1=h1->next;
    }
    h2=h3->next;
    h1=head;
    while(h1!=nullptr){
        h2->random=mpt[h1->random];
        h2=h2->next;
        h1=h1->next;
    }
    return h3->next;
}
