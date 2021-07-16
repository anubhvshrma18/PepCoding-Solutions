#include<iostream>
using namespace std;

int main(){
    int n,count=0,d;
    cin >> n >> d;
    while(n>0){
        if(n%10==d){
            count++;
        }
        n/=10;
    }
    cout << count << endl;
}