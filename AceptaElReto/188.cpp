#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

typedef vector<int> vi;

#define show(x) cout<<":"<<x<<endl

#define MAX 1005

int main() {
	int i, j, flag;
	string s, ult;
	while (getline(cin, s)) {
		flag = 1;
		for (i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				if ((tolower(s[i - 2]) != tolower(s[i + 1]))
						|| tolower(s[i - 1]) != tolower(s[i + 2])) {
					flag = 0;
					break;
				}
			}
		}
		if (flag) {
			cout << "SI\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
