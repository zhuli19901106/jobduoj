#include <cstdio>
using namespace std;

typedef long long int ll;
int main()
{
  ll a[31];
  int i;
  
  a[0] = 0;
  a[1] = 1;
  for (i = 2; i <= 30; ++i) {
    a[i] = a[i - 1] + a[i - 2];
  }
  
  while (scanf("%d", &i) == 1) {
    printf("%lld\n", a[i]);
  }
  
  return 0;
}