#include <bits/stdc++.h>
using namespace std;

void wordBreak(string str, string ans, unordered_set<string> &set)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        string left = str.substr(0, i + 1);
        if (set.count(left) == 1)
        {
            string right = str.substr(i + 1);
            wordBreak(right, ans + left + " ", set);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    unordered_set<string> set;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        set.insert(s);
    }
    string word;
    cin >> word;
    wordBreak(word, "", set);
}