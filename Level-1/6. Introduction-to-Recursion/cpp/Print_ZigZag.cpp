#include <bits/stdc++.h> 
using namespace std;

void pzz(int n){
    if(n==0){
        return;
    }
    cout << n << " ";
    pzz(n-1);
    cout << n << " ";
    pzz(n-1);
    cout << n << " ";
}
int main() 
{ 
   
   return 0; 
}
