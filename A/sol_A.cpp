#include <iostream>
using namespace std;

int main()
{
	int* corrs = new int[8]{ 2, 1, 2, 3, 4, 5, 4, 3 };
	
	int N;
	cin >> N;

	cout << corrs[N % 8] << endl;

	return 0;
}