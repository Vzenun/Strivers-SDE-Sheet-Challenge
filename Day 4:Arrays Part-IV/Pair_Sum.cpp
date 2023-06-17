#include <bits/stdc++.h>
#define ff first
#define ss second

vector<vector<int>> pairSum(vector<int> &arr, int s){
    // Write your code here.
    vector<pair<int,int> > arr2; 
    sort(arr.begin(),arr.end());
    int count=1;
    int prev;
    for(int i=0;i<arr.size();i++){
        if(i==0){
            prev=arr[i];
        }
        else{
            if(prev==arr[i]){
                count++;
            }
            else{
                arr2.emplace_back(prev,count);
                count=1;
                prev=arr[i];
            }
        }
    }
    arr2.emplace_back(prev,count);
    int i=0;
    int j=(int)arr2.size()-1;
    vector<vector<int>> ans;
    while(i<=j){
        if(i==j){
            if(2*arr2[i].ff==s){
                int count=(arr2[i].ss*(arr2[i].ss-1))/2;
                while(count!=0){
                vector<int> a;
                a.push_back(arr2[i].ff);
                a.push_back(arr2[j].ff);
                ans.push_back(a);
                count--;
                }
            }
            i++;
        }
        if(arr2[i].ff+arr2[j].ff==s){
            int count=arr2[i].ss*arr2[j].ss;
            while(count!=0){
                vector<int> a;
                a.push_back(arr2[i].ff);
                a.push_back(arr2[j].ff);
                ans.push_back(a);
                count--;
            }
            i++;
            j--;
        }
        else if(arr2[i].ff+arr2[j].ff<s){
            i++;
        }
        else{
            j--;
        }
    }
    return ans;
}