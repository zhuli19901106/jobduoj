#include <iostream>
using namespace std;

int main()
{
  int n;
  long long int sum;
  
  while (cin >> n) {
  	sum = 1;
    for (int i = 2; i <= n; ++i) {
      sum *= i;
    }
    cout << sum << endl;
  }
  
  return 0;
}