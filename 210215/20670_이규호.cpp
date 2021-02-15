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
	if (temp > 0) return 1;         //�ݽð����
	else if (temp < 0) return -1;   //�ð����
	else return 0;                  //������
}


// ������ ��ó��. x�� ���� ���� ����(���� ���� ��) 0��° �ε����� ���´�.
void preprocessing()
{
	int idx = -1; // ������ index (���� ���� x)
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

	// ������ ���Ѵ�. y / x�� ����. x�� 0�̸� �����Ⱑ �ȵǹǷ� ū ������ �־���.
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
	if (x <= A[0].first) return false; // ù ��ǥ���� X�� �۰ų� ������ �ܺ���. (�ܰ����� ���� �����Ƿ�)
	double tan = ((double)y - A[0].second) / ((double)x - A[0].first); // ù ��ǥ�κ��� ź��Ʈ �� ������
	if (Atan[1] > tan || Atan[N - 1] < tan) return false; // ������ ��� ���̸� �ܺ���.
	int left = 1, right = N - 1, mid, idx = 1;
	while (left <= right) // �̺�Ž��
	{
		mid = (left + right) / 2;
		if (tan == Atan[mid])
		{
			// ���� ��ġ�� �����Ƿ�, ��ǥ�� ���� �� ������ �����̰� �� ũ�� �ܺ���. 
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
	// ���ο� �ִٸ� ��� �ݽð������.
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