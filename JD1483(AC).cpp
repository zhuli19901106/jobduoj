#include <iostream>
using namespace std;

int main()
{
	int a[10005];
	int n;
	int i;
	int min, max;
	
	while (cin >> n) {
		for (i = 0; i < n; ++i) {
			cin >> a[i];
		}
		min = max = a[0];
		for (i = 1; i < n; ++i) {
			if (a[i] < min) {
				min = a[i];
			}
			if (a[i] > max) {
				max = a[i];
			}
		}
		cout << max << " " << min << endl;
	}
	
	return 0;
}