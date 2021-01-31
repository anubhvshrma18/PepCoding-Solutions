/*
*	
	*	
		*	
			*	
				*	
*/
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            if(r==c){
                cout <<"*\t";
            }
            else{
                cout <<"\t";
            }
        }
        cout <<"\n";
    }

    //write your code here
    
}