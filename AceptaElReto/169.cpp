#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int main() {
	ios_base::sync_with_stdio(false);
	int casos, z, ctotal, cgem, i, temp;
	string s, recuerdo;

	cin >> casos;
	for (z = 0; z < casos; ++z) {
		ctotal = 0;
		cgem = 0;
		temp = 1;
		recuerdo = "";
		while (1) {
			cin >> s;

			if (s == "====") {
				cout << ctotal << " " << cgem << "\n";
				break;
			}
			for (i = 0; i < s.length(); ++i) {
				if (s[i] >= 'a' && s[i] <= 'z') {
					s[i] = s[i] - 'a' + 'A';
				}
			}
			ctotal++;

			if (recuerdo == s) {
				cgem += temp;
				cgem++;
				temp = 0;
			} else {
				temp = 1; //contar +1 gemelo
			}

			recuerdo = s;

			cin >> s; //el nombre
		}
	}

	return 0;
}
