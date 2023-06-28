int search(int* arr, int n, int key) {
    // Write your code here.
    int flag=0;
    int i=-1;
    int j=n;
    while(i+1<j){
        int m=(i+j)/2;
        if(m>0 && m<n-1){
            if(arr[m]<arr[m+1] && arr[m]>arr[m-1]){
                if(arr[m]>arr[0]){
                    i=m;
                }
                else{
                    j=m;
                }
            }
            else if(arr[m]>arr[m+1]){
                flag=m+1;
                break;
            }
            else{
                flag=m;
                break;
            }
        }
        else{
            if(m==0){
                flag=1;
            }
            else{
                flag=0;
            }
            break;
        }
    }
    i=-1;
    j=n;
    while(i+1<j){
        int m=(i+j)/2;
        int m1=(m+flag)%n;
        if(arr[m1]<=key){
            i=m;
        }
        else{
            j=m;
        }
    }
    if(i==-1 || arr[(i+flag)%n]!=key){
        return -1;
    }
    else{
        return (i+flag)%n;
    }
}