#include <cstdio>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int i, j, n;
	int c;
	vector<int> v;
	vector<int> s;
	set<string> ans;
	set<string>::iterator it;
	string str;
	int b[4];
	int val;
	bool invalid;

	while (scanf("%d", &n) == 1) {
		scanf("%d", &c);		
		s.resize(n + 1, -1);
		while (scanf("%d", &val) == 1 && val != -1) {
			s[val] = 1;
		}
		invalid = false;
		while (scanf("%d", &val) == 1 && val != -1) {
			if (s[val] != -1) {
				invalid = true;
			}
			s[val] = 0;
		}
		if (invalid) {
			printf("IMPOSSIBLE\n");
			s.clear();
			continue;
		}

		for (i = 0; i < 8; ++i) {
			b[0] = !!(i & 4);
			b[1] = !!(i & 2);
			b[2] = !!(i & 1);
			b[3] = (c & 1) ^ b[0] ^ b[1] ^ b[2];
			if (b[0] + b[1] + b[2] + b[3] > c) {
				continue;
			}
			v.resize(n + 1, 1);
			for (j = 1; j <= n; ++j) {
				v[j] ^= b[0];
			}
			for (j = 1; j <= n; j += 2) {
				v[j] ^= b[1];
			}
			for (j = 2; j <= n; j += 2) {
				v[j] ^= b[2];
			}
			for (j = 1; j <= n; j += 3) {
				v[j] ^= b[3];
			}
			for (j = 1; j <= n; ++j) {
				if (s[j] == -1 || s[j] == v[j]) {
					continue;
				}
				break;
			}
			if (j < n) {
				v.clear();
				continue;
			}
			str = "";
			for (j = 1; j <= n; ++j) {
				str.push_back('0' + v[j]);
			}
			ans.insert(str);
			v.clear();
		}
		if (ans.empty()) {
			printf("IMPOSSIBLE\n");
		} else {
			for (it = ans.begin(); it != ans.end(); ++it) {
				printf("%s\n", (*it).data());
			}
			ans.clear();
		}

		s.clear();
		v.clear();
	}

	return 0;
}