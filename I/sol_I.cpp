#include <iostream>
#include <set>

using namespace std;


const int L = 0;
const int V = 1;
const int R = 2;


pair<int, int> pos = make_pair(0, 0);
int VD = -1;


void move(int d) {
	if (d == V) {
		pos.second += VD;
	}
	else {
		pos.first += d - 1;
	}
	VD = VD == 1 ? -1 : 1;
}


int main() {
	set<pair<int, int>> passed;

	int N;
	cin >> N;

	int* stack = new int[N + 1];
	for (int i = 0; i < N + 1; i++) {
		stack[i] = -1;
	}
	int sp = 1;
	stack[0] = V;

	passed.insert(make_pair(0, -1));
	passed.insert(make_pair(0, 0));


	int count = 0;

	while (true) {
		int& curr = stack[sp];

		if (++curr == 2 - stack[sp - 1]) {
			continue;
		}

		if (curr == 3) {
			if (sp == 1) {
				break;
			}
			curr = -1;
			passed.erase(passed.find(pos));
			move(2 - stack[--sp]);
			continue;
		}

		move(curr);
		if (sp == N) {
			if (passed.find(pos) != passed.end()) {
				count++;
			}
		}
		else if (passed.find(pos) == passed.end()) {
			passed.insert(pos);
			sp++;
			continue;
		}
		move(2 - curr);
	}

	cout << count << endl;


	return 0;
}