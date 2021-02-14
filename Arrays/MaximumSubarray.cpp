#include<iostream>
#include<climits>
#include<vector>

using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input an integer array. It should return the required sum.
int maxSum(vector < int > & arr) {
    // write your code here.
    int sum=INT_MIN,curr_sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];
        if(sum<curr_sum){
            sum=curr_sum;
        }
        if(curr_sum<0){
            curr_sum=0;
        }
    }
    return sum;
}

int main(int argc, char ** argv) {
    int n;
    cin >> n;
    vector < int > A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << maxSum(A) << endl;
}