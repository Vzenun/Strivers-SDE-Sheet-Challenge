string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int> arr;
    vector<int> fact(n+1);
    for(int i=0;i<n;i++){
        arr.emplace_back(i+1);
        if(i==0){
            fact[i]=1;
        }
        else{
            fact[i]=(i)*fact[i-1];
        }
    }
    fact[n]=fact[n-1]*n;
    string answer;
    int j=n;
    k=k-1;
    while(j!=0){
        int m=k/fact[j-1];
        answer.push_back(char('0'+arr[m]));
        arr.erase(arr.begin()+m);
        k-=m*fact[j-1];
        j--;
    }
    return answer;
}
