#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct Node {
	string s;
	int t;
	map<string, struct Node *> m;

	Node (const string &_s): s(_s) {}
} Node;
typedef map<string, struct Node *> mtype;

void split(vector<string> &path, const string &str)
{
	int i, len;
	string item;

	item = "";
	len = str.length();
	i = 0;
	while (i < len) {
		if (str[i] == '\\') {
			if (item.length() > 0) {
				path.push_back(item);
				item.clear();
			}
		} else {
			item.push_back(str[i]);
		}
		++i;
	}
	if (item.length() > 0) {
		path.push_back(item);
		item.clear();
	}
}

void insert(Node *root, vector<string> &path)
{
	Node *ptr;
	int i;
	mtype::iterator it;
	
	ptr = root;
	for (i = 0; i < (int)path.size(); ++i) {
		it = ptr->m.find(path[i]);
		if (it == ptr->m.end()) {
			ptr->m[path[i]] = new Node(path[i]);
		}
		if (ptr == root) {
			ptr->m[path[i]]->t = 0;
		} else {
			ptr->m[path[i]]->t = ptr->t + ptr->s.length() + 1;
		}
		ptr = ptr->m[path[i]];
	}
}

void preorder(Node *root, int level)
{
	int i;

	if (level >= 0) {
		for (i = 0; i < root->t; ++i) {
			cout << ' ';
		}
		cout << root->s << endl;
	}
	
	mtype::iterator it;
	for (it = root->m.begin(); it != root->m.end(); ++it) {
		preorder(it->second, level + 1);
	}
}

void clear(Node *&root)
{
	if (root == NULL) {
		return;
	}
	mtype::iterator it;

	for (it = root->m.begin(); it != root->m.end(); ++it) {
		clear(it->second);
	}
	root->m.clear();
	delete root;
	root = NULL;
}

int main()
{
	Node *root;
	int i, n;
	string str;
	vector<string> path;
		
	while (cin >> n && n) {
		root = new Node("");
		for (i = 0; i < n; ++i) {
			cin >> str;
			path.clear();
			split(path, str);
			insert(root, path);
		}
		preorder(root, -1);
		cout << endl;
		clear(root);
	}

	return 0;
}