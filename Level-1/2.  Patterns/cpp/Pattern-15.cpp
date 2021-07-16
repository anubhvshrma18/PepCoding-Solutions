/*
		1	
	2	3	2	
3	4	5	4	3	
	2	3	2	
		1	

*/
#include <iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin >> n;
    int str=1;
    
    for(int row=1;row<=n;row++){
        int num=row;
        if(row>(n/2)+1){
            num=n-row+1;
        }
        int nsp=(n-str)/2;
        for(int i=1;i<=nsp;i++){
            cout << "\t";
        }
        for(int j=1;j<=str;j++){
            if(j>(str/2)+1){
                num--;
            }
            cout <<num<< "\t";
            if(j<(str/2)+1){
                num++;
            }
            
        }
        for(int i=1;i<=nsp;i++){
            cout << "\t";
        }
        if(row<((n/2)+1)){
            str=str+2;
        }
        if(row>=((n/2)+1)){
            str=str-2;
            num--;
        }
        cout <<"\n";
    }

    //write your code here
    
}