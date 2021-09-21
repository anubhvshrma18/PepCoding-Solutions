class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> map;
        for(auto c:deck) map[c]++;
        int mn=0;
        for(auto m:map){
            mn=__gcd(mn,m.second);    
        }
        
        return mn>=2;
        
    }
};