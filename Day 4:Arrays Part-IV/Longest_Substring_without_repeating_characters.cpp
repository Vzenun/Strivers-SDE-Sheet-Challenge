#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    map<char,int> mpt;
    int answer=1;
    int count=0;
    int j=0;
    for(int i=0;i<input.size();i++){
        if(mpt[input[i]]==0){
            mpt[input[i]]=1;
            count++;
            answer=max(count,answer);
        }
        else{
            while(j<i && input[j]!=input[i]){
                count--;
                mpt[input[j]]=0;
                j++;
            }
            j++;
            answer=max(count,answer);
        }
    }
    answer=max(count,answer);
    return answer;
}