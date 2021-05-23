#include <bits/stdc++.h> 
using namespace std;
void printIncreasing(int n){
    if (n < 1) {
        return;
    }
    printIncreasing(n - 1);
    cout << n << endl;
}
int main() 
{ 
   int n;
   cin >> n;
   printIncreasing(n);
   return 0; 
}
