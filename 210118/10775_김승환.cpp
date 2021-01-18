#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

int find(int i)
{
    if (parents[i] == i)
        return i;
    return parents[i] = find(parents[i]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (a > b)
            swap(a, b);
        parents[b] = a;
    }
}

void solve()
{
    int G, P;
    cin >> G >> P;
    vector<int> airports(P);
    for (int i=0; i<P; ++i)
        cin >> airports[i];

    parents.resize(G+1);
    for (int i=0; i<=G; ++i)
        parents[i] = i;

    int ans;
    for (ans=0; ans<P; ++ans)
    {
        int possible = find(airports[ans]);
        if (possible == 0)
            break;
        merge(possible-1, possible);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}