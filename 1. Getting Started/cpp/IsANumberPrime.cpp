#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,flag=0;
        cin >> n;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout << "not prime" << endl;
        }
        else{
            cout << "prime" << endl;
        }
    }
    return 0;

    //write your code here
    
}