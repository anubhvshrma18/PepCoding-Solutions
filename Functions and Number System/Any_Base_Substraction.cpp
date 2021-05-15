#include<iostream>
using namespace std;

int getDifference(int b, int n1, int n2){
    // write your code here
    int ans=0,p=1,borrow=0;
    while(n2>0){
        int ld=n1%10;
        int rd=n2%10;
        n1=n1/10;
        n2=n2/10;
        
        int val=(rd+borrow)-ld;
        if(val<0){
            val=val+b;
            borrow=-1;
        }
        else{
            borrow=0;
        }
        
        ans=ans+val*p;
        p=p*10;
    }
    return ans;
    
}


int main(){
    int b, n1, n2;
    cin>>b>>n1>>n2;
    cout << getDifference(b,n1,n2);
}