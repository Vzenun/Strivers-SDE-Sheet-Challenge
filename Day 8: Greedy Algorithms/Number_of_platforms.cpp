int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int answer=1;
    int count=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(at[i]>dt[j]){
            answer=max(count,answer);
            count--;
            j++;
            i--;
        }
        else{
            count++;
            answer=max(count,answer);
        }
    }
    answer=max(count,answer);
    return answer;
}