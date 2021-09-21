#include "bits/stdc++.h"
using namespace std;

int lengthOfLongestSubstring (string &s) {
    //Write your code here   
    map<char,int>map1;
    map<char,int>map2;
    
    for(int i=0; i < s.length();i++) {
        char ch = s[i];
        map2[ch]++;
    }
        
    int oans = INT_MAX;
    int i=-1,j=-1;
    
    int dmtc = map2.size(); //desired match count
    int n = s.length();
    while(i < n-1) {
            
            //1. aquire
        while(i < n-1 && map1.size() < dmtc) {
            i++;
            //aquire this ith char
            char ch = s[i];
            map1[ch]++;
        }
            
            
            //2. release
        while(j < i && map1.size() == dmtc) {
            int len = i - j;
            // cout << len << endl;
            if(len < oans) {
                oans = len;
            }
            
            j++;
            //release jth char
            char ch = s[j];
            
            if(map1[ch] == 1) {
                map1.erase(ch);
            }
            else {
                map1[ch]--;
            }
        }
    }
    return oans;
    
}
 
int main(int argc,char** argv){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
}