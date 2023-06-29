string reverseString(string &str){
	// Write your code here.
	vector<string> arr;
	int n = str.size();
	string s;
	for(int i=0;i<n;i++){
		string t="";
		while(str[i]!=' ' && i<n){
            t.push_back(str[i++]);
		}
		if(!t.empty()){
            arr.push_back(t);
		}
	}

	for(int i=arr.size()-1;i>=0;i--){
		if(i!=0){
			s.append(arr[i]);
			s.push_back(' ');
		}
		else{
			s.append(arr[i]);
		}
	}
	return s;
}