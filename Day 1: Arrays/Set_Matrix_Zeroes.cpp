#include <bits/stdc++.h>

void setZeros(vector<vector<int> > &matrix)
{
	// Write your code here.
	vector<int> row(matrix.size(),0);
	vector<int> column(matrix[0].size(),0);
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[0].size();j++){
			if(matrix[i][j]==0){
				row[i]=1;
				column[j]=1;
			}
		}
	}
	for(int i=0;i<matrix.size();i++){
		if(row[i]==1){
			for(int j=0;j<matrix[0].size();j++){
				matrix[i][j]=0;
			}
		}
	}
	for(int i=0;i<matrix[0].size();i++){
		if(column[i]==1){
			for(int j=0;j<matrix.size();j++){
				matrix[j][i]=0;
			}
		}
	}
}