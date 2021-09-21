class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> map;
        for(auto m:wall){
            int ps=0;
            for(int i=0;i<m.size()-1;i++){
                ps+=m[i];
                map[ps]++;
            }
        }
        int mx=0;
        for(auto m:map){
            if(m.second  > mx){
                mx=m.second;
            }
        }
        return wall.size()-mx;
    }
};