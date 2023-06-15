#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int prev;
    int i1=-1;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            prev=permutation[i];
        }
        else{
            if(permutation[i]>=prev){
                prev=permutation[i];
            }
            else{
                i1=i;
                prev=permutation[i];
                break;
            }
        }
    }
    if(i1==-1){
        for(int i=0;i<n/2;i++){
            swap(permutation[i],permutation[n-1-i]);
        }
    }
    else{
        int answer=100000;
        int k1;
        int i2=i1+1;
        while(i2!=n){
            if(permutation[i2]>prev && answer>permutation[i2]){
                answer=min(permutation[i2],answer);
                k1=i2;
            }
            i2++;
        }
        swap(permutation[i1],permutation[k1]);
        for(int i=i1+1;i<(n+i1+1)/2;i++){
            swap(permutation[i],permutation[n-1-i+i1+1]);
        }
    }
    return permutation;
}