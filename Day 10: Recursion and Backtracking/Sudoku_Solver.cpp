#include<bits/stdc++.h>
bool check(vector<vector<int>> arr,int i1,int j1,int num){
    for(int i=0;i<9;i++){
        if(i!=i1){
            if(arr[i][j1]==num){
                return false;
            }
        }
    }
    for(int i=0;i<9;i++){
        if(i!=j1){
            if(arr[i1][i]==num){
                return false;
            }
        }
    }
    int a=i1/3;
    int b=j1/3;
    for(int i=3*a;i<3*a+3;i++){
        for(int j=3*b;j<3*b+3;j++){
            if(!(i==i1 && j==j1)){
                if(arr[i][j]==num){
                    return false;
                }
            }
        }
    }
    return true;
}

bool kom(vector<vector<int>> &arr,int i1){
    int flag=0;
    for(int i=i1;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j]==0){
                for(int a=1;a<=9;a++){
                    if(check(arr,i,j,a)){
                        arr[i][j]=a;
                        if(kom(arr,i)){
                            return true;
                        }
                        arr[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    vector<vector<int>> arr(9,vector<int>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            arr[i][j]=matrix[i][j];
        }
    }
    return kom(arr,0);
}
