#include <cstdio>
#include <vector>
using namespace std;

vector<int> f;

bool check(int n)
{
	int i;

	if (n <= 0) {
		return false;
	}
	for (i = f.size() - 1; i >= 0; --i) {
		if (n >= f[i]) {
			n -= f[i];
		}
		if (n == 0) {
			return true;
		}
	}
	return false;
}

int main()
{
	const int MAXN = 1000005;
	int i;

	f.push_back(1);
	for (i = 2; f[i - 2] * i <= MAXN; ++i) {
		f.push_back(f[i - 2] * i);
	}

	int n;

	while (scanf("%d", &n) == 1) {
		if (check(n) || check(n - 1)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	f.clear();
	return 0;
}