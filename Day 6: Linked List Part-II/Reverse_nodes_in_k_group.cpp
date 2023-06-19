#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node * reverse(Node * head,int k){
	if(k==1 || head->next==nullptr){
		return head;
	}
	else{
		Node * t=reverse(head->next,k-1);
		head->next->next=head;
		head->next=nullptr;
		return t;
	}
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	Node * ans=new Node(-1);
	Node * t=ans;
	Node * h1=head;
	if(head==nullptr){
		return head;
	}
	for(int i=0;i<n && h1!=nullptr;i++){
		if(b[i]==0){
			continue;
		}
		int k=b[i];
		Node * k1=h1;
		while(h1!=nullptr && b[i]!=0){
			h1=h1->next;
			b[i]-=1;
		}
		Node * a1=reverse(k1,k);
		ans->next=a1;
		ans=k1;
	}
	if(h1==nullptr){
		return t->next;
	}
	else{
		ans->next=h1;
		return t->next;
	}
}