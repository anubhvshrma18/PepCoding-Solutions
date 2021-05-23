#include<iostream>
using namespace std;
int main(int argc, char**argv){
    int marks;
    cin>>marks;
    if (marks > 90) {
        cout<<"excellent" << endl;
    }
    else if (marks > 80 && marks <= 90) {
        cout << "good" <<endl;
    }
    else if (marks > 70 && marks <= 80) {
        cout<<"fair"<<endl;
    } 
    else if (marks > 60 && marks <= 70) {
        cout<<"meets expectations"<<endl;
    } 
    else{
        cout<<"below par"<<endl;
    }
    
    //write your code here
    return 0;
    
}