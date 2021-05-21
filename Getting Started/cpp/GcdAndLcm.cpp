#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(int argc, char **argv){
    int num1, num2;
    cin >> num1 >> num2;
    
    int y= gcd(num1,num2);
    int x=(num1*num2)/y;
    //write your code here
    cout << y << " "<< x <<endl;
    return 0;
}