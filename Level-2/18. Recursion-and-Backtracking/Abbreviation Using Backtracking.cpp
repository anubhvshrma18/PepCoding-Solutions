#include "bits/stdc++.h"
using namespace std;

void getabbreviations(string s, int idx, string asf, int ssf)
{
    if (idx == s.length())
    {
        if (ssf == 0)
        {
            cout << asf << endl;
        }
        else
        {
            cout << asf << ssf << endl;
        }
        return;
    }
    if (ssf != 0)
    {
        getabbreviations(s, idx + 1, asf + to_string(ssf) + s[idx], 0);
    }
    else
    {
        getabbreviations(s, idx + 1, asf + s[idx], 0);
    }

    // if(ssf!=0){
    // 	asf=asf.substr(0,asf.length()-1);
    // }
    // ssf=ssf+1;
    getabbreviations(s, idx + 1, asf, ssf + 1);
}

int main()
{
    string s;
    cin >> s;
    getabbreviations(s, 0, "", 0);
}