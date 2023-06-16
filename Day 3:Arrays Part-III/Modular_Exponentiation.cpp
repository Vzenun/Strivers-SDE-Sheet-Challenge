#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long long int a=x%m;
	long long int ans=1;
	while(n!=0){
		if(n%2==0){
			a=(a%m*a%m)%m;
			a=a%m;
			n=n/2;
		}
		else{
			ans=(ans%m*a%m)%m;
			ans=ans%m;
			n--;
		}
	}
	return (int)ans%m;
}