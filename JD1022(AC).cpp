#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int s[105];
	int e[105];
	char str[100];
	int id;
	int hh, mm;
	int sum;
	int count;
	char ch;

	memset(s, -1, sizeof(s));
	memset(e, -1, sizeof(e));
	while (scanf("%d", &id) == 1 && id != -1) {
		if (id == 0) {
			scanf("%s", str);
			scanf("%s", str);
			sum = count = 0;
			for (id = 1; id <= 100; ++id) {
				if (s[id] != -1 && e[id] != -1) {
					sum += e[id] - s[id];
					++count;
				}
			}
			if (count > 0) {
				printf("%d %d\n", count, (int)(1.0 * sum / count + 0.5));
			} else {
				printf("0 0\n");
			}
			memset(s, -1, sizeof(s));
			memset(e, -1, sizeof(e));
		} else {
			scanf("%s", str);
			ch = str[0];
			scanf("%s", str);
			sscanf(str, "%02d:%02d", &hh, &mm);
			ch == 'S' ? (s[id] = hh * 60 + mm) : (e[id] = hh * 60 + mm);
		}
	}

	return 0;
}