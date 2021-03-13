#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
bool check = false;
string answer;

void solve(string str);
bool good(string str);

int main()
{
	scanf_s("%d", &N);
	solve("1");
	cout << answer;
	return 0;
}

void solve(string str)
{
	if (check) return;
	if (!good(str)) return;
	if (str.length() == N)
	{
		answer = str;
		check = true;
		return;
	}
	else
	{
		solve(str + "1");
		solve(str + "2");
		solve(str + "3");
	}

}

bool good(string str)
{
	int len = str.length();
	for (int i = 1; i <= len / 2; i++)
	{
		string temp1 = str.substr(len - i, i);
		string temp2 = str.substr(len - (2 * i), i);
		if (!temp1.compare(temp2)) return false;
	}
	return true;
}