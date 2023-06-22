#include <bits/stdc++.h> 

bool mycompare(vector<int> job1,vector<int> job2){
    if(job1[0]>job2[0]){
        return true;
    }
    else if(job1[0]>job2[0]){
        return (job1[1]>job2[1]);
    }
    else{
        return false;
    }
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),mycompare);
    priority_queue<int> pq;
    int sum=0;
    int j=0;
    for(int i=3000;i>=1;i--){
        while(j<jobs.size() && jobs[j][0]==i){
            pq.emplace(jobs[j][1]);
            j++;
        }
        if(pq.empty()){
            continue;
        }
        else{
            sum+=pq.top();
            pq.pop();
        }
    }
    return sum;
}
