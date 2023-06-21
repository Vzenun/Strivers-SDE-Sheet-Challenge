#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	int prev=-100000000;
	for(int i=0;i<n;i++){
		if(prev!=arr[i]){
			prev=arr[i];
			int sum=K-arr[i];
			int i1=i+1;
			int j1=n-1;
			while(i1<j1){
				if(arr[i1]+arr[j1]==sum){
					vector<int> k;
					k.emplace_back(arr[i]);
					k.emplace_back(arr[i1]);
					k.emplace_back(arr[j1]);
					int a=arr[i1];
					int b=arr[j1];
					while(arr[i1]==a && arr[j1]==b && i1<j1){
						i1++;
						j1--;
					}
					ans.emplace_back(k);

				}
				else if(arr[i1]+arr[j1]<sum){
					i1++;
				}
				else{
					j1--;
				}
			}
		}
	}
	return ans;
}