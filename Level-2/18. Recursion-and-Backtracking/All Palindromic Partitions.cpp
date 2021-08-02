#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
  int l=0,r=s.length()-1;
  while(l<r){
    if(s[l]!=s[r]){
      return false;
    }
    l++,r--;
  }
  return true;
}


void solution(string str,string asf){
  if(str.length()==0){
    cout << asf << endl;
    return;
  }

  for(int i=0;i<str.length();i++){
    string s=str.substr(0,i+1);

    if(isPalindrome(s)){
      string ls=str.substr(i+1);
      solution(ls,asf+"("+s+") ");
    }
  }


}

int main(){
  string s;
  cin >> s;
  solution(s,"");
  return 0; 
}