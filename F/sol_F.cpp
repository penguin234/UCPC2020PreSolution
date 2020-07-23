#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;


int CalcScore(const int& d1, const int& d2, const int& d3) {
	if (d1 == d2) {
		if (d2 == d3) {
			return 10000 + d1 * 1000;
		}
		else {
			return 1000 + d1 * 100;
		}
	}
	else if (d1 == d3) {
		return 1000 + d1 * 100;
	}
	else if (d2 == d3) {
		return 1000 + d2 * 100;
	}
	return max(max(d1, d2), d3) * 100;
}


int main() {
	int N;
	cin >> N;

	double** tables;
	tables = new double* [N - 1];
	tables[N - 2] = new double[216]{};

	double* table, * prev;
	double curr, next;
	for (int i = N - 3; i >= 0; i--) {
		table = tables[i] = new double[216];

		for (int d1 = 1; d1 <= 6; d1++) {
			for (int d2 = 1; d2 <= 6; d2++) {
				for (int d3 = 1; d3 <= 6; d3++) {
					curr = CalcScore(d1, d2, d3);

					next = 0;
					prev = tables[i + 1] + (36 * (d2 - 1) + 6 * (d3 - 1) - 1);
					for (int dn = 1; dn <= 6; dn++) {
						next += prev[dn];
					}
					next /= 6;

					*table = max(curr,next);
					table++;
				}
			}
		}
	}

	table = tables[0];
	double res = 0;
	for (int i = 0; i < 216; i++) {
		res += table[i];
	}
	res /= 216;

	cout << setprecision(16);
	cout << res << endl;

	return 0;
}