#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int G, P;
int parent[100001];
int answer = 0;

int find(int num)
{
	if (num == parent[num]) return num;
	return parent[num] = find(parent[num]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	parent[u] = v;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> G >> P;
	for (int i = 1; i <= G; i++) parent[i] = i;
	while (P--)
	{
		int temp;
		cin >> temp;
		int docking = find(temp);
		if (docking)
		{
			merge(docking, docking - 1);
			answer++;
		}
		else break;
	}
	cout << answer;

	return 0;
}