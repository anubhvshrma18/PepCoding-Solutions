/*
1	
1	1	
1	2	1	
1	3	3	1	
1	4	6	4	1	
*/
#include <iostream>
using namespace std;
int permutation(int n,int r){
    if(r==0 || n==0){
        return 1;
    }
    if(n==r){
        return 1;
    }
    int nfact=1,rfact=1,nrfact=1;
    for(int i=1;i<=n;i++){
        nfact*=i;
    }
    for(int i=1;i<=n-r;i++){
        nrfact*=i;
    }
    for(int i=1;i<=r;i++){
        rfact*=i;
    }
    return nfact/(rfact*nrfact);
}

int main(int argc, char **argv){
    int n;
    cin >> n;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=r;c++){
            cout << permutation(r-1,c-1) <<"\t";
        }
        cout <<"\n";
    }
    
    //write your code here
    
}
