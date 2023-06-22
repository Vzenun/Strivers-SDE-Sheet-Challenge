#include <bits/stdc++.h> 
vector<vector<string>> ans2;

bool check(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}

void kom(vector<string> ans,string s,int i1){
	if(s.size()!=0){
		for(int i=0;i<s.size();i++){
            string st=s.substr(0,i+1);
            if(check(st)){
                ans.emplace_back(st);
                kom(ans,s.substr(i+1),i+1);
                ans.pop_back();
            }
		}
	}
    else{
        ans2.push_back(ans);
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<string> ans;
    kom(ans,s,0);
    vector<vector<string>> a1=ans2;
    ans2.clear();
    return a1;
}