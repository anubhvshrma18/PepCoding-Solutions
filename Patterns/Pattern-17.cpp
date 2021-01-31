/*---

		*	
		*	*	
*	*	*	*	*	
		*	*	
		*	
        
        
        
--*/
//code
#include <iostream>
using namespace std;
int main(int agrc, char**argv){
    int n;
    cin >> n;
    int ns1=n/2;
    int ns2=n/2;
    int str=0;
    for(int r=1;r<=n;r++){
        if(r==(n/2)+1){
            ns1=0;
            str=n;
        }
        else{
            ns1=n/2;
            str=n-ns1-ns2;
        }
        for(int i=1;i<=ns1;i++){
            cout <<"\t";
        }
        for(int i=1;i<=str;i++){
            cout <<"*\t";
        }
        for(int i=1;i<=ns2;i++){
            cout <<"\t";
        }
        
        if(r<(n/2)+1){
            ns2--;
        }
        if(r>=(n/2)+1){
            ns2++;
        }
        cout <<"\n";
    }

    //write your code here
    
}