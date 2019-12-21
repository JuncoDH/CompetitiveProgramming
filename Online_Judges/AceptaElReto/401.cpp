#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctype.h>

using namespace std;

int main() {
	int i, longitud, flag, caso, z;
	string s1, s2;

	cin >> caso;
	for (z = 0; z < caso; z++) {
		cin >> s1 >> s2;
		flag = 0;
		longitud = s1.length();

		for (i = 0; i < longitud; i++) {
			s1[i] = tolower(s1[i]);
			if (s1[i] == 'v') {
				s1[i] = 'b';
			}
		}
		for (i = 0; i < s2.length(); i++) {
			s2[i] = tolower(s2[i]);
			if (s2[i] == 'v') {
				s2[i] = 'b';
			}
		}
		if(s1==s2){
			cout << "NO\n";
			continue;
		}
		s1 = s1 + s1;
		//cout<<s1<<" "<<s2<<endl;
		for (i = 1; i < longitud; i++) {
			if (s1.substr(i, longitud) == s2) {
				flag = 1;
				break;
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
