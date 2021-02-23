#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    string str;
    vector<char> v;
    cin >> str;

    function<void ()> calc = [&] ()
    {
        if (v.size() < 4)
            return;
        string t;
        for (int i=0; i<4; ++i)
            t.push_back(v[v.size()-1-i]);
        if (t != "PAPP")
            return;
        for (int i=0; i<4; ++i)
            v.pop_back();
        v.push_back('P');
        calc();
    };

    for (char c : str)
    {
        v.push_back(c);
        calc();
    }

    cout << (v.size() == 1 && v[0] == 'P' ? "PPAP" : "NP");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}