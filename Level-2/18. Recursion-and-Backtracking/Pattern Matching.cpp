#include <bits/stdc++.h>
using namespace std;

void solution(string str, int idx, string p, unordered_map<char, string> &mp)
{
    if (idx == p.length())
    {
        if (str.length() == 0)
        {
            unordered_set<char> st;
            for (int i = 0; i < p.length(); i++)
            {
                char ch = p[i];
                if (st.count(ch) == 0)
                {
                    cout << ch << " -> " << mp[ch] << ", ";
                    st.insert(ch);
                }
            }
            cout << "." << endl;
        }
        return;
    }

    char ch = p[idx];

    if (mp.find(ch) != mp.end())
    {
        string lmp = mp[ch];
        if (str.length() < lmp.length())
        {
            return;
        }

        string cmp = str.substr(0, lmp.length());
        if (lmp != cmp)
        {
            return;
        }

        string right = str.substr(lmp.length());
        solution(right, idx + 1, p, mp);
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            string left = str.substr(0, i + 1);
            string right = str.substr(i + 1);

            mp[ch] = left;
            solution(right, idx + 1, p, mp);
            mp.erase(ch);
        }
    }
}

int main()
{
    string str, pattern;
    cin >> str >> pattern;
    unordered_map<char, string> mp;
    solution(str, 0, pattern, mp);
}