#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    if(ques.length()==0){
        cout << ans << endl;
        return;
    }
    int len=ques.length();
    string emp="";
    emp+=ques[0];
    string sub=ques.substr(1);
    printSS(sub,ans+emp);
    printSS(sub,ans);
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}