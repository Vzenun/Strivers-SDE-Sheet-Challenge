bool searchMatrix(vector<vector<int>>& mat, int target) {
    int i=-1;
    int j=mat.size();
    while(i+1<j){
        int m=(i+j)/2;
        if(mat[m][0]<=target){
            i=m;
        }
        else{
            j=m;
        }
    }
    if(mat[i][0]==target){
        return true;
    }
    int i1=-1;
    int j1=mat[0].size();
    while(i1+1<j1){
        int m=(i1+j1)/2;
        if(mat[i][m]<=target){
            i1=m;
        }
        else{
            j1=m;
        }
    }
    if(mat[i][i1]==target){
        return true;
    }
    else{
        return false;
    }
}