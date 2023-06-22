#include <bits/stdc++.h> 

bool mycompare(pair<int,int> p1,pair<int,int> p2){
    return (double)p1.second/p1.first>(double)p2.second/p2.first;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),mycompare);
    int W=w;
    int i=0;
    double sum=0;
    while(w!=0 && i<n){
        if(items[i].first<=W){
            sum+=items[i].second;
            W-=items[i].first;
        }
        else{
            sum+=((double)items[i].second/items[i].first)*W;
            W=0;
        }
        i++;
    }
    return sum;
}