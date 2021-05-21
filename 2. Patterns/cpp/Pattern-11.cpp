/*
1	
2	3	
4	5	6	
7	8	9	10	
11	12	13	14	15
*/
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int num=1;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=r;c++){
            cout << num <<"\t";
            num++;
        }
        cout << "\n";
    }
    
    //write your code here
    
}