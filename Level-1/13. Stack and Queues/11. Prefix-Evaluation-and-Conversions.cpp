#include<bits/stdc++.h>
using namespace std;

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
    else{
        return i/j;
    }
}



void postfixConversion(string s){
	stack<int> ev;
	stack<string> inf;
	stack<string> pre;

	for(int i=s.length()-1;i>=0;i--){
		char ch=s[i];
		if(ch>='0' && ch<='9'){
			//pushing the values in stack
			ev.push(ch-'0');
			string str="";
			str+=ch;
			inf.push(str);
			pre.push(str);
		}
		else{
			// if operand comes this block will be executed
			// evaluation of expression
			int e1=ev.top();
			ev.pop();
			int e2=ev.top();
			ev.pop();
			int eval=evaluation(ch,e1,e2);
			ev.push(eval);

			// infix evaluation
			string i1=inf.top();
			inf.pop();
			string i2=inf.top();
			inf.pop();
			string infix="("+i1+ch+i2+")";
			inf.push(infix);

			//prefix evaluation
			string p1=pre.top();
			pre.pop();
			string p2=pre.top();
			pre.pop();
			string prefix="";
			prefix+=p1+p2+ch;
			pre.push(prefix);
		}
	}

	cout << ev.top() << endl;
	cout << inf.top() << endl;
	cout << pre.top()<< endl;
}


int main(){
	string s;
	cin >> s;
	// infixEval(s);
	postfixConversion(s);
}