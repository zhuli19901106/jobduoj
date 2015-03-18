#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int M = 100005;

class MyQueue {
public:
	MyQueue(size_t cap)
	{
		if (cap < 0) {
			cap = 0;
		}
		_cap = cap;
		_v.resize(_cap + 1);
		_front = _rear = 0;
	}

	size_t size()
	{
		return (_rear + _cap + 1 - _front) % (_cap + 1);
	}

	bool full()
	{
		return (_rear + 1) % (_cap + 1) == _front;
	}

	bool empty()
	{
		return _front == _rear;
	}

	size_t capacity()
	{
		return _cap;
	}

	void push(const int &val)
	{
		_v[_rear] = val;
		_rear = (_rear + 1) % (_cap + 1);
	}

	int front(int k = 1)
	{
		return _v[(_front + k - 1) % (_cap + 1)];
	}

	void pop()
	{
		_front = (_front + 1) % (_cap + 1);
	}

	~MyQueue()
	{
		_v.clear();
	}
protected:
	vector<int> _v;
	size_t _cap;
	size_t _front, _rear;
};

int main()
{
	MyQueue *q;
	int n, m;
	int i;
	char s[20];
	int val;

	while (scanf("%d%d", &n, &m) == 2) {
		q = new MyQueue(m);
		for (i = 0; i < n; ++i) {
			scanf("%s", s);
			if (strcmp(s, "Push") == 0) {
				scanf("%d", &val);
				if (q->full()) {
					printf("failed\n");
				} else {
					q->push(val);
				}
			} else if (strcmp(s, "Pop") == 0) {
				if (q->empty()) {
					printf("failed\n");
				} else {
					q->pop();
				}
			} else if (strcmp(s, "Query") == 0) {
				scanf("%d", &val);
				if (val < 1 || val > q->size()) {
					printf("failed\n");
				} else {
					printf("%d\n", q->front(val));
				}
			} else if (strcmp(s, "Isempty") == 0) {
				printf(q->empty() ? "yes\n" : "no\n");
			} else if (strcmp(s, "Isfull") == 0) {
				printf(q->full() ? "yes\n" : "no\n");
			}
		}
		delete q;
	}

	return 0;
}