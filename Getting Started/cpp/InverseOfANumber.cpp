#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int x=0,count=0;
    int temp=n;
    while(n>0){
        n=n/10;
        count++;
    }
    for(int i=1;i<=count;i++){
        x=x+i*pow(10,(temp%10)-1);
        temp=temp/10;
    }
    cout << x << endl;
    return 0;    
}