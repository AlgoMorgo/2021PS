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

ll N, M, K, ans = 0, x = INT_MAX, y = INT_MAX;
pair<ll, ll> Atmp[10000], Btmp[10000];
vector<pair<ll, ll>> A, B;
double Btan[10000], Atan[10000];

ll CCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0) return 1;         //반시계반향
	else if (temp < 0) return -1;   //시계방향
	else return 0;                  //일직선
}


// 데이터 전처리. x가 가장 작은 값을(가장 왼쪽 점) 0번째 인덱스로 놓는다.
void preprocessing()
{
	int idx = -1; // 시작할 index (가장 작은 x)
	FUP(i, 0, N - 1)
	{
		CIN2(Atmp[i].first, Atmp[i].second);
		if (x > Atmp[i].first)
		{
			idx = i;
			y = Atmp[i].second;
			x = Atmp[i].first;
		}
	}
	FUP(i, idx, idx + N - 1)
	{
		A.push_back(Atmp[i % N]);
	}
	idx = -1;
	x = y = INT_MAX;
	FUP(i, 0, M - 1)
	{
		CIN2(Btmp[i].first, Btmp[i].second);
		if (x > Btmp[i].first)
		{
			idx = i;
			y = Btmp[i].second;
			x = Btmp[i].first;
		}
	}
	FUP(i, idx, idx + M - 1)
	{
		B.push_back(Btmp[i % M]);
	}

	// 각도를 구한다. y / x의 값임. x가 0이면 나누기가 안되므로 큰 값으로 넣어줌.
	FUP(i, 1, N - 1)
	{
		if (A[i].first == A[0].first)
		{
			Atan[i] = A[i].second > A[0].second ? 1e9 + 7 : -(1e9 + 7);
		}
		else
		{
			Atan[i] = ((double)A[i].second - A[0].second) / ((double)A[i].first - A[0].first);
		}
	}

	FUP(i, 1, M - 1)
	{
		if (B[i].first == B[0].first)
		{
			Btan[i] = B[i].second > B[0].second ? 1e9 + 7 : -(1e9 + 7);
		}
		else
		{
			Btan[i] = ((double)B[i].second - B[0].second) / ((double)B[i].first - B[0].first);
		}
	}
	
}

bool checkA()
{
	if (x <= A[0].first) return false; // 첫 좌표보다 X가 작거나 같으면 외부임. (외곽선에 점이 없으므로)
	double tan = ((double)y - A[0].second) / ((double)x - A[0].first); // 첫 좌표로부터 탄젠트 값 구해줌
	if (Atan[1] > tan || Atan[N - 1] < tan) return false; // 범위를 벗어난 값이면 외부임.
	int left = 1, right = N - 1, mid, idx = 1;
	while (left <= right) // 이분탐색
	{
		mid = (left + right) / 2;
		if (tan == Atan[mid])
		{
			// 점이 겹치지 않으므로, 좌표의 값이 더 작으면 내부이고 더 크면 외부임. 
			if (x < A[mid].first) return true;
			else return false;
		}
		if (tan > Atan[mid])
		{
			left = mid + 1;
			idx = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	// 내부에 있다면 모두 반시계방향임.
	if (CCW(x, y, A[0].first, A[0].second, A[idx].first, A[idx].second) != 1) return false;
	else if (CCW(x, y, A[idx].first, A[idx].second, A[idx + 1].first, A[idx + 1].second) != 1) return false;
	else if (CCW(x, y, A[idx + 1].first, A[idx + 1].second, A[0].first, A[0].second) != 1) return false;
	return true;
}

bool checkB()
{
	if (x <= B[0].first) return true;
	double tan = ((double)y - B[0].second) / ((double)x - B[0].first);
	if (Btan[1] > tan || Btan[M - 1] < tan) return true;
	int left = 1, right = M - 1, mid, idx = 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (tan == Btan[mid])
		{
			if (x < B[mid].first) return false;
			else return true;
		}
		if (tan > Btan[mid])
		{
			left = mid + 1;
			idx = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (CCW(x, y, B[0].first, B[0].second, B[idx].first, B[idx].second) != 1) return true;
	else if (CCW(x, y, B[idx].first, B[idx].second, B[idx + 1].first, B[idx + 1].second) != 1) return true;
	else if (CCW(x, y, B[idx + 1].first, B[idx + 1].second, B[0].first, B[0].second) != 1) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, M, K);
	preprocessing();
	while (K--)
	{
		CIN2(x, y);
		if (!checkA()) 
			ans++;
		else if (!checkB())
			ans++;
	}
	!ans ? COUT("YES") : COUT(ans);

	return 0;
}