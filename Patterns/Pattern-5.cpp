/*
		*	
	*	*	*	
*	*	*	*	*	
	*	*	*	
		*	
*/
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int str=1;
    for(int row=1;row<=n;row++){
        int nsp=(n-str)/2;
        for(int i=1;i<=nsp;i++){
            cout << "\t";
        }
        for(int j=1;j<=str;j++){
            cout << "*\t";
        }
        for(int i=1;i<=nsp;i++){
            cout << "\t";
        }
        if(row<((n/2)+1)){
            str=str+2;
        }
        if(row>=((n/2)+1)){
            str=str-2;
        }
        cout <<"\n";
    }
    //write your code here
    return 0;

}