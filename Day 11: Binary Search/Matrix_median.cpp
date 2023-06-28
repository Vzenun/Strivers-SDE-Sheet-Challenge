int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int i=0;
    int j=100001;
    int n=matrix.size();
    int target=matrix.size()*matrix[0].size();
    target=target/2+1;
    while(i+1<j){
        int m=(i+j)/2;
        int sum=0;
        for(int k=0;k<n;k++){
            int i1=-1;
            int j1=matrix[0].size();
            while(i1+1<j1){
                int m1=(i1+j1)/2;
                if(matrix[k][m1]<m){
                    i1=m1;
                }
                else{
                    j1=m1;
                }
            }
            sum+=matrix[0].size()-j1;
        }
        if(sum>=target){
            i=m;
        }
        else{
            j=m;
        }
    }
    return j-1;
}