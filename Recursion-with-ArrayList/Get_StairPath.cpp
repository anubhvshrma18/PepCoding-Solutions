#include<bits/stdc++.h>
using namespace std;


vector<string> getPath(int n){
    if(n<=0){
        vector<string> v;
        v.push_back("");
        return v;
    }
    vector<string> ouput;
    if(n-1>=0){
        vector<string> nm1 = getPath(n-1);
        for(int i=0;i<nm1.size();i++){
            ouput.push_back("1"+nm1[i]);
        }
        
    }
    if(n-2 >=0){
        vector<string> nm2 = getPath(n-2);
        for(int i=0;i<nm2.size();i++){
            ouput.push_back("2"+nm2[i]);
        }
    }
    if(n-3 >=0){
        vector<string> nm3 = getPath(n-3);    
        for(int i=0;i<nm3.size();i++){
            ouput.push_back("3"+nm3[i]);
        }
        
    }
    return ouput;
}

int main(){
    int n;
    cin >> n;
    vector<string> res=getPath(n);
    int cnt=0;
    cout << "[";
    for(string y:res){
        if(cnt!=res.size()-1){
            cout << y << ", ";
            cnt++;
        }
        else{
            cout << y;
        }
    }
    cout <<"]";
    
}