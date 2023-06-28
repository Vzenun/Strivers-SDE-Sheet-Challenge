int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n=arr.size();
	int i=-1;
	int j=arr.size();
	if(n==1){
		return arr[0];
	}
	while(i+1<j){
		int m=(i+j)/2;
		if(m>0 && m<n-1){
			if(m%2==0){
				if(arr[m]==arr[m+1]){
					i=m;
				}
				else{
					j=m;
				}
			}
			else{
				if(arr[m]!=arr[m+1]){
					i=m;
				}
				else{
					j=m;
				}
			}
		}
		else{
			if(m==0){
				if(arr[m]==arr[m+1]){
					i=m;
				}
				else{
					j=m;
				}
			}
			else{
				j=m;
			}
		}
	}
	return arr[j];
}