#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int elem1=0;
    int elem2=0;
    int ct1=0;
    int ct2=0;
    int n=(int)arr.size();
    for(int i=0;i<n;i++){
        if(ct1==0){
            elem1=arr[i];
            ct1++;
        }
        else if(arr[i]==elem1){
            ct1++;
        }
        else if(ct2==0){
            elem2=arr[i];
            ct2++;
        }
        else if(arr[i]==elem2){
            ct2++;
        }
        else{
            ct2--;
            ct1--;
        }
    }
    vector<int> ans;
    ct1=0;
    ct2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==elem1){
            ct1++;
        }
        else if(arr[i]==elem2){
            ct2++;
        }
    }
    if(ct1>n/3){
        ans.emplace_back(elem1);
    }
    if(ct2>n/3){
        ans.emplace_back(elem2);
    }
    return ans;
}