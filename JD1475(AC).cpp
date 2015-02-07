#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int gd(char ch)
{
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	} else if (ch >= 'a' && ch <= 'z') {
		return ch - 'a' + 10;
	} else {
		return 0;
	}
}


int main()
{
	char s[2000];
	int i;
	int len;
	int t, ti;
	int hlen;
	int tlen;
	int sip[4];
	int dip[4];
	vector<int> v;
	int spt, dpt;

	while (gets(s) != NULL) {
		sscanf(s, "%d", &t);
		for (ti = 1; ti <= t; ++ti) {
			gets(s);
			len = strlen(s);
			for (i = 0; i < len; i += 3) {
				v.push_back(gd(s[i]) * 16 + gd(s[i + 1]));
			}
			hlen = (v[0] & 0xf) << 2;
			printf("Case #%d\n", ti);
			tlen = v[3] + (v[2] << 8);
			printf("Total length = %d bytes\n", tlen);
			for (i = 0; i < 4; ++i) {
				sip[i] = v[12 + i];
			}
			printf("Source = %d.%d.%d.%d\n", sip[0], sip[1], sip[2], sip[3]);
			for (i = 0; i < 4; ++i) {
				dip[i] = v[16 + i];
			}
			printf("Destination = %d.%d.%d.%d\n", dip[0], dip[1], dip[2], dip[3]);
			spt = (v[hlen] << 8) + v[hlen + 1];
			printf("Source Port = %d\n", spt);
			dpt = (v[hlen + 2] << 8) + v[hlen + 3];
			printf("Destination Port = %d\n", dpt);
			printf("\n");
			v.clear();
		}
	}

	return 0;
}