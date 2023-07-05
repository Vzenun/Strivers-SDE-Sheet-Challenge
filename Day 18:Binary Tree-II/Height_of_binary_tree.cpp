#include <bits/stdc++.h> 

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	// Write your code here.
	int i1=0;
	map<int,int> mpt;
	for(int i=0;i<N;i++){
		mpt[inorder[i]]=i;
	}
	queue<pair<pair<int,int>,int>> q;
	q.emplace(make_pair(make_pair(0,N-1),0));
	int answer=0;
	while(!q.empty()){
		int i=q.front().first.first;
		int j=q.front().first.second;
		int ht=q.front().second;
		q.pop();
		if(i==j){
			if(inorder[i]==levelOrder[i1]){
				i1++;
				answer=max(1+ht,answer);
			}
		}
		else{
			int a1=mpt[levelOrder[i1]];
			if(a1>=i && a1<=j){
				i1++;
				if(a1-1>=i){
					q.emplace(make_pair(make_pair(i,a1-1),1+ht));
					answer=max(1+ht,answer);
				}
				if(a1+1<=j){
					q.emplace(make_pair(make_pair(a1+1,j),1+ht));
					answer=max(1+ht,answer);
				}
			}
		}
	}
	return answer-1;
}