/*
1												1	
1	2										2	1	
1	2	3								3	2	1	
1	2	3	4						4	3	2	1	
1	2	3	4	5				5	4	3	2	1	
1	2	3	4	5	6		6	5	4	3	2	1	
1	2	3	4	5	6	7	6	5	4	3	2	1
*/
#include <iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin >> n;
    int c=2*n-1;
    for(int r=1;r<=n;r++){
        int str=r;
        int nsp=c-2*str;
        int num=1;
        for(int i=1;i<=str;i++){
            cout << num << "\t";
            num++;
        }
        for(int i=1;i<=nsp;i++){
            cout << "\t";
        }
        if(r==n){
            num--;
            str--;
        }
        for(int i=1;i<=str;i++){
            num--;
            cout << num <<"\t";
            
        }
        cout <<"\n";
    }

    //write your code here
    
}