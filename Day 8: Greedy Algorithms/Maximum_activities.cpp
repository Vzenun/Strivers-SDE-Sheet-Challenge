#include<bits/stdc++.h>
bool mycompare(pair< pair<int,int> ,int> p1,pair< pair<int,int> ,int> p2){
    if(p1.first.first<p2.first.first){
        return true;
    }
    else if(p1.first.first==p2.first.first){
        return (p1.second<p2.second);
    }
    else{
        return false;
    }
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector< pair< pair<int,int> ,int> > arr;
    for(int i=0;i<start.size();i++){
        arr.emplace_back(make_pair(finish[i],start[i]),i+1);
    }
    sort(arr.begin(),arr.end(),mycompare);
    int prev=-1;
    int ans=0;
    for(int i=0;i<start.size();i++){
        if(arr[i].first.second>=prev){
            ans++;
            prev=arr[i].first.first;
        }
    }
    return ans;
}