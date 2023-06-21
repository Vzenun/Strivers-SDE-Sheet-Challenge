#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long i=0;
    long j=n-1;
    long left_height=0;
    long right_height=0;
    long water=0;
    while(i<=j){
        if(arr[i]<=arr[j]){
            if(arr[i]>=left_height){
                left_height=arr[i];
            }
            else{
                water+=(left_height-arr[i]);
            }
            i++;
        }
        else{
            if(arr[j]>=right_height){
                right_height=arr[j];
            }
            else{
                water+=(right_height-arr[j]);
            }
            j--;
        }
    }
    return water;
}