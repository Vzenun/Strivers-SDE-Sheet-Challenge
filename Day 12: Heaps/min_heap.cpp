#include <bits/stdc++.h> 
using namespace std;

vector<int> heap;
void insert_element(int element){
    heap.push_back(element);
    int i=heap.size()-1;
    while(i>0){
        int parent=(i-1)/2;
        if(heap[parent]>heap[i]){
            swap(heap[parent],heap[i]);
        }
        i=parent;
    }
}
int remove_element(){
    if(heap.size()==1){
        int a=heap[0];
        heap.pop_back();
        return a;
    }
    int a=heap[0];
    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    int i=0;
    while(i<heap.size()){
        int lchild=2*i+1;
        int rchild=2*i+2;
        if(lchild<heap.size() && heap[lchild]<heap[i]){
            i=lchild;
        }
        if(rchild<heap.size() && heap[rchild]<heap[i]){
            i=rchild;
        }
        if(i!=(rchild-1)/2){
            swap(heap[(rchild-1)/2],heap[i]);
        }
        else{
            break;
        }
    }
    return a;
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(q[i].size()==2){
            insert_element(q[i][1]);
        }
        else{
            ans.push_back(remove_element());
        }
    }
    heap.clear();
    return ans;
}
