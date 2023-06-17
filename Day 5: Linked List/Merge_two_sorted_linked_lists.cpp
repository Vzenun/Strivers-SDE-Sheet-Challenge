#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==nullptr){
        return second;
    }
    else if(second==nullptr){
        return first;
    }
    else{
        Node<int>* ans=new Node<int>(3);
        Node<int> * h1=ans;
        while(first!=nullptr && second!=nullptr){
            if(first->data<=second->data){
                ans->next=first;
                first=first->next;
                ans=ans->next;
            }
            else{
                ans->next=second;
                second=second->next;
                ans=ans->next;
            }
        }
        while(first!=nullptr){
            ans->next=first;
            first=first->next;
            ans=ans->next;
        }
        while(second!=nullptr){
            ans->next=second;
            second=second->next;
            ans=ans->next;
        }
        return h1->next;
    }
}
