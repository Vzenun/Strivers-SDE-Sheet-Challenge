#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long ans=0;
    long long prev;
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[i]>=0){
                ans=max(ans,(long long)arr[i]);
                prev=arr[i];
            }
            else{
                prev=0;
            }
        }
        else{
            if(prev+arr[i]>=0){
                ans=max(ans,prev+(long long)arr[i]);
                prev=arr[i]+prev;
            }
            else{
                prev=0;
            }
        }
    }
    return ans;
}