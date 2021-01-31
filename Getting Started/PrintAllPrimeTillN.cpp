#include <iostream>
using namespace std;
int main(int argc, char **argv){
    int low, high;
    cin >> low >> high;

    //write your code here
    for(int i=low;i<=high;i++){
        int flag=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout << i << endl; 
        }
    }

}