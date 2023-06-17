#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    arr.insert(arr.begin(),0);
    int sum=0;
    map<int,int> mpt;
    for(int i=0;i<arr.size();i++){
        sum=sum^arr[i];
        arr[i]=sum;
        mpt[arr[i]]++;
    }
    int count=0;
    for(int i=arr.size()-1;i>=1;i--){
        int a1=arr[i]^x;
        if(mpt[a1]!=0){
            if(a1==arr[i]){
                count+=mpt[a1]-1;
                mpt[arr[i]]--;
            }
            else{
                count+=mpt[a1];
                mpt[arr[i]]--;
            }
        }
    }
    return count;
}