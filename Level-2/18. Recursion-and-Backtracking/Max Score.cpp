#include "bits/stdc++.h"
using namespace std;

int maxscore(vector<string> &v, vector<int> &fre, vector<int> &score, int idx)
{
    //base case
    if (idx == v.size())
    {
        return 0;
    }

    int nans = maxscore(v, fre, score, idx + 1);

    int awcv = 0;
    int li = v[idx].length();
    for (int i = 0; i < v[idx].length(); i++)
    {
        char ch = v[idx][i];
        if (fre[ch - 'a'] > 0)
        {
            fre[ch - 'a']--;
        }
        else
        {
            li = i;
            break;
        }
        awcv += score[ch - 'a'];
    }

    int rans = 0;
    int ans = nans;
    if (li == v[idx].length())
    {
        rans = maxscore(v, fre, score, idx + 1);
        ans = max(nans, rans + awcv);
    }
    for (int i = 0; i < li; i++)
    {
        char ch = v[idx][i];
        fre[ch - 'a']++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int l;
    cin >> l;
    vector<char> letters(l);
    for (int i = 0; i < l; i++)
    {
        cin >> letters[i];
    }
    vector<int> score(26);
    for (int i = 0; i < 26; i++)
    {
        cin >> score[i];
    }

    vector<int> fre(26);
    for (char ch : letters)
    {
        fre[ch - 'a']++;
    }

    cout << maxscore(v, fre, score, 0);
}