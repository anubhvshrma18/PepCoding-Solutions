#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int lengthOfLongestSubstring (string &s) {
 //Write your code here 
    int i=-1,j=-1;
    int n=s.length();
    
    int ans =-1;
    map<char,int> mp;
    while(i<n-1){
        //acquire
        while(i<n-1){
            i++;
            mp[s[i]]++;
            
            if(mp[s[i]]>1){
                break;
            }
            else{
                ans = max(ans,i-j);
            }
        }
        
        while(j < i){
            j++;
            if(mp[s[j]]==2){
                mp[s[j]]--;
                ans = max(ans,i-j);
                break;
            }
            else{
                mp[s[j]]--;
            }
        }
    }
    return ans;
}
 
int main(int argc,char** argv){
 string s;
 cin>>s;
 cout<<lengthOfLongestSubstring(s)<<endl;
}