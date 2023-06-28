#include <bits/stdc++.h> 
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
	vector<int> arr=positions;
	int i=0;
	int j=positions[n-1]+1;
	while(i+1<j){
		int m=(i+j)/2;
		int i1=0;
		int j1=0;
		int c1=c-1;
		while(j1<n){
			if(arr[j1]-arr[i1]>=m){
				i1=j1;
				c1--;
			}
			else{
				j1++;
			}
		}
		if(c1<=0){
			i=m;
		}
		else{
			j=m;
		}
	}
	return i;
}