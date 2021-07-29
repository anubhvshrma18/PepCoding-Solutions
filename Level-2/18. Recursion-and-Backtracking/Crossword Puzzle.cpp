#include "bits/stdc++.h"
using namespace std;

void display(vector<vector<char>> &crossword)
{
    for (int i = 0; i < crossword.size(); i++)
    {
        for (int j = 0; j < crossword[0].size(); j++)
        {
            cout << crossword[i][j];
        }
        cout << endl;
    }
}

bool canPlaceHori(vector<vector<char>> &crossword, int i, int j, string word)
{
    int len = word.length();
    if (j > 0 && crossword[i][j - 1] != '+')
    {
        return false;
    }
    if (j + len > crossword.size() || (j + len < crossword.size() && crossword[i][j + len] != '+'))
    {
        return false;
    }
    for (int c = 0; c < len; c++)
    {
        if (crossword[i][c + j] != '-' && crossword[i][c + j] != word[c])
        {
            return false;
        }
    }

    return true;
}
bool canPlaceVerti(vector<vector<char>> &crossword, int i, int j, string word)
{
    int len = word.length();
    if (i > 0 && crossword[i - 1][j] != '+')
    {
        return false;
    }
    if (i + len > crossword.size() || (i + len < crossword.size() && crossword[i + len][j] != '+'))
    {
        return false;
    }
    for (int c = 0; c < len; c++)
    {
        if (crossword[c + i][j] != '-' && crossword[c + i][j] != word[c])
        {
            return false;
        }
    }

    return true;
}

vector<bool> placeHori(vector<vector<char>> &crossword, int i, int j, string word)
{
    int len = word.length();
    vector<bool> vis(len);
    for (int c = 0; c < len; c++)
    {
        if (crossword[i][c + j] == '-')
        {
            crossword[i][c + j] = word[c];
            vis[c] = true;
        }
    }
    return vis;
}

vector<bool> placeVertic(vector<vector<char>> &crossword, int i, int j, string word)
{
    int len = word.length();
    vector<bool> vis(len);
    for (int c = 0; c < len; c++)
    {
        if (crossword[c + i][j] == '-')
        {
            crossword[c + i][j] = word[c];
            vis[c] = true;
        }
    }
    return vis;
}

void unplaceHor(vector<vector<char>> &crossword, int i, int j, string word, vector<bool> &vis)
{
    int len = word.length();
    for (int c = 0; c < len; c++)
    {
        if (vis[c])
        {
            crossword[i][c + j] = '-';
            // vis[c]=false;
        }
    }
}

void unplaceVer(vector<vector<char>> &crossword, int i, int j, string word, vector<bool> &vis)
{
    int len = word.length();
    for (int c = 0; c < len; c++)
    {
        if (vis[c])
        {
            crossword[i + c][j] = '-';
            // vis[c]=false;
        }
    }
}

void solveCW(vector<vector<char>> &crossword, vector<string> &words, int idx)
{
    if (idx == words.size())
    {
        display(crossword);
        return;
    }

    string word = words[idx];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // if we can place the word here
            if (crossword[i][j] == '-' || crossword[i][j] == word[0])
            {
                // horizontal place
                if (canPlaceHori(crossword, i, j, word))
                {
                    vector<bool> vis = placeHori(crossword, i, j, word);
                    solveCW(crossword, words, idx + 1);
                    unplaceHor(crossword, i, j, word, vis);
                }
                // vertical place
                else if (canPlaceVerti(crossword, i, j, word))
                {
                    vector<bool> vis = placeVertic(crossword, i, j, word);
                    solveCW(crossword, words, idx + 1);
                    unplaceVer(crossword, i, j, word, vis);
                }
            }
        }
    }
}

int main()
{
    vector<vector<char>> crossword(10, vector<char>(10));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> crossword[i][j];
        }
    }

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    solveCW(crossword, words, 0);
}