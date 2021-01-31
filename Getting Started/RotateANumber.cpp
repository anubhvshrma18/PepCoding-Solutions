#include <iostream>
#include<cmath>

using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int count = 0, sum = 0;
    int tem = n;
    while (tem > 0) {
        tem = tem / 10;
        count++;
    }
    // System.out.println(count);
    k = k % count;
    if (k < 0) {
        // k=Math.abs(k)%count;
        k = k + count;
    }
    int temp = k;
    while (k > 0) {
        int rem = n % 10;
        sum = sum * 10 + rem;
        n /= 10;
        k--;
    }
    while (temp > 0) {
        cout<< sum % 10;
        sum /= 10;
        temp--;
    }
    cout << n << "\n";
    
    //write your code here

}