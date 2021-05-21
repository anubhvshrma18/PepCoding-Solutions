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

int evaluation(char ch,int i,int j){
    if(ch=='+'){
        return i+j;
    }
    else if(ch=='-'){
        return i-j;
    }
    else if(ch=='*'){
        return i*j;
    }
    else if(ch=='/'){
        return i/j;
    }
    else{
        return 0;
    }
}

void infixEval(string s){
	stack<char> oprtr;
	stack<int> ev;
	for(int i=0;i<s.length();i++){
		char ch=s[i];
        // cout << s[i] << endl;
		if(ch=='('){
			oprtr.push(ch);
		}
		else if(ch>='0' && ch<='9'){
			ev.push(ch-'0');
		}
		else if(ch==')'){
			while(oprtr.top()!='('){
				char ch=oprtr.top();
				oprtr.pop();
				int e1=ev.top();
				ev.pop();
				int e2=ev.top();
				ev.pop();

				int ans=evaluation(ch,e2,e1);
				ev.push(ans);
			}
			oprtr.pop();
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch =='/'){
			while(oprtr.size()>0 && oprtr.top()!='(' && precedence(ch)<=precedence(oprtr.top())){
				char ch=oprtr.top();
				oprtr.pop();
				int e1=ev.top();
				ev.pop();
				int e2=ev.top();
				ev.pop();

				int ans=evaluation(ch,e2,e1);
				ev.push(ans);
			}
			oprtr.push(ch);
		}
	}
	while(oprtr.size()>0){
		char ch=oprtr.top();
		oprtr.pop();
		int e1=ev.top();
		ev.pop();
		int e2=ev.top();
		ev.pop();

		int ans=evaluation(ch,e2,e1);
		ev.push(ans);
	}
	cout << ev.top() << endl;
}

int main(){
	string s;
	getline(cin , s);
	// cout << s;
	infixEval(s);
	// postfixConversion(s);
}