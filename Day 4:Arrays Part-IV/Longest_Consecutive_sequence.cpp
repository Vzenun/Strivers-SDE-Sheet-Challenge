#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int answer=0;
    int count=0;
    int prev;
    for(int i=0;i<n;i++){
        if(i==0){
            prev=arr[i];
            count++;
        }
        else{
            if(arr[i]==prev){
                continue;
            }
            else if(arr[i]==prev+1){
                prev=arr[i];
                count++;
            }
            else{
                answer=max(answer,count);
                count=1;
                prev=arr[i];
            }
        }
    }
    answer=max(answer,count);
    return answer;
}