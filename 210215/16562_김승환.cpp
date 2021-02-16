#include <iostream>

using namespace std;

int parent[10000], value[10000], check[10000];

int find(int i)
{
    if (parent[i] == i)
        return i;
    else
        return parent[i] = find(parent[i]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        parent[x] = y;
        value[y] = min(value[x], value[y]);
    }
}

void solve()
{
    int N, M, k;
    cin >> N >> M >> k;
    for (int i=0; i<N; ++i)
    {
        int temp;
        cin >> temp;

        parent[i] = i;
        value[i] = temp;
    }
    for (int i=0; i<M; ++i)
    {
        int x, y;
        cin >> x >> y;
        merge(x-1, y-1);
    }

    int result = 0;
    for (int i=0; i<N; ++i)
    {
        if (!check[find(i)])
        {
            check[find(i)] = 1;
            result += value[find(i)];
        }
    }
    if (result > k)
        cout << "Oh no";
    else
        cout << result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}