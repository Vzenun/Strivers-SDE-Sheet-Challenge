int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int j=0;
    int count=k;
    int answer=0;
    for(int i=0;i<n;i++){
        if(count>0){
            if(arr[i]==0){count--;}
            answer=max(i-j+1,answer);
            continue;
        }
        else{
            if(arr[i]==1){
                answer=max(i-j+1,answer);
            }
            else{
                while(arr[j]==1){
                    j++;
                }
                j++;
                i--;
                count++;
            }
        }
    }
    return answer;
}
