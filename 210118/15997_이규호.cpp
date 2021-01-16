#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

struct Match
{
	string A, B;
	double win, draw, lose;
	friend istream& operator>>(istream&, Match& pos);
};

istream& operator>>(istream& is, Match& pos)
{
	is >> pos.A >> pos.B >> pos.win >> pos.draw >> pos.lose;
	return is;
}

Match match[6];
string team[4];
map<string, int> hashing;
double answer[4] = { 0, 0, 0, 0 };

void solve(double rate, vector<int> score)
{
	vector<pair<int, int>> rank;
	FUP(i, 0, 3)
	{
		rank.push_back({ score[i], i });
	}
	sort(ALL(rank));
	if (rank[0].first == rank[3].first)
	{
		FUP(i, 0, 3)
		{
			answer[i] += (rate * 0.5);
		}
	}
	else if (rank[1].first == rank[3].first)
	{
		FUP(i, 1, 3)
		{
			answer[rank[i].second] += (rate * 2 / 3);
		}
	}
	else if (rank[0].first == rank[2].first)
	{
		answer[rank[3].second] += rate;
		FUP(i, 0, 2)
		{
			answer[rank[i].second] += (rate / 3);
		}
	}
	else if (rank[1].first == rank[2].first)
	{
		answer[rank[3].second] += rate;
		FUP(i, 1, 2)
		{
			answer[rank[i].second] += (rate / 2);
		}
	}
	else
	{
		FUP(i, 2, 3)
		{
			answer[rank[i].second] += rate;
		}
	}
}

void DFS(int idx, double rate, vector<int> score)
{
	if (idx == 6)
	{
		solve(rate, score);
		return;
	}
	score[hashing[match[idx].A]] += 3;
	DFS(idx + 1, rate * match[idx].win, score);
	score[hashing[match[idx].A]] -= 3;
	score[hashing[match[idx].B]] += 3;
	DFS(idx + 1, rate * match[idx].lose, score);
	score[hashing[match[idx].B]] -= 3;
	score[hashing[match[idx].A]]++;
	score[hashing[match[idx].B]]++;
	DFS(idx + 1, rate * match[idx].draw, score);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	FUP(i, 0, 3)
	{
		CIN(team[i]);
		hashing[team[i]] = i;
	}
	FUP(i, 0, 5)
	{
		CIN(match[i]);
	}
	DFS(0, 1.0, { 0, 0, 0, 0 });
	COUT(fixed);
	cout.precision(8);
	FUP(i, 0, 3)
	{
		COUT(answer[i]);
		ENDL;
	}

	return 0;
}