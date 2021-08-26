#include<bits/stdc++.h>
using namespace std;

map<string,string> p;
map<string,int> r;
string find(string x){
    if(p[x]==x){
        return x;
    }

    return p[x]=find(p[x]);
}
bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs){
        // 

    for(int i=0;i<pairs.size();i++){
        string w1=pairs[i][0];
        string w2=pairs[i][1];

        if(p.find(w1)==p.end()){
            p[w1]=w1;
            r[w1]=0;
        }
        if(p.find(w2)==p.end()){
            p[w2]=w2;
            r[w2]=0;
        }


        string lx=find(w1);
        string ly=find(w2);

        if(lx!=ly){
            if(r[lx]<r[ly]){
                p[lx]=ly;

            }
            else if(r[lx] > r[ly]){
                p[ly]=lx;
            }
            else{
                p[lx]=ly;
                r[ly]++;
            }
        }
    }


    if(words1.size() != words2.size()){
        return false;
    }

    for(int i=0;i<words1.size();i++){
        string w1= words1[i];
        string w2=words2[i];

        if(w1==w2){
            continue;
        }

        if(p.find(w1)==p.end() || p.find(w2)==p.end() || p[w1]!=p[w2] ){
            return false;
        }
    }

    return true;
}

int main(){
    int n;;
    cin >> n;
    vector<string> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int m;
    cin >> m;
    vector<vector<string>> pair(m,vector<string>(2));
    for(int i=0;i<m;i++){
        cin >> pair[i][0] >> pair[i][1];
    }
    
    if(areSentencesSimilarTwo(a,b,pair)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}