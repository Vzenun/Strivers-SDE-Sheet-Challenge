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
    while(j!=0 && k!=0){
        int m=k/fact[j-1];
        int r=k%fact[j-1];
        if(r!=0){
            answer.push_back(char('0'+arr[m]));
            arr.erase(arr.begin()+m);
            k-=m*fact[j-1];
            //cout<<k<<endl;
            j--;
        }
        else{
            answer.push_back(char('0'+arr[m-1]));
            arr.erase(arr.begin()+m-1);
            k-=m*fact[j-1];
            //cout<<k<<endl;
            j--;
        }
    }
    int i=arr.size()-1;
    while(i>=0){
        answer.push_back(char('0'+arr[i]));
        i--;
    }
    return answer;
}
