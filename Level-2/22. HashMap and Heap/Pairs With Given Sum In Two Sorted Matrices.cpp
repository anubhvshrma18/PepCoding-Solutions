#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(vector<vector<int>> &nums1, vector<vector<int>> &nums2, int k)
{
    
    unordered_map<int,int> m1,m2;
    for(auto i:nums1){
        for(auto j:i){
            m1[j]++;
        }
    }
    for(auto i:nums2){
        for(auto j:i){
            m2[j]++;
        }
    }
    int cnt=0;
    for(auto m:m2){
        int val = k - m.first;
        if(m1.find(val)!=m1.end()){
            cnt+= m1[val]*m.second;
        }
    }
    return cnt;
}




int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr1(n, vector<int>(n, 0));
    for (int i = 0; i < arr1.size(); i++){
        for (int j = 0; j < arr1[0].size(); j++){
            cin >> arr1[i][j];
        }
    }

    vector<vector<int>> arr2(n, vector<int>(n, 0));
    for (int i = 0; i < arr2.size(); i++){
        for (int j = 0; j < arr2[0].size(); j++){
            cin >> arr2[i][j];
        }
    }

    int k;
    cin >> k;
    cout << solve(arr1,arr2,k) << endl;
    return 0;
}
