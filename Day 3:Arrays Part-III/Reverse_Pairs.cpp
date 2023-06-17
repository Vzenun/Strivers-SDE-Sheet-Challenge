#include <bits/stdc++.h> 

long long join(int i,int m,int j,vector<int> &arr){
    int n1=m-i+1;
    int n2=j-m;
    vector<int> arr1;
    vector<int> arr2;
    for(int i1=0;i1<n1;i1++){
        arr1.emplace_back(arr[i+i1]);
    }
    for(int i1=0;i1<n2;i1++){
        arr2.emplace_back(arr[m+1+i1]);
    }
    int i1=0;
    int j1=0;
    int k=i;
    long long answer=0;
    while(i1<n1 && j1<n2){
        if(arr1[i1]<=2*arr2[j1]){
            i1++;
            k++;
        }
        else{
            j1++;
            k++;
			answer+=n1-i1;
        }
    }
	i1=0;
	j1=0;
	k=i;
	while(i1<n1 && j1<n2){
        if(arr1[i1]<=arr2[j1]){
            arr[k]=arr1[i1];
            i1++;
            k++;

        }
        else{
            arr[k]=arr2[j1];
            j1++;
            k++;
        }
    }
    while(i1<n1){
        arr[k]=arr1[i1];
        i1++;
        k++;
    }
    while(j1<n2){
        arr[k]=arr2[j1];
        j1++;
        k++;
    }
    return answer;
}

long long divide(int i,int j,vector<int> &arr){
    if(i<j){
        int m=(i+j)/2;
        long long divide1=divide(i,m,arr);
        long long divide2=divide(m+1,j,arr);
        long long join1=join(i,m,j,arr);
        return divide1+divide2+join1;
    }
    else{
        return 0;
    }
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	long long ans=divide(0,n-1,arr);
    return (int)ans;	
}