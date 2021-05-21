#include<bits/stdc++.h>
using namespace std;

void fun(string s){
	int cnt=1;
	stack<int> st;
	for(int i=0;i<s.length();i++){
		char ch=s[i];
		if(s[i]=='d'){
			st.push(cnt);
			cnt++;
		}
		else if(ch=='i'){
			st.push(cnt);
			cnt++;
			while(st.size()>0){
				cout << st.top();
				st.pop();
			}

		}
	}
	st.push(cnt);
	while(st.size()>0){
	    cout << st.top();
	    st.pop();
	}
	
}

int main(){
    string s;
    cin >> s;
    fun(s);
}