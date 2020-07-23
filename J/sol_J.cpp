#include <iostream>
#include <algorithm>

using namespace std;

using Point = pair<int, int>;


int Distsquared(const Point& a, const Point& b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}


int N;


int MaxDist(Point* points, int idx) {
	int M = -1, temp;

	for (int j = 0; j < N; j++) {
		temp = Distsquared(points[idx], points[j]);
		if (temp > M) {
			M = temp;
		}
	}

	return M;
}


int main() {
	cin >> N;

	int x, y;
	Point* points = new Point[N];
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		points[i] = make_pair(x, y);
	}
	
	int m = 800000001, res, temp;
	for (int i = 0; i < N; i++) {
		temp = MaxDist(points, i);
		if (m > temp) {
			res = i;
			m = temp;
		}
	}
	
	cout << points[res].first << ' ' << points[res].second << endl;

	return 0;
}