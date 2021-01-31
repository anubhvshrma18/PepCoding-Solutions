/*--

*	*	*		*	*	*	
*	*				*	*	
*						*	
*	*				*	*	
*	*	*		*	*	*	

--*/
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    int nsp=1;
    for(int r=1;r<=n;r++){
        int str=(n-nsp)/2;
        for(int i=1;i<=str+1;i++){
            cout << "*\t";
        }
        for(int i=1;i<=nsp;i++){
            cout <<"\t";
        }
        for(int i=1;i<=str+1;i++){
            cout << "*\t";
        }
        if(r<((n/2)+1)){
            nsp+=2;
        }
        if(r>=((n/2)+1)){
            nsp-=2;
        }
        cout <<"\n";
    }

    //write your code here
    
}