#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a>>b;
        vec.push_back(make_pair(a,b));
    }
    sort(vec.begin(),vec.end());
    for(auto x:vec){
            if(s.empty()){
                s.push(x);
            }
            else if(s.top().second >= x.first){
                s.top().second=max(s.top().second,x.second);
            }else{
                s.push(x);
            }
        
    }
    stack<pair<int,int>> st;
    while(!s.empty()){
        st.push({s.top().first,s.top().second});
        s.pop();
    }
    while(!st.empty()){
        cout << st.top().first << " " << st.top().second << endl;
        st.pop();
    }
    
}