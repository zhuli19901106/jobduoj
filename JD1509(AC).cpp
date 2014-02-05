// 690809	zhuli19901106	1509	Accepted	点击此处查看所有case的执行结果	1176KB	6753B	120MS
// 201402050235
// This solution is Naive Algorithm, may fail on very large skewed tree.
// If you optimize it with ancestor array to achieve O(log(n)) time, you'll get WA.
// Because the test data of this problem have some illegal input.
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10005;
// tree[x][0]: parent of node x
// tree[x][1]: left child of node x
// tree[x][2]: right child of node x
// tree[x][3]: value of node x
int tree[MAXN][4];
// number of nodes
int e;

void build(int a)
{
    int tmp;

    scanf("%d", &tmp);
    if(tmp)
    {
        tree[a][1] = e;
        tree[e][3] = tmp;
        tree[e][0] = a;
        ++e;
		// build the left subtree
        build(e - 1);
    }

    scanf("%d", &tmp);
    if(tmp)
    {
        tree[a][2] = e;
        tree[e][3] = tmp;
        tree[e][0] = a;
        ++e;
		// build the right subtree
        build(e - 1);
    }
}
int main()
{
    int n, ni;
	int i;
	// the value to be queried
	int m1, m2;
	// the corresponding node indices of m1 and m2
	int s1, s2;
	int t1, t2;
	int c1, c2, c;

    while (scanf("%d", &n)  == 1) {
		for (ni = 0; ni < n; ++ni) {
			// get value for root node
			e = 1;
            scanf("%d", &tree[0][3]);

			// root has no parent node
            tree[0][0] = -1;
            build(0);

            scanf("%d%d", &m1, &m2);
            s1 = s2 = -1;
            for (i = 0;i <= e; ++i) {
                if (tree[i][3] == m1) {
					s1 = i;
					// there're duplicate values
                    break;
                }
            }
			for (i = 0;i <= e; ++i) {
                if (tree[i][3] == m2) {
                    s2 = i;
					// there're duplicate values
                    break;
                }
            }

            if (s1 != -1 && s2 != -1) {
                t1 = s1;
                t2 = s2;
                c1 = c2 = 0;

				// c1 is the depth of t1
                while (tree[t1][0] != -1) {
                    ++c1;
                    t1 = tree[t1][0];
                }
				// c2 is the depth of t2
                while (tree[t2][0] != -1) {
                    ++c2;
                    t2 = tree[t2][0];
                }
				// move'em to the same height level
                if (c1 > c2) {
                    c = c1 - c2;
                    while(c--) {
                        s1 = tree[s1][0];
					}
                }
                if (c2 > c1) {
					c = c2 - c1;
					while(c--) {
                        s2 = tree[s2][0];
					}
                }
                while(s1 != s2)
                {
                    s1 = tree[s1][0];
                    s2 = tree[s2][0];
                }
                printf("%d\n", tree[s1][3]);
            } else {
				// At least one value is not found in the tree.
                printf("My God\n");
			}
        }
    }

    return 0;
}

/*
// This here is my last version of code, got some strange WAs.
// I doubt if the test data is really legal as described.
// 1. m1 and m2 may be 0
// 2. some tree nodes may have same values, making things ambiguous.
// I'll prove my suspicion.
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct st{
public:
	int key;
	st *ll;
	st *rr;
	st(int _key = 0): key(_key), ll(NULL), rr(NULL) {}
}st;

// maximal number of nodes
const int MAXN = 10005;
// key -> node_index mapping
int hash_key[MAXN];
// node_index -> key mapping
int key_hash[MAXN];
// depth of each node
int depth[MAXN];
// array recording ancestors
int anc[MAXN][16];
// total number of nodes, index starting from 1
int nc;

// recursively calculate depths of nodes
void getDepth(st *root, int dep)
{
	if (root == NULL) {
		return;
	}
	depth[hash_key[root->key]] = dep;
	if (root->ll != NULL) {
		getDepth(root->ll, dep + 1);
	}
	if (root->rr != NULL) {
		getDepth(root->rr, dep + 1);
	}
}

// recursively construct a binary tree
void constructBinaryTree(st *&root)
{
	int tmp;

	scanf("%d", &tmp);
	if (tmp == 0) {
		root = NULL;
	} else {
		root = new st(tmp);
		++nc;
		if (hash_key[tmp] == 0) {
			hash_key[tmp] = nc;
		}
		key_hash[nc] = tmp;
		constructBinaryTree(root->ll);
		constructBinaryTree(root->rr);
	}
}

// recursively initialize ancestor array
void getParent(st *root)
{
	if (root == NULL) {
		return;
	}

	// anc[x][0] is the direct parent of x.
	if (root->ll != NULL) {
		anc[hash_key[root->ll->key]][0] = hash_key[root->key];
		getParent(root->ll);
	}
	if (root->rr != NULL) {
		anc[hash_key[root->rr->key]][0] = hash_key[root->key];
		getParent(root->rr);
	}
}

// calculate LCA in O(log(n)) time
int leastCommonAncestor(int x, int y)
{
	int i;

	if (depth[x] < depth[y]) {
		return leastCommonAncestor(y, x);
	}
	for (i = 15; i >= 0; --i) {
		if (depth[anc[x][i]] >= depth[y]) {
			x = anc[x][i];
			if (depth[x] == depth[y]) {
				break;
			}
		}
	}
	if (x == y) {
		return x;
	}

	for (i = 15; i >= 0; --i) {
		if (anc[x][i] != anc[y][i]) {
			// they'll finally be equal, think about the reason.
			x = anc[x][i];
			y = anc[y][i];
		}
	}

	// this is the direct parent of x
	return anc[x][0];
}

st *deleteTree(st *root)
{
	if (NULL == root) {
		return NULL;
	}

	if (root->ll != NULL) {
		root->ll = deleteTree(root->ll);
	}
	if (root->rr != NULL) {
		root->rr = deleteTree(root->rr);
	}
	delete root;
	root = NULL;

	return NULL;
}

int main()
{
	int ci, cc;
	int i, j;
	int x, y;
	st *root;

	while (scanf("%d", &cc) == 1) {
		for (ci = 0; ci < cc; ++ci) {
			// data initialization 
			memset(hash_key, 0, MAXN * sizeof(int));
			memset(key_hash, 0, MAXN * sizeof(int));
			memset(depth, 0, MAXN * sizeof(int));
			memset(anc, 0, MAXN * 16 * sizeof(int));
			nc = 0;
			root = NULL;

			constructBinaryTree(root);
			getParent(root);
			getDepth(root, 1);
			for (j = 1; j < 16; ++j) {
				for (i = 1; i <= nc; ++i) {
					anc[i][j] = anc[anc[i][j - 1]][j - 1];
				}
			}
			scanf("%d%d", &x, &y);
			if (hash_key[x] == 0 || hash_key[y] == 0) {
				printf("My God\n");
			} else {
				printf("%d\n", key_hash[leastCommonAncestor(hash_key[x], hash_key[y])]);
			}

			root = deleteTree(root);
		}
	}

	return 0;
}
*/