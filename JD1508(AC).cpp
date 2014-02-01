// 688177	zhuli19901106	1508	Accepted	点击此处查看所有case的执行结果	1020KB	1323B	0MS
// 201401311802
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int i;
	char s[100];
	int len;
	long long int n;
	int flag;
	bool suc;

	// don't use "while (gets(s) != NULL)"!
	while (scanf("%s", s) == 1) {
		len = strlen(s);
		suc = true;
		do {
			if (len <= 0) {
				suc = false;
				break;
			}

			if (len == 1 && (s[0] == '+' || s[0] == '-')) {
				suc = false;
				break;
			}

			for (i = 0; i < len; ++i) {
				if (s[i] == '-' || s[i] == '+') {
					if (i != 0) {
						suc = false;
						break;
					}
				} else if (!(s[i] >= '0' && s[i] <= '9')) {
					suc = false;
					break;
				}
			}
			if (!suc) {
				break;
			}
			if (s[0] == '-') {
				flag = -1;
				n = 0;
			} else if(s[0] == '+') {
				flag = +1;
				n = 0;
			} else {
				flag = +1;
				n = (s[0] - '0');
			}
			for (i = 1; i < len; ++i) {
				n = n * 10 + (s[i] - '0');
				if (n > 10000000) {
					suc = false;
					break;
				}
			}
			n = n * flag;
			if (n == 0) {
				suc = false;
				break;
			}
		} while (0);
		if (suc) {
			printf("%lld\n", n);
		} else {
			printf("My God\n");
		}
	}

	return 0;
}