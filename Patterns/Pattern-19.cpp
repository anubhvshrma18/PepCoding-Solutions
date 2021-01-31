/*
*	*	*		*	
		*		*	
*	*	*	*	*	
*		*			
*		*	*	*	

*/
#include <iostream>
using namespace std;
int main(int argc, char** argv){
    int n;
    cin >> n;
    // int str=2;
    // int nsp2=n/2;
    // int nsp1=(n/2)-1;
    // int str2=1;
    for(int r=1;r<=n;r++){
        for(int j=1;j<=n;j++){
            if(r==1 && (j==n || j<=(n/2)+1)){
                cout << "*\t";
            }
            else if(r<=(n/2) && (j==n || j==(n/2)+1)){
                cout <<"*\t";
            }
            else if(r==(n/2)+1){
                cout << "*\t";
            }
            else if(r>(n/2)+1 && (j==1 || j==(n/2)+1)){
                cout << "*\t";
            }
            else if(r==n && (j==1 || j>=(n/2)+1)){
                cout <<"*\t";
            }
            else{
                cout <<"\t";
            }
        }
        cout <<"\n";
 
    }
 
}