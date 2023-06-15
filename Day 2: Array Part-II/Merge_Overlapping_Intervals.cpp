#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
bool mycompare(vector<int> p1 ,vector<int> p2){
    if(p1[0]<p2[0]){return true;}
    else if(p1[0]==p2[0]){return p1[1]>p2[1];}
    else{return false;}
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end(),mycompare);
    vector<vector<int>> ans;
    for(int i=0;i<intervals.size();i++){
        if(i==0){
            ans.emplace_back(intervals[i]);
        }
        else{
            if(ans[ans.size()-1][0]<=intervals[i][0] && ans[ans.size()-1][1]>=intervals[i][0]){
                if(ans[ans.size()-1][1]<intervals[i][1]){
                    ans[ans.size()-1][1]=intervals[i][1];
                }
                continue;
            }
            else{
                ans.emplace_back(intervals[i]);
            }
        }
    }
    return ans;
}
