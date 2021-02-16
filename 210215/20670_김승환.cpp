#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, int>> a(N), b(M), c(K);
    for (auto& p : a)
        cin >> p.first >> p.second;
    for (auto& p : b)
        cin >> p.first >> p.second;
    for (auto& p : c)
        cin >> p.first >> p.second;
    vector<pair<int, int>> au, ad, bu, bd;
    int start, end;
    start = min_element(a.begin(), a.end()) - a.begin();
    end = max_element(a.begin(), a.end()) - a.begin();
    if (start < end)
    {
        for (int i=start; i<=end; ++i)
            ad.push_back(a[i]);
        for (int i=end; i<a.size(); ++i)
            au.push_back(a[i]);
        for (int i=0; i<=start; ++i)
            au.push_back(a[i]);
    }
    else
    {
        for (int i=end; i<=start; ++i)
            au.push_back(a[i]);
        for (int i=start; i<a.size(); ++i)
            ad.push_back(a[i]);
        for (int i=0; i<=end; ++i)
            ad.push_back(a[i]);
    }
    start = min_element(b.begin(), b.end()) - b.begin();
    end = max_element(b.begin(), b.end()) - b.begin();
    if (start < end)
    {
        for (int i=start; i<=end; ++i)
            bd.push_back(b[i]);
        for (int i=end; i<b.size(); ++i)
            bu.push_back(b[i]);
        for (int i=0; i<=start; ++i)
            bu.push_back(b[i]);
    }
    else
    {
        for (int i=end; i<=start; ++i)
            bu.push_back(b[i]);
        for (int i=start; i<b.size(); ++i)
            bd.push_back(b[i]);
        for (int i=0; i<=end; ++i)
            bd.push_back(b[i]);
    }

    auto in = [&au, &ad] (const pair<int, int>& p) -> bool
    {
        double angle, test;
        auto rit = lower_bound(au.rbegin(), au.rend(), p);
        if (rit == au.rend() || rit == au.rbegin())
            return false;
        angle = (double)(rit->second - (rit-1)->second) / (rit->first - (rit-1)->first + 0.01);
        test = (double)(p.second - (rit-1)->second) / (p.first - (rit-1)->first + 0.01);
        if (test > angle)
            return false;

        auto it = lower_bound(ad.begin(), ad.end(), p);
        angle = (double)(it->second - (it-1)->second) / (it->first - (it-1)->first + 0.01);
        test = (double)(p.second - (it-1)->second) / (p.first - (it-1)->first + 0.01);
        return test > angle;
    };

    auto out = [&bu, &bd] (const pair<int, int>& p) -> bool
    {
        double angle, test;
        auto rit = lower_bound(bu.rbegin(), bu.rend(), p);
        if (rit == bu.rend() || rit == bu.rbegin())
            return true;
        angle = (double)(rit->second - (rit-1)->second) / (rit->first - (rit-1)->first + 0.01);
        test = (double)(p.second - (rit-1)->second) / (p.first - (rit-1)->first + 0.01);
        if (test > angle)
            return true;

        auto it = lower_bound(bd.begin(), bd.end(), p);
        angle = (double)(it->second - (it-1)->second) / (it->first - (it-1)->first + 0.01);
        test = (double)(p.second - (it-1)->second) / (p.first - (it-1)->first + 0.01);
        return test < angle;
    };

    int answer = 0;
    for (auto& p : c)
    {
        if (!in(p) || !out(p))
            answer++;
    }
    cout << (answer == 0 ? "YES" : to_string(answer));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}