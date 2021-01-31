/*--

*				*	
*				*	
*		*		*	
*	*		*	*	
*				*	

--*/
//code
#include <iostream>
using namespace std;
int main(int argc, char**argv){
    int n;
    cin >> n;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            if(c==1 || c==n){
                cout <<"*\t";
            }
            else if(r==c && r>(n/2)){
                cout << "*\t";
            }
            else if((r+c==n+1) && (r>=(n/2)+1)){
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