#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> ans;
  vector<long long int> a;
  int num=0;
  while(num!=n){
    if(num==0){
      a.push_back(1);
      ans.emplace_back(a);
    }
    else if(num==1){
      a.push_back(1);
      a.push_back(1);
      ans.emplace_back(a);
    }
    else{
      vector<long long int> a1=ans[ans.size()-1];
      a.emplace_back(1);
      for(int i=0;i<a1.size()-1;i++){
        a.emplace_back(a1[i+1]+a1[i]);
      }
      a.emplace_back(1);
      ans.emplace_back(a);
    }
    a.clear();
    num++;
  }
  return ans;
}
