#include <bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int i1=j+1;
            int j1=n-1;
            int sum=target-arr[j]-arr[i];
            while(i1<j1){
                if(arr[i1]+arr[j1]==sum){
                    return "Yes";
                }
                else if(arr[i1]+arr[j1]<sum){
                    i1++;
                }
                else{
                    j1--;
                }
            }
        }
    }
    return "No";
}
