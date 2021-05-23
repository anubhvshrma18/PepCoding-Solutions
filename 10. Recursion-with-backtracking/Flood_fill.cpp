#include<iostream>
#include<vector>

using namespace std;

void floodfill(vector<vector<int>> maze,int sr,int sc,vector<vector<bool>> visited,string asf) {
    if(sr==maze.size()-1 && sc==maze[0].size()-1){
        cout << asf << endl;
        return;
    }
    if(sr<0 || sc<0 || sr>=maze.size() || sc>=maze[0].size()|| maze[sr][sc] == 1 || visited[sr][sc]==true ){
        return;
    }
    visited[sr][sc] = true;
    floodfill(maze,sr-1,sc,visited,asf+"t");
    floodfill(maze,sr,sc-1,visited,asf+"l");
    floodfill(maze,sr+1,sc,visited,asf+"d");
    floodfill(maze,sr,sc+1,visited,asf+"r");
    visited[sr][sc] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    vector<vector<bool>> vis(n,vector<bool> (m));
    floodfill(arr,0,0,vis,"");
}