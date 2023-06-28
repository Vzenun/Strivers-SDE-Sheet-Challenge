#include <bits/stdc++.h> 

vector<string> ans2;

void kom(string st,string s){
	if(s.size()!=0){
		for(int i=0;i<s.size();i++){
            st.push_back(s[i]);
            kom(st,s.substr(0,i)+s.substr(i+1));
            st.pop_back();
		}
	}
    else{
        ans2.push_back(st);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    string st;
    kom(st,s);
    ans=ans2;
    ans2.clear();
    return ans;
}