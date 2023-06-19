/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	Node * h1=head;
	Node * ans=new Node(0);
	Node * t1=ans;
	if(head==nullptr){
		return nullptr;
	}
	int k=1;
	while(k!=0){
		Node * h2=h1;
		h1=h1->next;
		h2->next=nullptr;
		while(h2!=nullptr){
			ans->child=h2;
			ans=ans->child;
			h2=h2->child;
		}
		k--;
	}
	while(h1!=nullptr){
		Node * h2=h1;
		h1=h1->next;
		h2->next=nullptr;
		Node * h3=t1->child;
		Node* t=t1;
		while(h2!=nullptr && h3!=nullptr){
			if(h2->data<=h3->data){
				t->child=h2;
				h2=h2->child;
				t=t->child;
			}
			else{
				t->child=h3;
				h3=h3->child;
				t=t->child;
			}
		}
		while(h2!=nullptr){
			t->child=h2;
			h2=h2->child;
			t=t->child;
		}
		while(h3!=nullptr){
			t->child=h3;
			h3=h3->child;
			t=t->child;
		}
	}
	return t1->child;
}
