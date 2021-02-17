#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    vector<int> res;
    int i=0,j=0;
    while(i<A.size() && j<B.size()){
        if(A[i]<B[j]){
            res.push_back(A[i]);
            i++;
        }
        else if(A[i]==B[j]){
            res.push_back(A[i]);
            res.push_back(B[j]);
            i++;
            j++;
        }
        else{
            res.push_back(B[j]);
            j++;

        }
    }
    while(i<A.size()){
        res.push_back(A[i]);
        i++;
    }
    while(j<B.size()){
        res.push_back(B[j]);
        j++;
    }
    return res;
}

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    cin >> m;
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    return 0;
}