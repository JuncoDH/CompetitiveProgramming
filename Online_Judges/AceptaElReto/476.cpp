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

typedef vector<int> vi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int v1[100], v2[100], v3[100];

int comprueba(int i, int j) {
	if (v2[i] == 'N' || v2[j] == 'N') {
		return 0;
	}
	if (v2[i] == '>' && v2[j] == '>') {
		if (v1[j] > v3[i] && v1[i] > v3[j]) {
			return 1;
		}
		return 0;
	}
	if (v2[i] == '>' && v2[j] == '=') {
		if (v1[j] > v3[i] && v1[i] == v3[j]) {
			return 1;
		}
		return 0;
	}
	if (v2[i] == '>' && v2[j] == '<') {
		if (v1[j] > v3[i] && v1[i] < v3[j]) {
			return 1;
		}
		return 0;
	}
	if (v2[i] == '=' && v2[j] == '>') {
		if (v1[j] == v3[i] && v1[i] > v3[j]) {
			return 1;
		}
		return 0;
	}
	if (v2[i] == '=' && v2[j] == '=') {
		if (v1[j] == v3[i] && v1[i] == v3[j]) {
			return 1;
		}
		return 0;
	}
	if (v2[i] == '=' && v2[j] == '<') {
		if (v1[j] == v3[i] && v1[i] < v3[j]) {
			return 1;
		}
		return 0;
	}
	if (v2[i] == '<' && v2[j] == '<') {
		if (v1[j] < v3[i] && v1[i] < v3[j]) {
			return 1;
		}
		return 0;
	}
	if (v2[i] == '<' && v2[j] == '=') {
		if (v1[j] < v3[i] && v1[i] == v3[j]) {
			return 1;
		}
		return 0;
	}
	if (v2[i] == '<' && v2[j] == '>') {
		if (v1[j] < v3[i] && v1[i] > v3[j]) {
			return 1;
		}
		return 0;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, i, j, flag; //RESIZE
	//v1 es n, v2 el <=> y v3 el num a comparar
	string s;
	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		flag = 0;
		for (i = 0; i < n; i++) {
			cin >> v1[i];
		}
		for (i = 0; i < n; i++) {
			cin >> s;
			v2[i] = s[0];
			v3[i] = stoi(s.substr(1, 1));
		}

		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {

				if (comprueba(i, j)) {
					v2[i] = 'N';
					v2[j] = 'N';
					cout << i + 1 << " " << j + 1 << endl;
					flag = 1;
				}
			}
		}
		if (!flag) {
			cout << "NO HAY\n";
		}
		cout << "---\n";
	}
	return 0;
}

