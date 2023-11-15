#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>

using namespace std;

#define show(x) cout<<":"<<x<<endl

int main() {
	int i, cont, carry, temp;
	string s1, s2;
	while (1) {
		cin >> s1 >> s2;
		if (s1 == "0" && s2 == "0") {
			return 0;
		}
		if (s1.length() > s2.length()) {
			for (i = s2.length(); i < s1.length(); i++) {
				s2 = "0" + s2;
			}
		}
		if (s1.length() < s2.length()) {
			for (i = s1.length(); i < s2.length(); i++) {
				s1 = "0" + s1;
			}
		}
		carry = 0;
		cont = 0;
		for (i = s1.length(); i >= 0; i--) {
			temp = s1[i] + s2[i] + carry - '0' - '0';
			if (temp >= 10) {
				cont++;
				carry = 1;
			} else {
				carry = 0;
			}
		}
		cout << cont << endl;

	}

	return 0;
}
