#include <cstdio>
using namespace std;

int a[6][6];
int x, y;
int op1, op2;

void rotateCW(int n, int x, int y)
{
	int i, j;
	int val;
	
	for (i = x; i <=  n / 2 + x - 1; ++i) {
		for (j = y; j <= (n + 1) / 2 + y - 1; ++j) {
			val = a[i][j];
			a[i][j] = a[2 * y - 1 + n - j][i];
			a[2 * y - 1 + n - j][i] = a[2 * x - 1 + n - i][2 * y - 1 + n - j];
			a[2 * x - 1 + n - i][2 * y - 1 + n - j] = a[j][2 * x - 1 + n - i];
			a[j][2 * x - 1 + n - i] = val;
		}
	}
}

void rotateCCW(int n, int x, int y)
{
	int i, j;
	int val;
	
	for (i = x; i <=  n / 2 + x - 1; ++i) {
		for (j = y; j <= (n + 1) / 2 + y - 1; ++j) {
			val = a[i][j];
			a[i][j] = a[j][2 * x - 1 + n - i];
			a[j][2 * x - 1 + n - i] = a[2 * x - 1 + n - i][2 * y - 1 + n - j];
			a[2 * x - 1 + n - i][2 * y - 1 + n - j] = a[2 * y - 1 + n - j][i];
			a[2 * y - 1 + n - j][i] = val;
		}
	}
}

int main()
{
	while (true) {
		for (x = 1; x <= 5; ++x) {
			for (y = 1; y <= 5; ++y) {
				if (scanf("%d", &a[x][y]) != 1) {
					break;
				}
			}
			if (y <= 5) {
				break;
			}
		}
		if (x <= 5) {
			break;
		}
		scanf("%d%d%d%d", &op1, &op2, &x, &y);
		if (op1 == 1) {
			rotateCW(op2, x, y);
		} else if (op1 == 2) {
			rotateCCW(op2, x, y);
		}
		for (x = 1; x <= 5; ++x) {
			for (y = 1; y <= 5; ++y) {
				printf((y == 5 ? "%d\n" : "%d "), a[x][y]);
			}
		}
	}

	return 0;
}