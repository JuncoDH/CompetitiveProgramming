#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, z, inv, prem, i, flag;
	string s;
	while (cin >> n) {
		if(!n){
			return 0;
		}
		vector<pair<int, int>> v;
		for (z = 0; z < n; z++) {
			cin >> inv >> prem;
			v.push_back(make_pair(inv, prem));
		}
		sort(v.begin(), v.end());
		flag = 0;
		for (i = n - 1; i > 0; i--) {
			//cout<<v[i].first <<" "<< v[i - 1].first <<" "<< v[i].second <<" "<< v[i - 1].second<<endl;
			if (v[i].first > v[i - 1].first && v[i].second <= v[i - 1].second) {
				flag = 1;
				break;
			}
		}
		cout << (flag ? "NO\n" : "SI\n");

	}
	return 0;
}

