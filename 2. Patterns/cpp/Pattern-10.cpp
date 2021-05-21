/*
		*	
	*		*	
*				*	
	*		*	
		*	
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int str=2;
    int nsp=n/2;
    int ns=-1;
    int ext=0;
    for(int r=1;r<=n;r++){
        
        if((r==1) || (r==n)){
            str=1;
            ext=1;
        }
        else{
            str=2;
            ext=0;
        }
        
        
        for(int i=1;i<=nsp;i++){
            cout <<"\t";
        }
        for(int i=1;i<=str-1+ext;i++){
            cout <<"*\t";
        }
        for(int i=1;i<=ns;i++){
            cout <<"\t";
        }
        for(int i=1;i<=str-1;i++){
            cout <<"*\t";
        }
        // for(int i=1;i<=nsp;i++){
        //     cout <<"\t";
        // }
        
        if(r<((n/2)+1)){
            nsp--;
            ns+=2;
        }
        if(r>=((n/2)+1)){
            nsp++;
            ns-=2;
        }
        cout <<"\n";
        
    }

    //write your code here
}

