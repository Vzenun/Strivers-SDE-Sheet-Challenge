#include <bits/stdc++.h> 
void sort012(int *arr, int n){
   //   Write your code here
    int high=n-1;
    int low=0;
    int mid=0;
    while(mid<=high){
        if(arr[mid]==2){
            swap(arr[high],arr[mid]);
            high--;
        }
        else if(arr[mid]==1){
            //swap(arr[high]);
            mid++;
        }
        else if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
    }
    }