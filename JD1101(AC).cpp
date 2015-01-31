#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

void process1(vector<int> &num, vector<char> &op)
{
	int n = op.size();
	int i, j, k;
	int sum;
	vector<int> num1;
	vector<char> op1;

	i = 0;
	while (i < n) {
		op1.push_back(op[i]);
		j = i + 1;
		sum = num[i];
		while (j < n && (op[j] == '*' || op[j] == '/')) {
			++j;
		}
		for (k = i + 1; k < j; ++k) {
			if (op[k] == '*') {
				sum *= num[k];
			} else {
				sum /= num[k];
			}
		}
		i = j;
		num1.push_back(sum);
	}

	num = num1;
	op = op1;
}

void process2(vector<int> &num, vector<char> &op)
{
	int n = op.size();
	int i;

	int sum = 0;
	for (i = 0; i < n; ++i) {
		if (op[i] == '+') {
			sum += num[i];
		} else {
			sum -= num[i];
		}
	}
	num.clear();
	op.clear();

	num.push_back(sum);
}

int main()
{
	int val;
	int ch;
	vector<int> num;
	vector<char> op;
	bool lastCase;

	lastCase = false;
	while (true) {
		op.push_back('+');
		if (scanf("%d", &val) == EOF) {
			lastCase = true;
			goto LA_FINE;
		}
		num.push_back(val);
		while (true) {
			ch = getchar();
			if (ch == '\n') {
				break;
			} else if (ch == EOF) {
				lastCase = true;
				break;
			} else {
				op.push_back(ch);
				scanf("%d", &val);
				num.push_back(val);
			}
		}

		process1(num, op);
		process2(num, op);
		printf("%d\n", num[0]);
LA_FINE:
		num.clear();
		op.clear();
		if (lastCase) {
			break;
		}
	}

	return 0;
}