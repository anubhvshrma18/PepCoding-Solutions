/*
*	*	*	*	*	*	*	
	*				*		
		*		*			
			*				
		*	*	*			
	*	*	*	*	*		
*	*	*	*	*	*	*	

*/
#include <iostream>
using namespace std;
int main(int agrc, char**argv){
    int n;
    cin >> n;
    //upper half
    for(int r=1;r<=n/2;r++){
        for(int i=1;i<=n;i++){
            if(r==1 || r==n){
                cout <<"*\t";
            }
            else if(r==i || r+i==n+1){
               cout <<"*\t"; 
            }
            else{
                cout <<"\t";
            }
        }
        cout <<"\n";
    }
    //lower half pyramid
    int spc=n/2;
    int str=1;
    for(int r=(n/2)+1;r<=n;r++){
        
        for(int i=1;i<=spc;i++){
            cout <<"\t";
        }
        for(int i=1;i<=str;i++){
            cout <<"*\t";
        }
        for(int i=1;i<=spc;i++){
            cout <<"\t";
        }
        spc--;
        str+=2;
        cout <<"\n";
    }

    //write your code here
    
}