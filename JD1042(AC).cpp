#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	int lena, lenb;
	const int MAXN = 105;
	int dp[MAXN][MAXN];
	int i, j;

	while (cin >> a >> b) {
		lena = a.length();
		lenb = b.length();
		if (lena == 0 || lenb == 0) {
			cout << 0 << endl;
			continue;
		}
		dp[0][0] = a[0] == b[0];
		for (i = 1; i < lena; ++i) {
			dp[i][0] = (a[i] == b[0] ? 1 : dp[i - 1][0]);
		}
		for (j = 1; j < lenb; ++j) {
			dp[0][j] = (a[0] == b[j] ? 1 : dp[0][j - 1]);
		}
		for (i = 1; i < lena; ++i) {
			for (j = 1; j < lenb; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (a[i] == b[j]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[lena - 1][lenb - 1] << endl;
	}

	return 0;
}