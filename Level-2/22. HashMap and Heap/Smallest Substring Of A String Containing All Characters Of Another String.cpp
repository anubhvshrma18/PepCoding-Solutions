#include "bits/stdc++.h"
using namespace std;

string solution(string s1,string s2){
    map<char,int>map1;
    map<char,int>map2;
        
        //freq map of s2
    for(int i=0; i < s2.length();i++) {
        char ch = s2[i];
        map2[ch]++;
    }
        
    int oans = INT_MAX;
    int oi = -1;
    int oj = -1;
    
    int i=-1,j=-1;
    
    int mtc = 0; //match count
    int dmtc = s2.length(); //desired match count
    int n = s1.length();
        
        while(i < n-1) {
            
            //1. aquire
            while(i < n-1 && mtc < dmtc) {
                i++;
                //aquire this ith char
                char ch = s1[i];
                map1[ch]++;
                //impact on match count
                if(map1[ch] <= map2[ch]) {
                    mtc++;
                }
            }
            
            
            //2. release
            while(j < i && mtc == dmtc) {
                int len = i - j;
                // cout << len << endl;
                if(len < oans) {
                    oans = len;
                    oi = i;
                    oj = j;
                }
                
                j++;
                //release jth char
                char ch = s1[j];
                
                if(map1[ch] == 1) {
                    map1.erase(ch);
                }
                else {
                    map1[ch]--;
                }

                //impact on match count
                if(map1[ch] < map2[ch]) {
                    mtc--;
                }
            }
        }
        string ans = s1.substr(oj+1 , oi+1 - (oj+1));
        return ans;
}

int main() 
{ 
  string s,t;
  cin >> s >> t;
  cout << solution(s,t) << endl;
}