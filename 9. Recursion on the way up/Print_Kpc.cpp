#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // write your code here
    if(ques.length()==0){
        cout << asf << endl;
    }
    string z=codes[ques[0]-'0'];
    for(int i=0;i<z.length();i++){
        string e="";
        e+=z[i];
        printKPC(ques.substr(1),asf+e);
    }
    
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}