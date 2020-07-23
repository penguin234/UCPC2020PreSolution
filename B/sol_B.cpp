#include <iostream>

using namespace std;


char convert(char c) {
	switch (c) {
	case '-':
		return '|';
	case '|':
		return '-';
	case '/':
		return '\\';
	case '\\':
		return '/';
	case '^':
		return '<';
	case '<':
		return 'v';
	case 'v':
		return '>';
	case '>':
		return '^';
	default:
		return c;
	}
}


int main() {
	int N, M;
	cin >> N >> M;

	char** input = new char* [N];

	for (int i = 0; i < N; i++) {
		input[i] = new char[M + 1];
		cin >> input[i];
	}

	for (int i = M - 1; i >= 0; --i) {
		for (int j = 0; j < N; ++j) {
			cout << convert(input[j][i]);
		}
		cout << endl;
	}

	return 0;
}