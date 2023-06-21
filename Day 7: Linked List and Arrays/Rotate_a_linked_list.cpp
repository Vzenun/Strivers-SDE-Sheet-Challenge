/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
    Node * h1=head;
    Node * h2=head;
    int n=0;
    while(h1!=nullptr){
        n++;
        h1=h1->next;
    }
    h1=head;
    k=k%n;
    while(k!=0){
        if(h1==nullptr){
            h1=head;
        }
        h1=h1->next;
        k--;
    }
    if(h1==nullptr){
        return head;
    }
    while(h1->next!=nullptr){
        h2=h2->next;
        h1=h1->next;
    }
    h1->next=head;
    h1=h2->next;
    h2->next=nullptr;
    return h1;
}