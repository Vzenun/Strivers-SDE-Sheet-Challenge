#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    if(mat.size()==1){
        return;
    }
    int i=0;
    int j=0;
    int a=0;
    int i1=n-1;
    int j1=m-1;
    int a1;
    while(a<min(n/2,m/2)){
        a1=mat[i+1][j];
        for(int k=j;k<j1;k++){
            swap(mat[i][k],a1);
        }
        for(int k=i;k<i1;k++){
            swap(mat[k][j1],a1);
        }
        for(int k=j1;k>j;k--){
            swap(mat[i1][k],a1);
        }
        for(int k=i1;k>i;k--){
            swap(mat[k][j],a1);
        }
        i++;
        j++;
        i1--;
        j1--;
        a++;
    }
}