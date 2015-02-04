#include <cstdio>
#include <vector>
using namespace std;

double calc(int n)
{
	if (n >= 90) {
		return 4.0;
	} else if (n >= 85) {
		return 3.7;
	} else if (n >= 82) {
		return 3.3;
	} else if (n >= 78) {
		return 3.0;
	} else if (n >= 75) {
		return 2.7;
	} else if (n >= 72) {
		return 2.3;
	} else if (n >= 68) {
		return 2.0;
	} else if (n >= 64) {
		return 1.5;
	} else if (n >= 60) {
		return 1.0;
	} else {
		return 0;
	}
}

int main()
{
	int i, n;
	int creditSum;
	double gpaSum;
	vector<int> a, b;

	while (scanf("%d", &n) == 1) {
		creditSum = 0;
		gpaSum = 0;
		a.resize(n);
		b.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; ++i) {
			scanf("%d", &b[i]);
		}
		for (i = 0; i < n; ++i) {
			creditSum += a[i];
			gpaSum += a[i] * calc(b[i]);
		}
		printf("%.2f\n", gpaSum / creditSum);
		a.clear();
		b.clear();
	}

	return 0;
}