


#include<iostream>

using namespace std;

int getSum(int b, int n1, int n2) {
    // write your code here
    int ans=0,carry=0,p=1;
    while(n1>0 || n2>0 || carry!=0){
        int ld=n1%10;
        int rd=n2%10;
        n1=n1/10;
        n2=n2/10;
        
        int sum=ld+rd+carry;
        int val=sum%b;
        carry=sum/b;
        ans=ans+val*p;
        p=p*10;
    }
    
    return ans;
    
    
}


int main() {
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << getSum(b, n1, n2) << endl;
}