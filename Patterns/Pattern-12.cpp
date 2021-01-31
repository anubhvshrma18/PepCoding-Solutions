/*
0	
1	1	
2	3	5	
8	13	21	34	
55	89	144	233	377	
*/
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int fi=0,fy=1;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=r;c++){
            cout << fi << "\t";
            int x=fi+fy;
            fi=fy;
            fy=x;
        }
        cout << "\n";
    }
    //write your code here
    
}