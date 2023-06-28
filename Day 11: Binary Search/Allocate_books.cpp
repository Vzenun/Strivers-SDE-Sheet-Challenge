#include <bits/stdc++.h> 
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long i=0;
	long long j=0;
	for(int i=0;i<m;i++){
		j+=time[i];
	}
	j+=10;
	while(i+1<j){
		long long m2=(i+j)/2;
		long long m1=m2;
		long long day=0;
		long long ctr=0;
		while(day<n && ctr<m){
			m1=m2;
			while(ctr<m){
				if(m1>=time[ctr]){
					m1-=time[ctr];
					ctr++;
				}
				else{
					break;
				}
			}
			day++;
		}
		if(ctr==m){
			j=m2;
		}
		else{
			i=m2;
		}
	}
	return j;
}