#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> r;

int find(int x){
    if(parent[x] == x){
        return x;
    }

    int temp = find(parent[x]);
    parent[x]=temp;
    return temp;
}

vector<int> redundantConnection(vector<vector<int>> &pos){
    int n = pos.size();
    r.resize(n+1);
    parent.resize(n+1);

    for(int i=1;i<=n;i++){
        r[i]=0;
        parent[i]=i;
    }


    for(vector<int> edge:pos){
        int u=edge[0];
        int v=edge[1];

        int lu = find(u);
        int lv = find(v);

        if(lu != lv){
            if(r[lu] < r[lv]){
                parent[lu] = lv;
            }
            else if(r[lu] > r [lv]){
                parent[lv]=lu;
            }
            else{
                parent[lu] = lv;
                r[lv]++;
            }
        }
        else{
            vector<int> ans{u,v};
            return ans;
        }
    }
    return {};
}



int main(){
    int n;
    cin >> n;
    vector<vector<int>> pos(n,vector<int>(2));
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        pos[i][0]=a;
        pos[i][1]=b;
    }
    
    vector<int> ans = redundantConnection(pos);
    cout << ans[0] << " " << ans[1] << endl;
}