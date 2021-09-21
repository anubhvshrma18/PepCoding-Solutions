#include<bits/stdc++.h>
using namespace std;


vector<vector<string>> groupShiftedStrings(vector<string> &v){
    map<string,vector<string>> map;
    
    for(auto s:v){
        string temp="";
        
        for(int i=1;i<s.length();i++){
            int cc=s[i]-'0',pc = s[i-1]-'0';
            int diff = (cc - pc + 26) % 26;
            temp += to_string(diff);
            temp += "@";
        }
        map[temp].push_back(s);
    }
    
    vector<vector<string>> ans;
    for(auto a:map){
        ans.push_back(a.second);
    }
    
    return ans;
    
}

void display(vector<vector<string>> &list) {
	for (auto i:list) {
		for (auto j:i) {
			cout << j  << " ";
		}
		cout << endl;
	}
}

int main() {
	int N;
	cin >> N;
	vector<string> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<vector<string>> ans = groupShiftedStrings(arr);
	for (auto i:ans) {
		sort(i.begin(),i.end());
	}
	display(ans);
}