
bool check(vector<vector<int>> arr ,int i1,int j1,int n){
    for(int i=0;i<j1;i++){
        if(arr[i1][i]==1){
            return false;
        }
    }
    int i=i1-1;
    int j=j1-1;
    while(i>=0 && j>=0){
        if(arr[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    i=i1+1;
    j=j1-1;
    while(i<n && j>=0){
        if(arr[i][j]==1){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void kom(int count,int n,vector<vector<int>> arr,vector<vector<int>> &ans){
    if(count==n){
        vector<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s.emplace_back(arr[i][j]);
            }
        }
        ans.push_back(s);
    }
    else{
        for(int i=0;i<n;i++){
            if(check(arr,i,count,n)){
                arr[i][count]=1;
                kom(count+1,n,arr,ans);
                arr[i][count]=0;
            }
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> arr(n,vector<int>(n,0));
    vector<vector<int>> ans;
    kom(0,n,arr,ans);
    return ans;
}