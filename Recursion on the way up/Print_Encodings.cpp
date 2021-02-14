#include <iostream>
#include<string>
using namespace std;

string codes[]={"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
void printEncoding(string str, string asf){
    // write your code here
    if(str.length()==0){
        cout << asf << endl;
        return;
    }
    if(str[0]=='0'){
        return;
    }
    int idx=int(str[0]-'0');
    string emp="";
    string opt=codes[str[0]-'0'];
    emp+=opt;
    printEncoding(str.substr(1),asf+emp);
    if(str.length()>=2){
        string val=str.substr(0,2);
        int v=stoi(val);
        if(v<=26){
            string get=codes[v];
            printEncoding(str.substr(2),asf+get);
        }
    }
    
    
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}