#include <cstdio>
using namespace std;

int main()
{
	char d[256];
	int ch;

	d['Q'] = '=';
	d['W'] = 'Q';
	d['E'] = 'W';
	d['R'] = 'E';
	d['T'] = 'R';
	d['Y'] = 'T';
	d['U'] = 'Y';
	d['I'] = 'U';
	d['O'] = 'I';
	d['P'] = 'O';
	d['['] = 'P';
	d[']'] = '[';
	d['\\'] = ']';
	d['A'] = '\\';
	d['S'] = 'A';
	d['D'] = 'S';
	d['F'] = 'D';
	d['G'] = 'F';
	d['H'] = 'G';
	d['J'] = 'H';
	d['K'] = 'J';
	d['L'] = 'K';
	d[';'] = 'L';
	d['\''] = ';';
	d['Z'] = '\'';
	d['X'] = 'Z';
	d['C'] = 'X';
	d['V'] = 'C';
	d['B'] = 'V';
	d['N'] = 'B';
	d['M'] = 'N';
	d[','] = 'M';
	d['.'] = ',';
	d['/'] = '.';
	d['1'] = '`';
	d['2'] = '1';
	d['3'] = '2';
	d['4'] = '3';
	d['5'] = '4';
	d['6'] = '5';
	d['7'] = '6';
	d['8'] = '7';
	d['9'] = '8';
	d['0'] = '9';
	d['-'] = '0';
	d['='] = '-';
	d[' '] = ' ';
	d['\n'] = '\n';
	d['\t'] = '\t';
	
	while ((ch = getchar()) != EOF) {
		putchar(d[ch]);

	}

	return 0;
}