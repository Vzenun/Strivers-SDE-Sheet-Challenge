bool check(vector<vector<int>> &arr,vector<int> &colors,int n,int i){
    for(int j=0;j<n;j++){
        if(arr[i][j]==1 && colors[j]==colors[i]){
            return false;
        }
    }
    return true;
}

bool kom(vector<vector<int>> &arr,vector<int> &colors,int i1,int n,int m){
    if(i1==n){
        return true;
    }
    if(colors[i1]==-1){
        for(int i=0;i<m;i++){
            colors[i1]=i;
            if(check(arr,colors,n,i1)){
                if(kom(arr,colors,i1+1,n,m)){
                    return true;
                }
            }
            colors[i1]=-1;
        }
        return false;
    }
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int> colors(n,-1);
    if(kom(mat,colors,0,n,m)){
        return "YES";
    }
    else{
        return "NO";
    }
}