// 652798	zhuli19901106	1362	Accepted	点击此处查看所有case的执行结果	1520KB	483B	280MS
// 201311172053
#include <iostream>
#include <string>
using namespace std;

string left_rotate(const string &str, int n)
{
	if(str.length() == 0){
		return str;		
	}
	
	n = n % str.length();
	
	if(n != 0){
		return str.substr(n, str.length() - n) + str.substr(0, n);
	}else{
		return str;
	}
}

int main()
{
	string str;
	int n;
	
	while(cin >> str >> n){
		cout << left_rotate(str, n) << endl;
	}
	
	return 0;
}