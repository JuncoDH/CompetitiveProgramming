#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define MAX 1005
#define show(x) cout<<":"<<x<<endl

int main() {
	int i, flag;
	string s;
	map<char, char> m;
	m['0'] = '1';
	m['1'] = '2';
	m['2'] = '3';
	m['3'] = '4';
	m['4'] = '5';
	m['5'] = '6';
	m['6'] = '7';
	m['7'] = '8';
	m['8'] = '9';
	m['9'] = 'A';
	m['A'] = 'B';
	m['B'] = 'C';
	m['C'] = 'D';
	m['D'] = 'E';
	m['E'] = 'F';
	m['F'] = '0';

	while (1) {
		cin >> s;
		if (s == "FIN") {
			return 0;
		}
		flag = 0;
		for (i = s.length() - 1; s[i] != 0; i--) {
			s[i] = m.find(s[i])->second;
			if (s[i] == '0' && i==0) {
				flag = 1;
			}
			if (s[i] == '0') {
				continue;
			}
			break;

		}
		if (flag) {
			cout << "1";
		}
		cout << s << endl;

	}

	return 0;
}
