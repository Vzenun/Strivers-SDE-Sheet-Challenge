#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> st;
    int i=n-1;
    vector<int> ans(n,0);
    while(i>=0){
        if(st.size()==0){
            ans[i]=-1;
            st.push(arr[i]);
            i--;
        }
        else{
            if(st.top()>arr[i]){
                ans[i]=st.top();
                st.push(arr[i]);
                i--;
            }
            else{
                while(st.size()>0 && st.top()<=arr[i]){
                    st.pop();
                }
                if(st.size()==0){
                    ans[i]=-1;
                    st.push(arr[i]);
                    i--;
                }
                else{
                    ans[i]=st.top();
                    st.push(arr[i]);
                    i--;
                }
            }
        }
    }
    return ans;
}