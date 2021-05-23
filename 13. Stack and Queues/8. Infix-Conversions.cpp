#include <bits/stdc++.h>
using namespace std;

int precedence(char ch){
	if(ch=='+' || ch=='-'){
		return 1;
	}
	else if(ch=='*' || ch=='/'){
		return 2;
	}
	else{
		return 0;
	}
}

void infixConversion(string s){
	stack<string> pre;
	stack<string> post;
	stack<char> oprtr;

	for(int i=0;i<s.length();i++){

		if(s[i]=='('){
			oprtr.push(s[i]);
		}
		else if(s[i]==')'){
			while(oprtr.top()!='('){
				char opt=oprtr.top();
				oprtr.pop();

				string val2=pre.top();
				pre.pop();
				string val1=pre.top();
				pre.pop();
				string preval="";
				preval+=(opt);
				preval+=(val1);
				preval+=(val2);
				pre.push(preval);
				
				string pval2=post.top();
				post.pop();
				string pval1=post.top();
				post.pop();
				string postval="";
				postval+=(pval1);
				postval+=(pval2);
				postval+=(opt);
				post.push(postval);
			}
			oprtr.pop();
		}
		else if(s[i]>='0' && s[i]<='9' || s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
			string str="";
			str+=s[i];
			pre.push(str);
			post.push(str);
		}
		else if(s[i]=='+' || s[i]=='-' ||s[i]=='/' ||s[i]=='*'){
			while(oprtr.size()>0 && oprtr.top()!='(' && precedence(s[i]) <= precedence(oprtr.top())){
				char opt=oprtr.top();
				oprtr.pop();

				string val2=pre.top();
				pre.pop();
				string val1=pre.top();
				pre.pop();
				string preval="";
				preval+=(opt);
				preval+=(val1);
				preval+=(val2);
				pre.push(preval);
				
				string pval2=post.top();
				post.pop();
				string pval1=post.top();
				post.pop();
				string postval="";
				postval+=(pval1);
				postval+=(pval2);
				postval+=(opt);
				post.push(postval);
			}
			oprtr.push(s[i]);
		}
	}
	while(oprtr.size()>0){
		char opt=oprtr.top();
		oprtr.pop();

		string val2=pre.top();
		pre.pop();
		string val1=pre.top();
		pre.pop();
		string preval="";
		preval+=(opt);
		preval+=(val1);
		preval+=(val2);
		pre.push(preval);
		
		string pval2=post.top();
		post.pop();
		string pval1=post.top();
		post.pop();
		string postval="";
		postval+=(pval1);
		postval+=(pval2);
		postval+=(opt);
		post.push(postval);
	}

    cout << post.top() << endl;
	cout << pre.top() << endl;
	

}

int main(){
	string s;
	cin >> s;

	infixConversion(s);
	return 0;
}