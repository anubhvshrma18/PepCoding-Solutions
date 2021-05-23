#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.length()==0){
        cout << asf << endl;
    }
    for(int i=0;i<str.length();i++){
        swap(str[0],str[i]);
        string y="";
        y+=str[0];
        printPermutations(str.substr(1),asf+y);
    }

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}