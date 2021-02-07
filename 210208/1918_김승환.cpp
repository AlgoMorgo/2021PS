#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;

void solve()
{
    string str;
    cin >> str;
    vector<char> c;
    for (char i : str)
    {
        if (i == '(')
            c.push_back(i);
        else if (i == ')')
        {
            while (c.back() != '(')
            {
                cout << c.back();
                c.pop_back();
            }
            c.pop_back();
        }
        else if (i == '*' || i == '/')
        {
            while (!c.empty() && (c.back() == '*' || c.back() == '/'))
            {
                cout << c.back();
                c.pop_back();
            }
            c.push_back(i);
        }
        else if (i == '+' || i == '-')
        {
            while (!c.empty() && c.back() != '(')
            {
                cout << c.back();
                c.pop_back();
            }
            c.push_back(i);
        }
        else
            cout << i;
    }
    while (!c.empty())
    {
        cout << c.back();
        c.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}