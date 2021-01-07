#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
int N;
int fleaCnt[MAX];

vector<int> sell, buy;

/*
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> fleaCnt[i];
	}
}

long long Cost() {
	long long result = 0;
	int i = 0;
	int iter = 0;
	for (int i = 0; i < N; i++) {

		bool isPositive;
		if (fleaCnt[i] == 0) continue;
		else if (fleaCnt[i] < 0) isPositive = false;
		else isPositive = true;
		int j = i + 1;
		while (fleaCnt[i] != 0) {
			bool isNextPositive;
			if (fleaCnt[j] == 0) {
				j++;
				continue;
			}
			else if (fleaCnt[j] < 0) isNextPositive = false;
			else isNextPositive = true;
			//i!=j
			if (isPositive == isNextPositive) {
				j++;
			}
			else {
				int temp = fleaCnt[i] + fleaCnt[j];
;				if (temp > 0) {
					if (isPositive == true) {
						result += abs(fleaCnt[j]) * (j - i);
						fleaCnt[i] = temp;
						fleaCnt[j] = 0;
						j++;
					}
					else {
						result += abs(fleaCnt[i]) * (j - i);
						fleaCnt[j] = temp;
						fleaCnt[i] = 0;
					}
				}
				else if(temp<0){
					if (isPositive == false) {
						result += abs(fleaCnt[j]) * (j - i);
						fleaCnt[i] = temp;
						fleaCnt[j] = 0;
						j++;
					}
					else {
						result += abs(fleaCnt[i]) * (j - i);
						fleaCnt[j] = temp;
						fleaCnt[i] = 0;
					}
				}
				else {
					result += abs(fleaCnt[i]) * (j - i);
					fleaCnt[i] = 0;
					fleaCnt[j] = 0;
				}
			}
		}
	}
	return result;
}
*/
int main() {
	long long result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> fleaCnt[i];
		if (fleaCnt[i] > 0) sell.push_back(i);
		else buy.push_back(i);
	}
	auto i = sell.begin();
	auto j = buy.begin();

	while (i != sell.end() && j != buy.end()) {
		if (fleaCnt[*i] > abs(fleaCnt[*j])) {
			fleaCnt[*i] += fleaCnt[*j];
			result += abs(fleaCnt[*j] * (*j - *i));
			j++;
		}
		else if (fleaCnt[*i] < abs(fleaCnt[*j])) {
			fleaCnt[*j] += fleaCnt[*i];
			result += fleaCnt[*i] * abs(*j - *i);
			i++;
		}
		else {
			result += fleaCnt[*i] * abs(*j - *i);
			i++; 
			j++;
		}
	}
	cout << result;
	return 0;
}