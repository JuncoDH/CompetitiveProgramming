#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define show(x) cout<<":"<<x<<endl

#define MAX 1005

int main() {
	int n, i, j;
	string s1, s2;
	char c;
	while (1) {
		cin >> n;
		if(!n){
			return 0;
		}
		cin>>c;
		s1 = "";
		s2 = "";
		for (i = 0; i < 4; i ++) {
			for (j = 0; j < n; j++) {
				s1 += c;
			}
			for (j = 0; j < n; j++) {
				s1 += " ";
			}
		}
		for (i = 0; i < 4; i ++) {
			for (j = 0; j < n; j++) {
				s2 += " ";
			}
			for (j = 0; j < n; j++) {
				s2 += c;
			}
		}
		cout << "|";
		for (i = 0; i < 8 * n; i++) {
			cout << "-";
		}
		cout << "|\n";
		for (i = 0; i < 4; i ++) {
			for (j = 0; j < n; j++) {
				cout << "|" << s2 << "|\n";
			}
			for (j = 0; j < n; j++) {
				cout << "|" << s1 << "|\n";
			}
		}
		cout << "|";
		for (i = 0; i < 8 * n; i++) {
			cout << "-";
		}
		cout << "|\n";

	}
	return 0;
}
